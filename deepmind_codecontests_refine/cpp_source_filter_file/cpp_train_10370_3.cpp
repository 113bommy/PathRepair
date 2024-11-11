#include <bits/stdc++.h>
using namespace std;
const int N = 200, inf = 1000 * 1000 * 1000;
int a[N], n, k, ans = inf;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 1; j < n; j++) {
    int h = 0, o = 0;
    for (int l = 0; l <= j; l++) {
      if (a[l] >= 8) {
        h += 8;
        o += (a[l] - 8);
      } else {
        h += a[l];
        h += min(8 - a[l], o);
        o -= min(o, 8 - a[l]);
      }
    }
    if (h >= k) ans = min(j + 1, ans);
  }
  if (ans == inf)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
