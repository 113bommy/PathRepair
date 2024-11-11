#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 301;
int cl[maxn][maxn], cr[maxn][maxn], cd[maxn][maxn], cu[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, t, tp, tu, td;
  cin >> n >> m >> t >> tp >> tu >> td;
  vector<vector<int>> gr(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> gr[i][j];
    }
  }
  auto calc = [&](int i1, int j1, int i2, int j2) {
    if (gr[i1][j1] == gr[i2][j2]) return tp;
    if (gr[i1][j1] < gr[i2][j2]) return tu;
    return td;
  };
  for (int i = 1; i <= n; i++) {
    cl[i][1] = 0;
    cr[i][1] = 0;
    for (int j = 2; j <= m; j++) {
      cl[i][j] = cl[i][j - 1] + calc(i, j, i, j - 1);
      cr[i][j] = cr[i][j - 1] + calc(i, j - 1, i, j);
    }
  }
  for (int j = 1; j <= m; j++) {
    cu[1][j] = 0;
    cd[1][j] = 0;
    for (int i = 2; i <= n; i++) {
      cu[i][j] = cu[i - 1][j] + calc(i, j, i - 1, j);
      cd[i][j] = cd[i - 1][j] + calc(i - 1, j, i, j);
    }
  }
  int ans = -1, ai1 = 1, aj1 = 1, ai2 = n, aj2 = n;
  for (int i = 1; i <= n; i++) {
    for (int i2 = i + 2; i2 <= n; i2++) {
      auto getTot = [&](int j) {
        return cr[i][j] + cl[i2][j] + cd[i2][j] - cd[i][j];
      };
      auto getVal = [&](int j) { return cu[i2][j] - cu[i][j]; };
      set<pair<int, int>> sp;
      int offset = 0;
      for (int j = 3; j <= m; j++) {
        sp.insert({getTot(j), j});
      }
      for (int j = 1; j < m - 1; j++) {
        int val = getVal(j) + offset;
        pair<int, int> p = {t - val, 0};
        auto it = sp.lower_bound(p);
        if (it != sp.end()) {
          int anst = val + it->first;
          if (ans == -1 || abs(anst - t) < abs(ans - t)) {
            ans = anst;
            ai1 = i, aj1 = j, ai2 = i2, aj2 = it->second;
          }
        }
        if (it != sp.begin()) {
          it--;
          int anst = val + it->first;
          if (ans == -1 || abs(anst - t) < abs(ans - t)) {
            ans = anst;
            ai1 = i, aj1 = j, ai2 = i2, aj2 = it->second;
          }
        }
        sp.erase({getTot(j + 2), j});
        offset -= calc(i, j, i, j + 1) + calc(i2, j + 1, i2, j);
      }
    }
  }
  cout << ai1 << ' ' << aj1 << ' ' << ai2 << ' ' << aj2;
  return 0;
}
