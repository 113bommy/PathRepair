#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
const int M = 100;
long long vet[N];
int A[M], B[M];
void build(int* A, int n) {
  while (1) {
    long long sum = 0;
    for (int i = 0; i < n - 1; ++i) {
      A[i] = rand() % (N / 10) + 1;
      sum += vet[A[i]];
    }
    for (int i = 0; i < 100; ++i) {
      int j = rand() % (N / 10) + 1;
      long long aux = sum + vet[j];
      if (*lower_bound(vet, vet + N, aux) == aux) {
        A[n - 1] = j;
        return;
      }
    }
  }
}
int main() {
  srand(time(0));
  for (int i = 0; i < N; ++i) vet[i] = 1LL * i * i;
  int n, m;
  cin >> n >> m;
  build(A, n);
  build(B, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << A[i] * B[j] << ' ';
    cout << endl;
  }
}
