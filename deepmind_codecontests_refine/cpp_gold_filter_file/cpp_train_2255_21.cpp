#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, q, i, j, k, a, b, c, r, id, x;
  cin >> n >> q;
  vector<long long> g(n + 1), s(n + 1), f(q), ans(q);
  s[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> g[i];
    s[i] = s[i - 1] + g[i];
  }
  for (i = 0; i < q; i++) cin >> f[i];
  r = g[1];
  id = 1;
  for (i = 0; i < q; i++) {
    if (f[i] < r) {
      r -= f[i];
      ans[i] = n + 1 - id;
    } else {
      if (id == n) {
        ans[i] = n;
        id = 1;
        r = g[1];
      } else {
        x = f[i] - r;
        if (x == 0) {
          ans[i] = n - id;
          id++;
          r = g[id];
        } else {
          a = id;
          b = n;
          while (a < b) {
            c = (a + b + 1) / 2;
            if (s[c] - s[id] <= x)
              a = c;
            else
              b = c - 1;
          }
          if (a == n) {
            ans[i] = n;
            id = 1;
            r = g[1];
          } else {
            ans[i] = n - a;
            r = g[a + 1] - (x - (s[a] - s[id]));
            id = a + 1;
          }
        }
      }
    }
  }
  for (i = 0; i < q; i++) cout << ans[i] << "\n";
  return 0;
}
