#include <bits/stdc++.h>
using namespace std;
const int maxm = 90005;
int t, n, m, s[305][305];
struct NODE {
  int a, i, p;
  NODE() { a = i = p = 0; }
  bool operator<(const NODE &x) const {
    if (a == x.a)
      return i > x.i;
    else
      return a < x.a;
  }
} g[maxm];
bool cmp(const NODE &a, const NODE &b) { return a.i < b.i; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n * m; i++) {
      cin >> g[i].a;
      g[i].i = i;
    }
    sort(g + 1, g + n * m + 1);
    for (int i = 1; i <= n * m; i++) g[i].p = i;
    int L = 0, R = 0, pre = -1;
    g[n * m + 1].a = -1;
    for (int i = 1; i <= n * m + 1; i++) {
      if (g[i].a != pre) {
        if (pre != -1 && L != R) {
          int r = (R - 1) / m + 1;
          int c = R - (r - 1) * m;
          int lr = (L - 1) / m + 1;
          int lc = L - (lr - 1) * m;
          if (lr != r) {
            for (int j = L; j <= R; j++) g[j].p = -1;
            for (int j = 1, k = (r - 1) * m + 1; j <= c; j++, k++)
              g[L + j - 1].p = k;
            for (int j = m, k = L; j >= lc; j--, k++) g[R + j - m].p = k;
          }
        }
        L = R = i;
        pre = g[i].a;
      } else
        R = i;
    }
    sort(g + 1, g + n * m + 1, cmp);
    int ans = 0;
    for (int i = 1; i <= n * m; i++) {
      if (g[i].p == -1) continue;
      int r = (g[i].p - 1) / m + 1;
      int c = g[i].p - (r - 1) * m;
      for (int j = 1; j < c; j++)
        if (s[r][j] == 1) ans++;
      s[r][c] = 1;
    }
    cout << ans << endl;
  }
  return 0;
}
