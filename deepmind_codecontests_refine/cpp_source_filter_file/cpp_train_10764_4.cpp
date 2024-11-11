#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int inf = 2e9 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-15;
int n, m, k;
pair<long long, long long> p[1111];
long long x[1111], y[1111], r[1111];
bitset<1001> po[1001];
int to[1001][1001];
bool incp(int a, int b) {
  return (p[a].first - x[b]) * (p[a].first - x[b]) +
             (p[a].second - y[b]) * (p[a].second - y[b]) <
         r[b] * r[b];
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].first >> p[i].second;
  }
  for (int i = 0; i < m; ++i) {
    cin >> r[i] >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      po[i][j] = incp(i, j);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      to[i][j] = to[j][i] = (po[i] & po[j]).count();
    }
  }
  int a, b;
  for (int i = 1; i <= k; ++i) {
    cin >> a >> b;
    --a, --b;
    cout << po[a].count() + po[b].count() - to[a][b] << "\n";
  }
}
