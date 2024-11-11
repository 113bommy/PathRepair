#include <bits/stdc++.h>
using namespace std;
struct que {
  int t, r, c, x;
};
que a[100000];
vector<vector<int> > ans(103, vector<int>(103, -1));
int main() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < q; ++i) {
    cin >> a[i].t;
    if (a[i].t == 3) cin >> a[i].r >> a[i].c >> a[i].x;
    if (a[i].t == 2) cin >> a[i].c;
    if (a[i].t == 1) cin >> a[i].r;
  }
  for (int i = q - 1; i >= 0; --i) {
    if (a[i].t == 3) ans[a[i].r][a[i].c] = a[i].x;
    if (a[i].t == 2) {
      for (int j = n; j >= 1; --j) {
        ans[j + 1][a[i].c] = ans[j][a[i].c];
      }
      ans[1][a[i].c] = ans[n + 1][a[i].c];
    }
    if (a[i].t == 1) {
      for (int j = m; j >= 1; --j) {
        ans[a[i].r][j + 1] = ans[a[i].r][j];
      }
      ans[a[i].r][1] = ans[a[i].r][m + 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cout << ans[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
