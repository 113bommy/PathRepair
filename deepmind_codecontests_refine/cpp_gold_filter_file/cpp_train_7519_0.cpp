#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(0));
const long long inf = 1e18 + 7;
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<long long> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];
  long long G, R;
  cin >> G >> R;
  sort(a.begin(), a.end());
  vector<vector<long long>> dist(m + 1, vector<long long>(G + 1, inf));
  deque<pair<long long, long long>> q;
  q.emplace_back(0, 0);
  dist[0][0] = 0;
  while (q.size()) {
    pair<long long, long long> v = q.front();
    q.pop_front();
    if (v.first) {
      long long d = abs(a[v.first] - a[v.first - 1]);
      if (v.second + d < G) {
        if (dist[v.first - 1][v.second + d] > dist[v.first][v.second]) {
          dist[v.first - 1][v.second + d] = dist[v.first][v.second];
          q.emplace_front(v.first - 1, v.second + d);
        }
      } else if (v.second + d == G) {
        if (dist[v.first - 1][0] > dist[v.first][v.second] + 1) {
          dist[v.first - 1][0] = dist[v.first][v.second] + 1;
          q.emplace_back(v.first - 1, 0);
        }
      }
    }
    if (v.first + 1 != m) {
      long long d = abs(a[v.first] - a[v.first + 1]);
      if (v.second + d < G) {
        if (dist[v.first + 1][v.second + d] > dist[v.first][v.second]) {
          dist[v.first + 1][v.second + d] = dist[v.first][v.second];
          q.emplace_front(v.first + 1, v.second + d);
        }
      }
      if (v.second + d == G) {
        if (dist[v.first + 1][0] > dist[v.first][v.second] + 1) {
          dist[v.first + 1][0] = dist[v.first][v.second] + 1;
          q.emplace_back(v.first + 1, 0);
        }
      }
    }
  }
  long long ans = -1;
  for (int i = 0; i < G; ++i) {
    if (dist[m - 1][i] == inf) continue;
    long long res = (G + R) * dist[m - 1][i] + i;
    if (i == 0) res -= R;
    if (ans == -1 || (ans != -1 && ans > res)) ans = res;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(15);
  int t;
  bool IS_ONE_TEST = 1;
  if (IS_ONE_TEST)
    t = 1;
  else
    cin >> t;
  while (t-- > 0) {
    solve();
  }
}
