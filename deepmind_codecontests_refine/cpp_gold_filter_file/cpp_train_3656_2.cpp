#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int inf = numeric_limits<int>::max() / 2;
const long double eps = 1e-9;
const long double pi = acos(-1);
inline void solve(), read();
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  solve();
  return 0;
}
const int MAXD = 501;
const int MAXS = 5001;
int d, s;
bool used[MAXD][MAXS];
pair<pair<int, int>, int> par[MAXD][MAXS];
inline void solve() {
  if (d % 3 == 0 && s % 3 != 0) {
    cout << -1 << "\n";
    return;
  }
  queue<pair<pair<int, int>, int>> q;
  q.push({{0, 0}, {0}});
  used[0][0] = 1;
  while (!q.empty()) {
    int i = q.front().first.first, r = q.front().first.second,
        z = q.front().second;
    q.pop();
    for (int p = 0; p < 10; p++) {
      int j = i + 1, l = (10 * r + p) % d, y = z + p;
      if (y > s) {
        continue;
      }
      if (used[l][y]) {
        continue;
      }
      used[l][y] = 1;
      par[l][y] = {{r, z}, p};
      q.push({{j, l}, y});
    }
  }
  int x = 0, y = s;
  if (!used[x][y]) {
    cout << -1 << "\n";
    return;
  }
  string ans;
  while (y != 0) {
    ans += to_string(par[x][y].second);
    tie(x, y) = (par[x][y].first);
  }
  reverse((ans).begin(), (ans).end());
  cout << ans << "\n";
}
inline void read() { cin >> d >> s; }
