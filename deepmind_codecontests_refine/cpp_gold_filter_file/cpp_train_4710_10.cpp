#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false),
            cout << fixed << setprecision(9), 0);
Int fast(Int N) {
  Int ans = 0, t;
  for (t = 0; t < 32; t++)
    if (N <= (1LL << (2 + 2 * t)) - 1) break;
  const int A[3] = {3, 1, 2};
  N -= (1LL << (2 * t));
  Int a = N % 3;
  ans += (a + 1) << (2 * t);
  Int d = 1;
  N /= 3;
  for (int i = 0; i < t; i++) {
    Int b = N % 4;
    if (b != 0) {
      ans += A[(a + b) % 3] * d;
    }
    N /= 4;
    d *= 4;
  }
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    Int N;
    cin >> N;
    cout << fast(N) << '\n';
  }
  return 0;
}
