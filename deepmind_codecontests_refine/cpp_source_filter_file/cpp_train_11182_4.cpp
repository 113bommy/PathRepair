#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
int fa[maxn];
long long cost[maxn];
int lastu, lastv;
int findset(int x) {
  if (fa[x] != x) fa[x] = findset(fa[x]);
  return fa[x];
}
vector<pair<long long, int> > ans;
int main() {
  int n = readint(), m = readint(), p = readint(), q = readint();
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u = readint(), v = readint(), w = readint();
    lastu = u;
    lastv = v;
    int fu = findset(u), fv = findset(v);
    if (fu == fv)
      cost[fu] += w;
    else {
      cost[fv] += cost[fu] + w;
      fa[fu] = fv;
    }
  }
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      pq;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (findset(i) == i) pq.push(make_pair(cost[i], i)), cnt++;
  }
  int need = cnt - q;
  if (need < 0 || need > p) {
    return !printf("NO");
  }
  while (need--) {
    p--;
    int u = pq.top().second;
    pq.pop();
    int v = pq.top().second;
    pq.pop();
    ans.push_back(make_pair(u, v));
    lastu = u, lastv = v;
    long long res = min((int)1e9 * 1ll, cost[u] + cost[v] + 1ll);
    cost[v] += cost[u] + res;
    pq.push(make_pair(cost[v], v));
  }
  if (p && lastu == 0) {
    return !printf("NO");
  }
  while (p--) {
    ans.push_back(make_pair(lastu, lastv));
  }
  puts("YES");
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
