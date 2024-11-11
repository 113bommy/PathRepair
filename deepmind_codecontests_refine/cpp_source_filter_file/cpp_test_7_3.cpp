#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  string a, b;
  cin >> a >> b;
  vector<int> fail(m + 1);
  fail[0] = fail[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = fail[i];
    while (j && b[i] != b[j]) j = fail[j];
    fail[i + 1] = b[i] == b[j] ? j + 1 : 0;
  }
  vector<vector<int>> quick_f(m + 1, vector<int>(2));
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < 2; j++) {
      int k = fail[i];
      while (k && '0' + j != b[k]) k = fail[k];
      quick_f[i][j] = '0' + j == b[k] ? k + 1 : k;
    }
  }
  auto update_min = [](int &x, int y) {
    if (x == -1 || y < x) x = y;
  };
  vector<vector<int>> f(n - m + 2, vector<int>(m, -1));
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> g(n - m + 2, vector<int>(m, -1));
    for (int j = 0; j <= n - m + 1; j++) {
      for (int k = 0; k < m; k++) {
        if (f[j][k] == -1) continue;
        int cost;
        cost = a[i] == b[k] ? 0 : 1;
        if (k + 1 == m) {
          update_min(g[j + 1][fail[m]], f[j][k] + cost);
        } else {
          update_min(g[j][k + 1], f[j][k] + cost);
        }
        cost = a[i] == b[k] ? 1 : 0;
        int idx = b[k] - '0';
        int nk = quick_f[nk][1 - idx];
        update_min(g[j][nk], f[j][k] + cost);
      }
    }
    f = g;
  }
  for (int i = 0; i <= n - m + 1; i++) {
    int v = -1;
    for (int j = 0; j < m; j++)
      if (f[i][j] != -1) update_min(v, f[i][j]);
    cout << v << " \n"[i == n - m + 1];
  }
}
