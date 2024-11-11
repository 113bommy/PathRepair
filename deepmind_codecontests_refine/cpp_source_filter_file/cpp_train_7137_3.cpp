#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int maxq = 100000 + 10;
bitset<maxn> b[maxn];
bitset<maxn> c;
vector<int> edges[maxq];
int op[maxq], x[maxq], y[maxq];
int n, m, q;
int ans[maxq];
void dfs(int s) {
  if (s == 0) {
    for (int i = 0; i < edges[s].size(); i++) {
      ans[edges[s][i]] = ans[s];
      dfs(edges[s][i]);
    }
  }
  if (op[s] == 1) {
    int flag = 0;
    if (b[x[s]][y[s]] == 0) {
      b[x[s]][y[s]] = 1;
      ans[s]++;
      flag = 1;
    }
    for (int i = 0; i < edges[s].size(); i++) {
      ans[edges[s][i]] = ans[s];
      dfs(edges[s][i]);
    }
    if (flag == 1) b[x[s]][y[s]] = 0;
  }
  if (op[s] == 2) {
    int flag = 0;
    if (b[x[s]][y[s]] == 1) {
      b[x[s]][y[s]] = 0;
      ans[s]--;
      flag = 1;
    }
    for (int i = 0; i < edges[s].size(); i++) {
      ans[edges[s][i]] = ans[s];
      dfs(edges[s][i]);
    }
    if (flag == 1) b[x[s]][y[s]] = 1;
  }
  if (op[s] == 3) {
    ans[s] -= b[x[s]].count();
    b[x[s]] ^= c;
    ans[s] += b[x[s]].count();
    for (int i = 0; i < edges[s].size(); i++) {
      ans[edges[s][i]] = ans[s];
      dfs(edges[s][i]);
    }
    b[x[s]] ^= c;
  }
  if (op[s] == 4) {
    for (int i = 0; i < edges[s].size(); i++) {
      ans[edges[s][i]] = ans[s];
      dfs(edges[s][i]);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++) c[i] = 1;
  memset(ans, 0, sizeof(ans));
  for (int i = 1; i <= q; i++) {
    scanf("%d", &op[i]);
    if (op[i] == 1) {
      scanf("%d%d", &x[i], &y[i]);
      edges[i - 1].push_back(i);
    } else if (op[i] == 2) {
      scanf("%d%d", &x[i], &y[i]);
      edges[i - 1].push_back(i);
    } else if (op[i] == 3) {
      scanf("%d", &x[i]);
      edges[i - 1].push_back(i);
    } else {
      scanf("%d", &x[i]);
      edges[x[i]].push_back(i);
    }
  }
  dfs(0);
  for (int i = 1; i <= q; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
