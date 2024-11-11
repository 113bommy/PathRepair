#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > a[500010];
int n, k, resval, dinhu, d[500010];
long long res = 1e14 + 7, s[500010], len[500010], lenu[500010], lenv[500010];
bool dau[500010], check[500010];
queue<int> hd;
void DFS1(int u) {
  if (check[u]) ++d[u];
  for (int i = 0; i < a[u].size(); ++i) {
    int v = a[u][i].first, w = a[u][i].second;
    if (!dau[v]) continue;
    len[v] = len[u] + w;
    dau[v] = false;
    DFS1(v);
    if (d[v] > 0) {
      d[u] += d[v];
      s[u] += s[v] + w;
    }
  }
  if (len[u] > len[dinhu] && check) dinhu = u;
}
void DFS2(int u) {
  for (int i = 0; i < a[u].size(); ++i) {
    int v = a[u][i].first, w = a[u][i].second;
    if (!dau[v]) continue;
    dau[v] = false;
    if (d[v] == 0) s[v] = s[u] + w;
    if (d[v] == k) s[v] = s[u] - w;
    if (d[v] != 0 && d[v] != k) s[v] = s[u];
    DFS2(v);
  }
}
void BFS1() {
  hd.push(dinhu);
  dau[dinhu] = false;
  dinhu = 0;
  while (!hd.empty()) {
    int u = hd.front();
    hd.pop();
    for (int i = 0; i < a[u].size(); ++i) {
      int v = a[u][i].first, w = a[u][i].second;
      if (!dau[v]) continue;
      lenu[v] = lenu[u] + w;
      if (lenu[v] > lenu[dinhu] && check[v]) dinhu = v;
      dau[v] = false;
      hd.push(v);
    }
  }
}
void BFS2() {
  hd.push(dinhu);
  dau[dinhu] = false;
  while (!hd.empty()) {
    int u = hd.front();
    hd.pop();
    for (int i = 0; i < a[u].size(); ++i) {
      int v = a[u][i].first, w = a[u][i].second;
      if (!dau[v]) continue;
      lenv[v] = lenv[u] + w;
      dau[v] = false;
      hd.push(v);
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int u, v, w;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d%d", &u, &v);
    w = 1;
    a[u].push_back(pair<int, int>(v, w));
    a[v].push_back(pair<int, int>(u, w));
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &u);
    check[u] = true;
  }
  memset(dau, true, sizeof(dau));
  dau[1] = false;
  DFS1(1);
  memset(dau, true, sizeof(dau));
  dau[1] = false;
  DFS2(1);
  memset(dau, true, sizeof(dau));
  BFS1();
  memset(dau, true, sizeof(dau));
  BFS2();
  for (int i = 1; i <= n; ++i) {
    long long smin = s[i] * 2 - max(lenu[i], lenv[i]);
    if (smin < res) {
      res = smin;
      resval = i;
    }
  }
  printf("%d\n", resval);
  printf("%I64d", res);
  fclose(stdin);
  fclose(stdout);
}
