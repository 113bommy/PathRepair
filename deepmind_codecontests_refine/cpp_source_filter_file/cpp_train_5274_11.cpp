#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
long long e[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, u, l, i;
  cin >> n >> u;
  for (i = 0; i < n; i++) cin >> e[i];
  long double ans = -1, val;
  for (i = 0; i < n - 2; i++) {
    l = upper_bound(e + i, e + n, e[i] + u) - e;
    if (l > i + 1 && e[l - 1] - e[i] <= u) {
      val = ((long double)(e[l - 1] - e[i + 1])) / (e[l - 1] - e[i]);
      if (val > ans) ans = val;
    }
  }
  cout << setprecision(20) << fixed;
  cout << ans << '\n';
  return 0;
}
