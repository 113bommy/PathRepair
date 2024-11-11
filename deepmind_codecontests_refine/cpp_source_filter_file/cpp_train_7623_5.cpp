#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 110000;
int n, dis[N], flag = 1, vis[N];
vector<int> to[N];
inline void addEdg(int x, int y) {
  to[x].push_back(y), to[y].push_back(x);
  return;
}
inline int addMod(int a, int b) { return (a += b) >= mod ? a - mod : a; }
inline long long quickpow(long long base, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1) ret = ret * base % mod;
    base = base * base % mod, pw >>= 1;
  }
  return ret;
}
template <class T>
inline void read(T &x) {
  x = 0;
  char ch = getchar(), w = 0;
  while (!isdigit(ch)) w = (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = w ? -x : x;
  return;
}
void dfs(int now, int fa) {
  for (auto &v : to[now]) {
    if (v == fa) continue;
    dis[v] = dis[now] + 1, dfs(v, now);
  }
  return;
}
int main() {
  int x, y;
  read(n);
  for (register int i = 1; i < n; ++i) read(x), read(y), addEdg(x, y);
  dfs(1, 0);
  int ans = n - 1, f0 = 0, f1 = 1;
  for (register int i = 1; i <= n; ++i) {
    if (to[i].size() != 1) continue;
    if (dis[i] & 1)
      f1 = 1;
    else
      f0 = 1;
    if (vis[to[i][0]]) --ans;
    vis[to[i][0]] = 1;
  }
  if (f0 && f1) flag = 3;
  cout << flag << ' ' << ans << endl;
  return 0;
}
