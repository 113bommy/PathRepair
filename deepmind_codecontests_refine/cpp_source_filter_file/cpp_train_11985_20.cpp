#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, next;
} e[1000010];
int n, q;
int num, head[1000010];
long long val[1000010], ans[1000010];
vector<pair<int, long long>> vec[1000010];
void addedge(int a, int b) {
  e[++num].to = b;
  e[num].next = head[a];
  head[a] = num;
}
void dfs(int u, int fa, long long sum, int dep) {
  sum += val[dep];
  for (int i = 0; i < vec[u].size(); i++) {
    sum += vec[u][i].second;
    if (dep + vec[u][i].first + 1 <= n)
      val[dep + vec[u][i].first + 1] -= vec[u][i].second;
  }
  ans[u] = sum;
  for (int i = head[u]; i; i = e[i].next) {
    if (fa ^ e[i].to) {
      dfs(e[i].to, u, sum, dep + 1);
    }
  }
  for (int i = 0; i < vec[u].size(); i++) {
    if (dep + vec[u][i].first + 1 <= n)
      val[dep + vec[u][i].first] += vec[u][i].second;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int u, k;
    long long v;
    scanf("%d%d%lld", &u, &k, &v);
    vec[u].push_back(make_pair(k, v));
  }
  dfs(1, 1, 0, 1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
}
