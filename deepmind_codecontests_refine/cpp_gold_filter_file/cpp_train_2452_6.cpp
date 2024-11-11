#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int N = 1e3 + 10;
const int M = 3e4 + 10;
int n, m, sum[N], s, t, w[M], num[M], mark[N];
bool av[M], flag = 1;
long long ans1 = INF;
int ans1ind;
long long ans2 = INF;
pair<int, int> ans2ind;
long long ans = INF, ansind;
vector<pair<int, int> > adj[N], edge, dfstree;
int stt;
bool DFS(int v, int e = -1, int par = -1) {
  if (flag && e != -1) dfstree.push_back({v, par}), num[dfstree.size() - 1] = e;
  mark[v] = ++stt;
  bool f = (v == t);
  int mule = 0;
  for (auto p : adj[v])
    if (av[p.second]) {
      if (!mark[p.first])
        f |= DFS(p.first, p.second, v), sum[v] += sum[p.first];
      else {
        if (p.first != par && mark[p.first] < mark[v]) sum[v]++, sum[p.first]--;
        if (p.first == par) mule++;
      }
    }
  if (!sum[v] && f && e != -1 && mule < 2)
    if (ans > w[e]) ans = w[e], ansind = e;
  return f;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &s, &t);
  s--, t--;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d %d", &u, &v, &w[i]);
    adj[--u].push_back({--v, i});
    adj[v].push_back({u, i});
    edge.push_back({u, v});
    av[i] = 1;
  }
  DFS(s);
  flag = 0;
  ans1 = ans;
  ans1ind = ansind;
  if (!mark[t]) {
    printf("0\n0\n\n");
    return 0;
  }
  for (int i = 0; i < dfstree.size(); i++) {
    ans = INF;
    stt = 0;
    av[num[i]] = 0;
    memset(mark, 0, sizeof mark);
    memset(sum, 0, sizeof sum);
    DFS(s);
    long long cur = ans + w[num[i]];
    if (ans2 > cur) ans2 = cur, ans2ind = {num[i], ansind};
    av[num[i]] = 1;
  }
  if (min(ans1, ans2) < INF) {
    if (ans1 < ans2)
      printf("%lld\n1\n%d\n", ans1, ans1ind + 1);
    else
      printf("%lld\n2\n%d %d\n", ans2, ans2ind.first + 1, ans2ind.second + 1);
  } else
    printf("-1\n");
}
