#include <bits/stdc++.h>
using namespace std;
template <class T>
T read1() {
  T t = 0;
  bool vis = 0;
  char k;
  do (k = getchar()) == '-' && (vis = 1);
  while ('0' > k || k > '9');
  while ('0' <= k && k <= '9')
    t = (t << 3) + (t << 1) + (k ^ '0'), k = getchar();
  return vis ? -t : t;
}
int s, a[6005], w[6005];
vector<int> G[6005];
int ans;
void dfs(int n, int fa) {
  int x = upper_bound(w + 1, w + s + 1, a[n]) - w;
  int tm = w[x];
  w[x] = a[n];
  ans = max(ans, x);
  for (int i = 0; i < G[n].size(); ++i)
    if (G[n][i] ^ fa) dfs(G[n][i], n);
  w[x] = tm;
}
int main() {
  s = read1<int>();
  for (int i = 1; i <= s; ++i) a[i] = read1<int>();
  memset(w, 0x7f, sizeof(w));
  for (int i = 1; i < s; ++i) {
    int u = read1<int>(), v = read1<int>();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int i = 1; i <= s; ++i) dfs(i, 0);
  printf("%d", ans);
  return 0;
}
