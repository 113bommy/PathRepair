#include <bits/stdc++.h>
using namespace std;
const long long I1 = 1e9;
const long long I2 = 1e18;
const int32_t M1 = 1e9 + 7;
const int32_t M2 = 998244353;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
const int M = 3e3 + 5;
bool cc[M][M];
long long int dis[M][M];
set<pair<pair<long long int, long long int>, long long int> > s;
vector<long long int> a[M];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (long long int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for (long long int i = 0; i < k; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    s.insert({{x, y}, z});
  }
  queue<pair<long long int, long long int> > q;
  q.push({1, 1});
  while (!q.empty()) {
    pair<long long int, long long int> cur = q.front();
    int x = cur.first, y = cur.second;
    q.pop();
    cc[cur.first][cur.second] = true;
    for (auto u : a[y]) {
      if (s.count({{x, y}, u})) continue;
      if (cc[y][u] == true) continue;
      cc[y][u] = true;
      dis[y][u] = dis[x][y] + 1;
      q.push({y, u});
    }
  }
  long long int d = I1, i = n, prev = n;
  for (long long int i = 1; i <= n; i++) {
    if (dis[i][n] != 0) minn(d, dis[i][n]);
  }
  if (d == I1) {
    cout << "-1" << endl;
    return;
  }
  cout << d << endl;
  vector<long long int> ans;
  ans.push_back(n);
  while (i != 1) {
    long long int ind = -1;
    for (long long int j = 1; j <= n; j++) {
      if (dis[j][i] == d) {
        ind = j;
        break;
      }
    }
    ans.push_back(ind);
    prev = i;
    i = ind;
    d--;
  }
  reverse(ans.begin(), ans.end());
  for (auto u : ans) cout << u << " ";
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  while (testcase--) solve();
  return 0;
}
