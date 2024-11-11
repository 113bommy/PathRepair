#include <bits/stdc++.h>
using namespace std;
int A[2000001];
int main() {
  int N, c = 0;
  cin >> N;
  for (int i = 0; i < N; i++) A[i] = i + 1;
  for (int k = 2; k <= 4; k++) {
    int d = (N - 1) % k + 1;
    int N_ = N;
    for (int p = N - d; p >= 0; p -= k) {
      A[N_ + c] = A[c + p];
      N_ = p;
    }
    c++;
  }
  for (int i = 0; i < N; i++) printf("%d ", A[i + c]);
}
