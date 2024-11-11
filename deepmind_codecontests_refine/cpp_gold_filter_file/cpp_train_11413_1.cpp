#include <bits/stdc++.h>
using namespace std;
const int N = 101010;
int f[N], deep[N], n, i, j, size[N], k;
long long ans[N];
vector<int> e[N];
struct g {
  int a, b, c, id;
} v[N];
bool cmp(g x, g y) {
  if (x.c == y.c) return deep[x.a] > deep[y.a];
  return x.c < y.c;
}
int gf(int x) {
  while (x != f[x]) x = f[x];
  return x;
}
void dfs(int x, int fa) {
  int i;
  deep[x] = deep[fa] + 1;
  for (i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) dfs(e[x][i], x);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
    e[v[i].a].push_back(v[i].b);
    e[v[i].b].push_back(v[i].a);
    v[i].id = i;
  }
  dfs(1, 0);
  for (i = 1; i <= n; i++) {
    f[i] = i;
    size[i] = 1;
  }
  for (i = 1; i < n; i++)
    if (deep[v[i].a] > deep[v[i].b]) swap(v[i].a, v[i].b);
  sort(v + 1, v + n, cmp);
  for (i = 1; i < n; i++)
    for (i = 1; i < n;) {
      for (j = i; j < n; j++)
        if (v[i].c != v[j].c)
          break;
        else {
          ans[v[j].id] = size[gf(v[j].b)];
          size[gf(v[j].a)] += size[gf(v[j].b)];
          f[gf(v[j].b)] = gf(v[j].a);
        }
      k = j;
      for (j = i; j < k; j++) ans[v[j].id] *= (size[gf(v[j].a)] - ans[v[j].id]);
      i = k;
    }
  int cnt = 0;
  long long Ans = 0;
  for (i = 1; i < n; i++) {
    if (ans[i] > Ans)
      Ans = ans[i], cnt = 1;
    else if (ans[i] == Ans)
      cnt++;
  }
  printf("%I64d %d\n", 2 * Ans, cnt);
  for (i = 1; i < n; i++)
    if (ans[i] == Ans) printf("%d ", i);
}
