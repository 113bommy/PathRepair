#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
void solve() {
  int a[500010], m[1000], n, ans = LONG_MAX, t = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m[a[i]] = 1;
    t += a[i];
  }
  ans = t;
  int minvalue;
  for (int i = 1; i <= 100; i++)
    if (m[i]) {
      minvalue = i;
      break;
    }
  for (int i = minvalue + 1; i <= 100; i++) {
    if (m[i])
      for (int j = 2; j <= i; j++) {
        if (i % j == 0)
          ans = min(ans, t + minvalue * (j - 1) - (i / j) * (j - 1));
      }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
}
