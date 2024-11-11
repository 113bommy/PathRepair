#include <bits/stdc++.h>
using namespace std;
constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 2e5 + 1;
using ll = long long;
int N, M, K;
int x[MAXN], y[MAXN];
bool vis[MAXN];
string s;
void Solution() {
  memset(vis, 0, sizeof(vis));
  s += 'L';
  int id = -1;
  for (int i = 0; i < N; i++) {
    if (id == -1 || x[id] > x[i] || (x[id] == x[i] && y[id] > y[i])) id = i;
  }
  vis[id] = true;
  cout << id + 1 << ' ';
  for (int it = 1; it < N; it++) {
    int to = -1;
    for (int i = 1; i < N; i++) {
      if (vis[i]) continue;
      if (to == -1) {
        to = i;
        continue;
      }
      ll now = 1LL * (x[i] - x[id]) * (y[to] - y[id]) -
               1LL * (y[i] - y[id]) * (x[to] - x[id]);
      if (s[it - 1] == 'R') now = -now;
      if (now > 0) to = i;
    }
    vis[to] = true;
    id = to;
    cout << id + 1 << ' ';
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> N) {
    for (int i = 0; i < N; i++) {
      cin >> x[i] >> y[i];
    }
    cin >> s;
    Solution();
  }
  return 0;
}
