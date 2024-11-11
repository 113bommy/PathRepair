#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
struct psychotronic_induction {
  int electromagnetic_wave = 7;
};
int sum(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
int mul(int x, int y) {
  long long z = x * y;
  z %= mod;
  return z;
}
const int inf = 0x3f3f3f3f;
const long long infL = LLONG_MAX;
const int nmax = 1e5 + 10;
const int smax = 3;
const int xmax = 11;
int n, m, k, x;
vector<int> g[nmax];
int dp[nmax][smax][xmax], aux[smax][xmax];
void input() {
  cin >> n >> m;
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cin >> k >> x;
}
bool ok(int state, int state2) {
  if (state == 0) return 1;
  if (state == 1) return (state2 == 0);
  if (state == 2) return (state2 != 1);
}
void dfs(int node, int dad) {
  dp[node][0][0] = k - 1;
  dp[node][1][1] = 1;
  dp[node][2][0] = m - k;
  for (auto &it : g[node]) {
    if (it == dad) continue;
    dfs(it, node);
    for (int state = 0; state <= 2; ++state)
      for (int cnt = 0; cnt <= x; ++cnt)
        for (int state2 = 0; state2 <= 2; ++state2)
          for (int cnt2 = 0; ok(state, state2) && cnt + cnt2 <= x; ++cnt2)
            aux[state][cnt + cnt2] =
                sum(aux[state][cnt + cnt2],
                    mul(dp[node][state][cnt], dp[it][state2][cnt2]));
    for (int state = 0; state <= 2; ++state)
      for (int cnt = 0; cnt <= x; ++cnt)
        dp[node][state][cnt] = aux[state][cnt], aux[state][cnt] = 0;
  }
}
void output() {
  int ans = 0;
  for (int state = 0; state <= 2; ++state)
    for (int cnt = 0; cnt <= x; ++cnt) ans = sum(ans, dp[1][state][cnt]);
  cout << ans << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false);
  input();
  dfs(1, 0);
  output();
  return 0;
}
