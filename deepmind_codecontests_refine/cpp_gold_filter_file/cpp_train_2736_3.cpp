#include <bits/stdc++.h>
using namespace std;
const int maxn = 128;
int val[maxn][maxn];
char str[maxn];
struct mpp {
  int a, b, c, d, e, f;
};
vector<mpp> ans;
inline void out(int a, int b, int c, int d, int e, int f) {
  ans.push_back(mpp{a, b, c, d, e, f});
}
inline void solve() {
  ans.clear();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> str;
    for (int j = 1; j <= m; j++) val[i][j] = str[j - 1] - '0';
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      if (val[i][j]) {
        out(i, j, i, j + 1, i + 1, j);
        out(i, j, i + 1, j, i + 1, j + 1);
        out(i, j, i, j + 1, i + 1, j + 1);
        val[i][j] = 0;
      }
  for (int i = 2; i <= n; i++)
    for (int j = 2; j <= m; j++)
      if (val[i][j]) {
        out(i, j - 1, i, j, i - 1, j);
        out(i, j - 1, i, j, i - 1, j - 1);
        out(i - 1, j - 1, i - 1, j, i, j);
        val[i][j] = 0;
      }
  if (val[1][1]) {
    out(1, 1, 2, 1, 2, 2);
    out(1, 1, 1, 2, 2, 2);
    out(1, 1, 1, 2, 2, 1);
  }
  if (val[1][m]) {
    out(1, m, 2, m - 1, 2, m);
    out(1, m - 1, 1, m, 2, m - 1);
    out(1, m - 1, 1, m, 2, m);
    val[1][m] = 0;
  }
  if (val[n][1]) {
    out(n - 1, 1, n, 1, n, 2);
    out(n, 1, n, 2, n - 1, 2);
    out(n - 1, 1, n - 1, 2, n, 1);
    val[n][1] = 0;
  }
  if (val[n][m]) {
    out(n, m - 1, n, m, n - 1, m);
    out(n, m - 1, n, m, n - 1, m - 1);
    out(n - 1, m - 1, n - 1, m, n, m);
    val[n][1] = 0;
  }
  cout << ans.size() << '\n';
  for (auto x : ans)
    cout << x.a << " " << x.b << " " << x.c << " " << x.d << " " << x.e << " "
         << x.f << '\n';
}
int t;
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) solve();
  return 0;
}
