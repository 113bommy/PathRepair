#include <bits/stdc++.h>
using namespace std;
int const mod = (1e9) + 7;
int const N = (1e5) + 5;
vector<int> gr[N];
double p[N];
int mark[N], d[N];
void dfs(int v) {
  int ans = 0;
  for (int i = 0; i < gr[v].size(); ++i) {
    dfs(gr[v][i]);
    ans += d[gr[v][i]] + 1;
  }
  d[v] = ans;
}
void dfs2(int v, double m, int u) {
  p[v] = 1 + m + (1. * d[u] - d[v] - 1) / 2.;
  for (int i = 0; i < gr[v].size(); ++i) {
    dfs2(gr[v][i], p[v], v);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int p;
    scanf("%d", &p);
    p--;
    gr[p].push_back(i);
  }
  dfs(0);
  p[0] = 1;
  for (int i = 0; i < gr[0].size(); ++i) {
    dfs2(gr[0][i], 1, 0);
  }
  for (int i = 0; i < n; ++i) {
    printf("%0.8fl ", p[i]);
  }
  return 0;
}
