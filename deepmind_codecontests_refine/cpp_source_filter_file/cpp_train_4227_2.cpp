#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
const int M = 123;
const long double Pi = acos(-1);
const long long Inf = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const long double eps = 1e-12;
int n, cnt[N], q[4], tin[N], tout[N], timer;
bool can[N];
vector<int> g[N];
void dfs(int v) {
  cnt[v] = 0;
  tin[v] = ++timer;
  if (g[v].size() == 0) cnt[v] = 1;
  for (auto to : g[v]) {
    dfs(to);
    cnt[v] += cnt[to];
  }
  tout[v] = timer;
}
bool P(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
void Add(int x) {
  for (int j = n; j >= 0; j--) {
    if (can[j]) {
      can[j + x] = 1;
    }
  }
}
void Go(int v, int x, int y) {
  for (auto to : g[v]) {
    if (P(to, x) || P(to, y)) {
      Go(to, x, y);
    } else
      Add(cnt[to]);
  }
}
bool solve(int x, int y) {
  for (int i = 0; i <= n; i++) can[i] = 0;
  can[0] = 1;
  for (auto to : g[1]) {
    if (P(to, x) || P(to, y)) {
      Go(to, x, y);
      continue;
    }
    Add(cnt[to]);
  }
  if (can[cnt[1] / 2 - 1]) return 1;
  return 0;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < 4; i++) cin >> q[i];
  for (int i = 2, p; i <= n; i++) {
    cin >> p;
    g[p].push_back(i);
  }
  dfs(1);
  if (cnt[1]) {
    cout << "NO\n";
    return 0;
  }
  if (solve(q[0], q[1]) && solve(q[2], q[3]))
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
