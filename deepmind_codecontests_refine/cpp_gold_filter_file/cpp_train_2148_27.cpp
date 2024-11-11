#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 123;
const int mod = 1e9 + 7;
const int inf = 1e9 + 1;
const long long infl = 3e18 + 1;
const double pi = acos(-1.0);
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int n, a[N], ans = inf, last[N], res;
int main() {
  boost();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    last[a[i]] = i;
  }
  for (int i = 0; i <= 200001; i++) {
    if (last[i] > 0) {
      if (last[i] < ans) {
        ans = min(ans, last[i]);
        res = i;
      }
    }
  }
  cout << res;
  return 0;
}
