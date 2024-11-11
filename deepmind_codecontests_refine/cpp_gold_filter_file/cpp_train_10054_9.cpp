#include <bits/stdc++.h>
using namespace std;
long long a[100005][3], s[100005], f[100005], g[100005], h[100005], n, l, r;
int main() {
  cin >> n;
  for (int j = 0; j <= 2; j++)
    for (int i = 1; i <= n; i++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i][0] + a[i][1] + a[i][2];
  for (int i = 1; i <= n; i++) f[i] = g[i] = h[i] = -1e17;
  f[1] = a[1][0];
  g[1] = s[1];
  l = max(0LL, f[1] - s[1]);
  h[1] = a[1][0] + a[1][1];
  r = g[1] - s[1];
  for (int i = 2; i <= n; i++) {
    f[i] = max(f[i - 1] + a[i][0], s[i] + r);
    g[i] = max(g[i - 1] + a[i][2], s[i] + l);
    h[i] = max(h[i - 1], max(f[i - 1] + a[i][0], g[i - 1] + a[i][2])) + a[i][1];
    f[i] = max(f[i], h[i - 1] + a[i][1] + a[i][0]);
    g[i] = max(g[i], h[i - 1] + a[i][1] + a[i][2]);
    l = max(l, f[i] - s[i]);
    r = max(r, g[i] - s[i]);
  }
  cout << g[n];
}
