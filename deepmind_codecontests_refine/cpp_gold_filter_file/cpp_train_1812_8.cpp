#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
int const N = 100 * 1000 + 16;
int const M = 1000 * 1000 * 1000 + 7;
int n, m, k;
char w[512][512];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
inline bool valid(int x, int y) {
  return 1 <= x && x <= n && 1 <= y && y <= m && w[x][y] == '*';
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> (w[i] + 1);
  }
  int r = 200;
  vector<tuple<int, int, int>> p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int rad = 1; rad <= r; ++rad) {
        bool can = true;
        for (int d = 0; d < 5; ++d)
          can &= valid(i + dx[d] * rad, j + dy[d] * rad);
        if (can) p.emplace_back(rad, i, j);
      }
    }
  }
  sort(p.begin(), p.end());
  if (p.size() < k)
    cout << -1;
  else {
    k--;
    int rad = get<0>(p[k]);
    for (int d = 0; d < 5; ++d) {
      cout << get<1>(p[k]) + dx[d] * rad << " " << get<2>(p[k]) + dy[d] * rad
           << "\n";
    }
  }
}
