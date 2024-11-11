#include <bits/stdc++.h>
using namespace std;
int N;
long long A[105], Ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  long long T = 0;
  for (int i = 0; i <= N - 1; i++) {
    cin >> A[i];
    T += A[i];
  }
  sort(A, A + N);
  Ans = T;
  long long M = A[0];
  for (int i = 1; i <= N - 1; i++) {
    long long X = A[i];
    for (long long j = 1; j * j <= X; j++) {
      if (X % j == 0) {
        Ans = min(Ans, T - M + M * j - X + X / j);
        Ans = min(Ans, T - M + M * (X / j) - X + j);
      }
    }
  }
  cout << Ans << '\n';
  return 0;
}
