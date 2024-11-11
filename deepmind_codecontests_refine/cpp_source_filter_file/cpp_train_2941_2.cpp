#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int n, m, t;
int a[N][N], d[N][N];
int X[] = {0, 0, 1, -1}, Y[] = {1, -1, 0, 0};
char c[N][N];
void solve() {
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int tox = i + X[k], toy = j + Y[k];
        if (tox < 0 || tox >= n || toy < 0 || toy >= n) continue;
        if (c[tox][toy] == c[i][j]) cnt++;
      }
      if (cnt) a[i][j] = 1;
    }
  }
  vector<pair<int, int> > q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j]) continue;
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int tox = i + X[k], toy = j + Y[k];
        if (tox < 0 || tox >= n || toy < 0 || toy >= n) continue;
        if (a[tox][toy]) cnt++;
      }
      if (cnt) q.emplace_back(i, j);
    }
  }
  int D = 0;
  while (!q.empty()) {
    D++;
    for (int i = 0; i < q.size(); i++) {
      int x = q[i].first, y = q[i].second;
      d[x][y] = D;
      a[x][y] = 1;
    }
    vector<pair<int, int> > new_q;
    for (int i = 0; i < q.size(); i++) {
      int x = q[i].first, y = q[i].second;
      for (int k = 0; k < 4; k++) {
        int tox = x + X[k], toy = y + Y[k];
        if (tox < 0 || tox >= n || toy < 0 || toy >= n) continue;
        if (!a[tox][toy]) {
          new_q.emplace_back(tox, toy);
        }
      }
    }
    sort(new_q.begin(), new_q.end());
    new_q.resize(unique(new_q.begin(), new_q.end()) - new_q.begin());
    q = new_q;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!a[i][j]) d[i][j] = -1;
    }
  }
  while (t--) {
    int i, j;
    long long p;
    cin >> i >> j >> p;
    i--, j--;
    if (d[i][j] >= p || d[i][j] == -1) {
      cout << c[i][j] << endl;
      continue;
    }
    int C = c[i][j] - '0';
    if ((p - d[i][j]) % 2) C ^= 1;
    cout << C << endl;
  }
}
int main() {
  int tt = 1;
  while (tt--) solve();
}
