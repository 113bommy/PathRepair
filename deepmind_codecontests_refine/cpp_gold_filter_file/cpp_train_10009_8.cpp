#include <bits/stdc++.h>
using namespace std;
const int maxn = 1111;
int a[maxn][maxn];
int r[maxn][maxn], c[maxn][maxn];
int tr[maxn][maxn], tc[maxn][maxn];
int ans[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
      set<int> s;
      for (int j = 1; j <= m; j++) s.insert(a[i][j]);
      vector<int> v(s.begin(), s.end());
      for (int j = 1; j <= m; j++) {
        auto iter = lower_bound(v.begin(), v.end(), a[i][j]);
        r[i][j] = iter - v.begin();
        tr[i][j] = v.end() - iter - 1;
      }
    }
    for (int i = 1; i <= m; i++) {
      set<int> s;
      for (int j = 1; j <= n; j++) s.insert(a[j][i]);
      vector<int> v(s.begin(), s.end());
      for (int j = 1; j <= n; j++) {
        auto iter = lower_bound(v.begin(), v.end(), a[j][i]);
        c[j][i] = iter - v.begin();
        tc[j][i] = v.end() - iter - 1;
      }
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        ans[i][j] = max(r[i][j], c[i][j]) + max(tr[i][j], tc[i][j]) + 1;
        cout << ans[i][j];
        if (j == m)
          cout << endl;
        else
          cout << " ";
      }
  }
  return 0;
}
