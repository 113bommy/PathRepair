#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int sgn(long long x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  long long v[n];
  long long msk[n];
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> msk[i];
    sum += v[i];
  }
  if (sum < 0) {
    for (int i = 0; i < n; i++) v[i] *= -1;
    sum *= -1;
  }
  long long a[65];
  fill_n(a, 65, 0ll);
  for (int i = 0; i < n; i++) a[__builtin_ctz(msk[i])] += v[i];
  long long s = 0;
  for (int c = 62; c >= 0; c--) {
    if (a[c] > 0) {
      s += (1ll << c);
      for (int i = 0; i < n; i++) {
        if ((msk[i] & (1ll << c)) > 0) {
          a[__builtin_ctz(msk[i])] -= 2 * v[i];
          v[i] = -v[i];
        }
      }
    }
  }
  cout << s << "\n";
}
