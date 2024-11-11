#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ps;
vector<vector<int>> cs;
vector<int> tc;
int findp(int i) {
  if (ps[i] != i) {
    ps[i] = findp(ps[i]);
  }
  return ps[i];
}
void merge(int i, int j) { ps[findp(j)] = ps[findp(i)]; }
pair<int, int> b(int u, int v) {
  if (ps[u] == v) {
    return {tc[u], n - tc[u]};
  } else {
    pair<int, int> z = b(v, u);
    return {z.second, z.first};
  }
}
int dfs(int i) {
  if (ps[i] == -1) ps[i] = i;
  tc[i] = 1;
  for (auto c : cs[i]) {
    if (ps[c] == -1) {
      ps[c] = i;
      tc[i] += dfs(c);
    }
  }
  return tc[i];
}
int main() {
  scanf("%d", &(n));
  ps = vector<int>(n, -1);
  tc = vector<int>(n, 0);
  vector<pair<pair<int, int>, pair<int, int>>> tt(0);
  cs = vector<vector<int>>(n, vector<int>(0));
  for (int i = 0; i < (n - 1); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    cs[x].push_back(y);
    cs[y].push_back(x);
    tt.push_back({{x, y}, {y, x}});
  }
  dfs(0);
  long long mr = 0;
  vector<vector<long long>> res(n, vector<long long>(n, -1));
  for (int i = 0; i < (n); ++i) {
    res[i][i] = 0;
  }
  while (((int)(tt).size())) {
    vector<pair<pair<int, int>, pair<int, int>>> ntt(0);
    for (auto i : tt) {
      int u = i.first.first;
      int v = i.second.first;
      int up = i.first.second;
      int vp = i.second.second;
      if (res[u][v] == -1) {
        pair<int, int> z = b(u, up);
        pair<int, int> z2 = b(vp, v);
        res[u][v] =
            max(res[u][vp], res[v][up]) + (long long)z.first * z2.second;
        res[v][u] = res[u][v];
        for (auto c : cs[u]) {
          if (res[v][c] == -1) {
            ntt.push_back({{c, u}, {v, vp}});
          }
        }
        for (auto c : cs[v]) {
          if (res[u][c] == -1) ntt.push_back({{u, up}, {c, v}});
        }
        if (res[ps[u]][v] == -1) {
          ntt.push_back({{ps[u], u}, {v, vp}});
        }
        if (res[ps[v]][u] == -1) {
          ntt.push_back({{ps[v], v}, {u, up}});
        }
        mr = max(mr, res[u][v]);
      }
    }
    tt = ntt;
  }
  printf("%I64d\n", mr);
}
