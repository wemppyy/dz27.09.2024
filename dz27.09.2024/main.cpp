#include <iostream> 
#include <ctime> 

using namespace std;

template <typename T>
void push_back(T element, T*& arr, int& size) {
    T* newArr = new T[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = element;
    delete[] arr;
    arr = newArr;
    size++;
}

template <typename T>
bool in_arr(int value, T* arr, int size) {
    bool result = false;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == value) result = true;
    }
    return result;
}

int main() {
    srand(time(0));

    int M, N;
    int C_size = 0;
    int D_size = 0;

    cout << "A[M] -> ";
    cin >> M;

    cout << endl << "B[N] -> ";
    cin >> N;

    cout << endl;

    int* A = new int[M];
    int* B = new int[N];

    for (int i = 0; i < M; i++) {
        A[i] = rand() % 20;
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        B[i] = rand() % 20;
        cout << B[i] << " ";
    }
    cout << endl;

    int* C = new int[0];
    int* D = new int[0];
    int operation;

    cout << "Menu:\n"
            "1. Task 1\n"
            "2. Task 2\n";

    cin >> operation;

    switch (operation) {
        case 1:

            /*for (int i = 0; i < M; i++) {
                bool in_b = false;
                for (int j = 0; j < N; j++) {
                    if (A[i] == B[j])
                        in_b = true;
                }
                bool in_c = false;
                for (int j = 0; j < C_size; j++) {
                    if (A[i] == C[i])
                        in_c = true;
                }
                if (!in_b && !in_c) push_back(A[i], C, C_size);
            }*/

            for (int i = 0; i < M; i++) {
                bool in_b = in_arr(A[i], B, N);
                bool in_c = in_arr(A[i], C, C_size);
                if (!in_b && !in_c) push_back(A[i], C, C_size);
            }

            for (int i = 0; i < C_size; i++) {
                cout << C[i] << " ";
            }
            break;
        case 2:
            for (int i = 0; i < M; i++) {
                bool in_b = in_arr(A[i], B, N);
                bool in_d = in_arr(A[i], D, D_size);
                if (!in_b && !in_d) push_back(A[i], D, D_size);
            }
            for (int i = 0; i < N; i++) {
                bool in_a = in_arr(B[i], A, M);
                bool in_d = in_arr(B[i], D, D_size);
                if (!in_a && !in_d) push_back(B[i], D, D_size);
            }
            for (int i = 0; i < D_size; i++) {
                cout << D[i] << " ";
            }
            break;
        default:
            cout << "Error. Wrong value!" << endl;
            break;
    }

    



    return 0;
}
