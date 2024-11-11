#include <bits/stdc++.h>
using namespace std;
int n, q;
long long v[100009];
long long c[100009];
long long co[100009][2];
int main() {
  cin >> n >> q;
  for (int h = 0; h < n; h++) cin >> v[h];
  for (int h = 0; h < n; h++) cin >> c[h];
  for (int h = 0; h < q; h++) {
    int a, b;
    long long x, x1, y = -LLONG_MAX, y1 = LLONG_MAX, ans = 0;
    cin >> a >> b;
    memset(co, 0, sizeof(co));
    x1 = c[0];
    x = b * v[0];
    co[c[0]][1] = 1;
    co[c[0]][0] = x;
    for (int j = 1; j < n; j++) {
      long long o = -LLONG_MAX;
      if (co[c[j]][1] != 0) o = max(o, co[c[j]][0] + a * v[j]);
      o = max(o, b * v[j]);
      if (x1 == c[j] && y1 != LLONG_MAX)
        o = max(o, y + b * v[j]);
      else if (x1 != c[j])
        o = max(o, x + b * v[j]);
      ans = max(o, ans);
      if (o < co[c[j]][0] && co[c[j]][1] == 1) continue;
      co[c[j]][1] = 1;
      co[c[j]][0] = o;
      if (x1 == c[j])
        x = o;
      else if (x <= o)
        y = x, y1 = x1, x = o, x1 = c[j];
      else if (y <= o)
        y = o, y1 = c[j];
    }
    cout << ans << endl;
  }
}
