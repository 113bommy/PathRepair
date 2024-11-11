#include <bits/stdc++.h>
using namespace std;
int n;
vector<long long> vec[1000005][2], sum[1000005][2];
int root;
vector<pair<int, int> > query[1000005];
long long ans[1000005];
int diist[1000005];
void dfs(int v, int flag, long long dist) {
  vec[root][flag].push_back(dist);
  for (int j = 0; j <= 1; j++) {
    int x = 2 * v + j;
    if (x <= n) dfs(x, flag, diist[x]);
  }
}
void roll(int v) {
  for (pair<int, int> q : query[v]) {
    int idx = q.first;
    long long hap = q.second;
    long long resp = -hap;
    for (int j = 0; j <= 1; j++) {
      auto it = upper_bound(vec[v][j].begin(), vec[v][j].end(), hap) -
                vec[v][j].begin();
      if (it > 0) {
        resp += (long long)hap * it - sum[v][j][it - 1];
      }
    }
    int par = v / 2;
    int me = v;
    while (par >= 1) {
      int tmp = 1 - (me & 1);
      hap -= diist[me];
      if (hap <= 0) break;
      auto it = upper_bound(vec[par][tmp].begin(), vec[par][tmp].end(), hap) -
                vec[par][tmp].begin();
      if (it > 0) {
        resp += (long long)hap * it - sum[par][tmp][it - 1];
      }
      me = par;
      par /= 2;
    }
    ans[idx] = resp;
  }
  for (int j = 0; j <= 1; j++) {
    int x = 2 * v + j;
    if (x <= n) roll(x);
  }
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int val;
    scanf("%d", &val);
    diist[i + 1] = val;
  }
  for (int i = 1; i <= n; i++) {
    root = i;
    for (int j = 0; j <= 1; j++) {
      int x = 2 * i + j;
      if (x > n) break;
      int flag = x & 1;
      dfs(x, flag, diist[x]);
    }
    for (int j = 0; j <= 1; j++) {
      vec[i][j].push_back(0);
      sort(vec[root][j].begin(), vec[root][j].end());
      long long cur = 0;
      for (long long x : vec[root][j]) {
        cur += x;
        sum[root][j].push_back(cur);
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int s, h;
    scanf("%d%d", &s, &h);
    query[s].push_back(make_pair(i, h));
  }
  roll(1);
  for (int i = 0; i < m; i++) printf("%lld\n", ans[i]);
  return 0;
}
