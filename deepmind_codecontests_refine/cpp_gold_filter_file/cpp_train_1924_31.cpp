#include <bits/stdc++.h>
using namespace std;
int n, k;
int p[107];
double res;
double curr[107][107];
double last[107][107];
int przejscia[4][107][107][2 * 107];
vector<pair<int, int> > v[4][107][107];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  k = min(k, 1000);
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (p[i] > p[j]) curr[i][j] = 1;
    }
  }
  double s = n * (n + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int x = 1; x <= n; ++x) {
        for (int y = x; y <= n; ++y) {
          if (x <= i && i <= y && x <= j && j <= y) {
            if (x + y - i <= x + y - j) ++przejscia[0][i][j][x + y];
          } else if (x <= i && i <= y) {
            if (x + y - i <= j) ++przejscia[1][i][j][x + y];
          } else if (x <= j && j <= y) {
            if (i <= x + y - j) ++przejscia[2][i][j][x + y];
          } else {
            if (i <= j) ++przejscia[3][i][j][0];
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int c = 0; c <= 2 * n; ++c) {
        for (int q = 0; q < 4; ++q) {
          if (przejscia[q][i][j][c])
            v[q][i][j].emplace_back(c, przejscia[q][i][j][c]);
        }
      }
    }
  }
  for (int l = 1; l <= k; ++l) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        last[i][j] = curr[i][j];
        curr[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        double val = last[i][j] / s;
        for (auto it : v[0][i][j])
          curr[it.first - i][it.first - j] += it.second * val;
        for (auto it : v[1][i][j]) curr[it.first - i][j] += it.second * val;
        for (auto it : v[2][i][j]) curr[i][it.first - j] += it.second * val;
        for (auto it : v[3][i][j]) curr[i][j] += it.second * val;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        curr[j][i] = 1 - curr[i][j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      res += curr[i][j];
    }
  }
  cout << setprecision(15) << fixed << res;
}
