#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
const int inf = 0x3f3f3f3f;
const long long mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end() {}
int n;
vector<int> e[N];
int d[N];
int vis[N];
void pa(int u, int fa) {
  if (e[u].size() < 3) {
    vis[u] = 1;
    for (auto v : e[u]) {
      if (v == fa) continue;
      pa(v, u);
    }
  }
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (e[i].size() == 1) pa(i, 0);
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      for (auto v : e[i])
        if (vis[v]) d[i]++;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      int tot = 0;
      for (auto v : e[i]) {
        if (vis[v]) continue;
        if (d[v] > min(d[i] + 1, 3)) tot++;
      }
      if (tot >= 3) return puts("No"), void();
    }
  }
  puts("Yes");
}
int main() {
  TIME_START = clock();
  int Test = 1;
  while (Test--) solve();
  TIME_END = clock();
  program_end();
  return 0;
}
