#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 5;
int hed[maxn];
int to[maxn];
int nex[maxn];
int etot;
int dis[maxn];
int stk[maxn];
int top;
int n;
int m;
int q;
int N[maxn];
int a[maxn];
int p[maxn];
int lst[maxn];
int rs[maxn];
vector<int> vec;
void addedge(int u, int v) {
  to[etot] = v;
  nex[etot] = hed[u];
  hed[u] = etot++;
}
void dfs(int u) {
  stk[++top] = u;
  for (int i = hed[u]; i != -1; i = nex[i]) {
    dis[to[i]] = dis[u] + 1;
    dfs(to[i]);
  }
  if (top >= n)
    rs[u] = stk[dis[u] - n + 1];
  else
    rs[u] = inf;
  top--;
}
int main() {
  fill(hed, hed + 200004, -1);
  fill(rs, rs + 200004, inf);
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) N[p[i]] = p[i + 1];
  N[p[n]] = p[1];
  lst[a[m]] = m;
  for (int i = m - 1; i >= 1; i--) {
    if (lst[N[a[i]]] != 0) addedge(lst[N[a[i]]], i);
    lst[a[i]] = i;
  }
  for (int i = m; i >= 1; i--) {
    if (!dis[i]) {
      dis[i] = 1;
      top = 0;
      dfs(i);
    }
  }
  for (int i = m; i >= 1; i--) rs[i] = min(rs[i], rs[i + 1]);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (rs[l] <= r)
      vec.push_back(1);
    else
      vec.push_back(0);
  }
  for (int i = 0; i < vec.size(); i++) printf("%d", vec[i]);
  printf("\n");
  return 0;
}
