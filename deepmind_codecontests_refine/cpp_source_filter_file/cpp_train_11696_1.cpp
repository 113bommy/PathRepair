#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T& x) {
  cin >> x;
}
template <class H, class... T>
void read(H& h, T&... t) {
  read(h);
  read(t...);
}
template <class A>
void read(A* x, int size) {
  for (int i = (0); (1) > 0 ? i < (size) : i > (size); i += (1)) read(x[i]);
}
template <class A>
void read(vector<A>& x) {
  for (auto& a : x) read(a);
}
template <class T>
void print(T& x) {
  cout << x << ' ';
}
template <class H, class... T>
void print(H h, T... t) {
  print(h);
  print(t...);
}
template <class A>
void print(A* x, int size) {
  for (int i = (0); (1) > 0 ? i < (size) : i > (size); i += (1)) print(x[i]);
  cout << '\n';
}
template <class A>
void print(vector<A>& x) {
  for (auto& a : x) print(a);
}
template <class H, class... T>
void debug(H h, T... t) {
  print(h, t...);
  cout << endl;
}
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int N = 1510, mod = 1e9 + 7;
string str[N];
pair<int, int> dp[N][N];
bool vis[N][N];
int n, m;
bool dfs(int x, int y) {
  int p = (x % n + n) % n, q = (y % m + m) % m;
  if (vis[p][q] == 1) {
    if (dp[p][q].first == x and dp[p][q].second == y) return 0;
    return 1;
  }
  vis[p][q] = 1;
  dp[p][q] = {x, y};
  for (int k = (0); (1) > 0 ? k < (4) : k > (4); k += (1)) {
    int xx = x + d4i[k], yy = y + d4j[k];
    if (str[(xx % n + n) % n][(yy % m + m) % m] == '.' and dfs(xx, yy))
      return 1;
  }
  return 0;
}
void solve() {
  read(n, m);
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) read(str[i]);
  memset(vis, 0, sizeof(vis));
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1)) {
    for (int j = (0); (1) > 0 ? j < (m) : j > (m); j += (1)) {
      if (str[i][j] == 'S') {
        cout << (dfs(i, j) ? "Yes" : "No");
        return;
      }
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
