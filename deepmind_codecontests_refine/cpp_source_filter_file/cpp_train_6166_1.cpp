#include <bits/stdc++.h>
using namespace std;
char buf[1 << 15], *fs, *ft;
inline char getc() {
  return (fs == ft &&
          (ft = (fs = buf) + fread(buf, 1, 1 << 15, stdin), fs == ft))
             ? 0
             : *fs++;
}
inline int read() {
  register int x = 0, f = 1;
  register char ch = getc();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getc();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getc();
  }
  return x * f;
}
const int MAXN = 110;
int T, ans, cnt;
int n, m;
string a[MAXN], b;
map<string, int> H;
int vis[MAXN];
int q[MAXN], mark[MAXN];
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    b = "";
    int flag = 0;
    for (int j = m - 1; j >= 0; --j) b += a[i][j];
    for (int j = 0; j < m; ++j)
      if (b[j] != a[i][j]) flag = 1;
    if (!flag) mark[i] = 1, ++cnt;
    if (H.find(b) != H.end()) {
      ++ans;
      vis[H[b]] = i;
      vis[i] = H[b];
    }
    H[a[i]] = i;
  }
  if (!ans) {
    if (!cnt) {
      cout << 0 << endl;
      return 0;
    } else {
      cout << m << endl;
      for (int i = 1; i <= n; ++i)
        if (mark[i]) {
          cout << a[i];
          break;
        }
    }
  } else {
    cout << ans * 2 * m + (cnt ? m : 0) << endl;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) {
        q[++T] = vis[i];
        vis[vis[i]] = 0;
        cout << a[i];
      }
    }
    for (int i = 1; i <= n; ++i)
      if (mark[i]) {
        cout << a[i];
        break;
      }
    for (int i = 1; i <= T; ++i) cout << a[q[i]];
  }
  return 0;
}
