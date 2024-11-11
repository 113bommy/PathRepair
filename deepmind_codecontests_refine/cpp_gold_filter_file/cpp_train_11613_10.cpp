#include <bits/stdc++.h>
using namespace std;
const int N = 303;
const int P = N * N;
const int OO = P * N * 2;
int val[N][N];
int new_val[N][N];
int last[N][N];
vector<pair<int, int>> pos[P];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      cin >> x;
      pos[x].emplace_back(i, j);
      val[i][j] = i + j;
    }
  }
  int ans = OO;
  for (int kind = 1; kind <= p; ++kind) {
    for (auto& ps : pos[kind]) {
      int value = OO;
      for (int i = 0; i < m; ++i) {
        if (last[ps.first][i] < kind - 1) continue;
        value = min(value, val[ps.first][i] + abs(ps.second - i));
      }
      new_val[ps.first][ps.second] = value;
      if (kind == p) {
        ans = min(ans, value);
      }
    }
    for (auto& ps : pos[kind]) {
      int value = new_val[ps.first][ps.second];
      for (int i = 0; i < n; ++i) {
        if (last[i][ps.second] == kind) {
          val[i][ps.second] = min(val[i][ps.second], value + abs(i - ps.first));
        } else {
          val[i][ps.second] = value + abs(i - ps.first);
        }
        last[i][ps.second] = kind;
      }
    }
  }
  cout << ans;
}
