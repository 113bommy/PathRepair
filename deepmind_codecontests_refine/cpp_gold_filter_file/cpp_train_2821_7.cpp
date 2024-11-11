#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 3;
int n, m, x[2 + (1)][MAXN], y[2 + (1)][MAXN], a[MAXN];
vector<int> v[2 + (1)][4 + (1)];
bitset<MAXN> mark[2][MAXN];
void go(int q) {
  iota(a, a + m, 0);
  sort(a, a + m, [q](int w, int e) { return x[q][w] < x[q][e]; });
  for (int t = 0; t < m; t++)
    for (int i = 0; i < m; i++) {
      if (x[q][a[i]] > i) {
        bool shd = true;
        for (int j = x[q][a[i]] - 1; j >= i; j--)
          if (mark[q][j][y[q][a[i]]]) shd = false;
        if (!shd) continue;
        while (x[q][a[i]] > i) {
          v[q][0].push_back(x[q][a[i]]);
          v[q][1].push_back(y[q][a[i]]);
          mark[q][x[q][a[i]]][y[q][a[i]]] = false;
          v[q][2].push_back(--x[q][a[i]]);
          v[q][3].push_back(v[q][1].back());
          mark[q][x[q][a[i]]][y[q][a[i]]] = true;
        }
        break;
      }
      if (x[q][a[i]] < i) {
        bool shd = true;
        for (int j = x[q][a[i]] + 1; j <= i; j++)
          if (mark[q][j][y[q][a[i]]]) shd = false;
        if (!shd) continue;
        while (x[q][a[i]] < i) {
          v[q][0].push_back(x[q][a[i]]);
          v[q][1].push_back(y[q][a[i]]);
          mark[q][x[q][a[i]]][y[q][a[i]]] = false;
          v[q][2].push_back(++x[q][a[i]]);
          v[q][3].push_back(v[q][1].back());
          mark[q][x[q][a[i]]][y[q][a[i]]] = true;
        }
        break;
      }
    }
  for (int i = 0; i < m; i++) {
    while (y[q][a[i]] > a[i]) {
      v[q][0].push_back(x[q][a[i]]);
      v[q][1].push_back(y[q][a[i]]);
      v[q][2].push_back(x[q][a[i]]);
      v[q][3].push_back(--y[q][a[i]]);
    }
    while (y[q][a[i]] < a[i]) {
      v[q][0].push_back(x[q][a[i]]);
      v[q][1].push_back(y[q][a[i]]);
      v[q][2].push_back(x[q][a[i]]);
      v[q][3].push_back(++y[q][a[i]]);
    }
  }
  for (int i = 0; i < m; i++) {
    while (x[q][a[i]] > a[i]) {
      v[q][0].push_back(x[q][a[i]]);
      v[q][1].push_back(y[q][a[i]]);
      v[q][2].push_back(--x[q][a[i]]);
      v[q][3].push_back(y[q][a[i]]);
    }
    while (x[q][a[i]] < a[i]) {
      v[q][0].push_back(x[q][a[i]]);
      v[q][1].push_back(y[q][a[i]]);
      v[q][2].push_back(++x[q][a[i]]);
      v[q][3].push_back(y[q][a[i]]);
    }
  }
  if (q)
    for (int i = 0; i < 4; i++) reverse(v[q][i].begin(), v[q][i].end());
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x[0][i] >> y[0][i];
    mark[0][--x[0][i]][--y[0][i]] = true;
  }
  for (int i = 0; i < m; i++) {
    cin >> x[1][i] >> y[1][i];
    mark[1][--x[1][i]][--y[1][i]] = true;
  }
  go(0), go(1);
  cout << v[0][0].size() + v[1][0].size() << '\n';
  for (int q = 0; q < 2; q++)
    for (int i = 0; i < v[q][0].size(); i++)
      if (q == 0)
        cout << v[q][0][i] + 1 << ' ' << v[q][1][i] + 1 << ' ' << v[q][2][i] + 1
             << ' ' << v[q][3][i] + 1 << '\n';
      else
        cout << v[q][2][i] + 1 << ' ' << v[q][3][i] + 1 << ' ' << v[q][0][i] + 1
             << ' ' << v[q][1][i] + 1 << '\n';
  return 0;
}
