#include <bits/stdc++.h>
using namespace std;
const int maxn = 300500;
map<long long, int> mp;
set<int> s[maxn];
struct node {
  int x, y;
} e[maxn];
int f[maxn], id[maxn], ans[maxn];
long long d[maxn], lab[maxn];
int n, m, idx;
void no() {
  puts("NO");
  exit(0);
}
void dfs(int u, int num) {
  ans[u] = num;
  for (auto x : s[u]) {
    if (!ans[x]) dfs(x, num + 1);
  }
}
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
int main() {
  scanf("%d%d", &n, &m);
  lab[0] = 1;
  for (int i = 1; i <= n; i++) lab[i] = lab[i - 1] * 13331, d[i] = lab[i];
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].x, &e[i].y);
    d[e[i].x] += lab[e[i].y];
    d[e[i].y] += lab[e[i].x];
  }
  for (int i = 1; i <= n; i++) {
    if (!mp.count(d[i])) mp[d[i]] = ++idx;
    id[i] = idx;
  }
  for (int i = 1; i <= n; i++) f[i] = i;
  for (int i = 1; i <= m; i++) {
    int x = id[e[i].x], y = id[e[i].y];
    if (x == y) continue;
    if (s[x].count(y) && s[y].count(x)) continue;
    if (find(x) == find(y)) no();
    f[find(x)] = find(y);
    s[x].insert(y);
    s[y].insert(x);
  }
  for (int i = 1; i <= idx; i++)
    if ((int)s[i].size() > 2) no();
  for (int i = 1; i <= idx; i++)
    if ((int)s[i].size() < 2) {
      dfs(i, 1);
      puts("YES");
      for (int i = 1; i <= n; i++) printf("%d ", ans[id[i]]);
      break;
    }
  return 0;
}
