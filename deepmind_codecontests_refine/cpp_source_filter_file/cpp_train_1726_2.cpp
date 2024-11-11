#include <bits/stdc++.h>
using namespace std;
void sortirovka(int size, int arr[]) {
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}
void copyM(int A[], int C[], int n) {
  for (int i = 0; i < n; i++) C[i] = A[i];
}
bool sravnenine(int C[], int B[], int n) {
  int k = 0;
  bool t = false;
  for (int i = 0; i < n; i++) {
    if (C[i] == B[i]) k++;
  }
  if (k == n) t = true;
  return t;
}
int main() {
  int n, L, k = 0;
  bool t = false;
  cin >> n >> L;
  int A[50], B[50], C[50];
  for (int j = 0; j < n; j++) cin >> A[j];
  for (int j = 0; j < n; j++) cin >> B[j];
  for (int x = 1; x < L; x++) {
    copyM(A, C, n);
    for (int j = 0; j < n; j++) C[j] += x;
    for (int j = 0; j < n; j++)
      if (C[j] > L - 1) {
        C[j] -= L;
        sortirovka(n, C);
      }
    if (sravnenine(C, B, n) == true) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
