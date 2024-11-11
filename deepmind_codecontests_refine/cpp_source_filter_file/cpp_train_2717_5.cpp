#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long Negative[500001], Positive[500001], n, X, N, M;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> X, (X < 0) ? Negative[N++] = X : Positive[M++] = X;
  sort(Positive, Positive + M);
  sort(Negative, Negative + N);
  if (M == 0) {
    if (N == 1) return cout << Negative[0], 0;
    long long val = Negative[M - 1] - Negative[0];
    for (int i = 1; i < M - 1; i++) val -= Negative[i];
    return cout << val, 0;
  } else {
    if (N > 0) {
      for (int i = 0; i < M - 1; i++) {
        Negative[0] -= Positive[i];
        Positive[i] = 0;
      }
      long long val = Positive[M - 1];
      for (int i = 0; i < N; i++) val -= Negative[i];
      return cout << val, 0;
    } else {
      if (M == 1)
        cout << Positive[0];
      else if (M == 2)
        cout << Positive[1] - Positive[0];
      else {
        long long val = Positive[0] - Positive[1];
        for (int i = 2; i < M - 1; i++) val -= Positive[i];
        cout << Positive[M - 1] - val << endl;
      }
    }
  }
  return 0;
}
