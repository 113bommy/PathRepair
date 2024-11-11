#include <bits/stdc++.h>
const int N = 1e5 + 5;
std::vector<int> edge[N];
int a[N];
long long best[N], down[N];
long long ans;
int n;
void DFS(int u, int fa) {
  std::vector<long long> downs;
  for (auto v : edge[u]) {
    if (v == fa) continue;
    DFS(v, u);
    best[u] = std::max(best[u], best[v]);
    downs.push_back(down[v]);
  }
  long long mx1 = 0, mx2 = 0;
  for (auto d : downs) {
    if (d > mx1) {
      mx2 = mx1;
      mx1 = d;
    } else if (d > mx2) {
      mx2 = d;
    }
  }
  best[u] = std::max(best[u], mx1 + mx2 + a[u]);
  down[u] = mx1 + a[u];
  ans = std::max(ans, best[u]);
}
void DFS2(int u, int fa, long long up) {
  up += a[u];
  std::vector<int> children;
  for (auto v : edge[u]) {
    if (v == fa) continue;
    children.push_back(v);
  }
  int sz = children.size();
  if (sz == 0) return;
  std::vector<long long> prebest(sz + 1), sufbest(sz + 1);
  prebest[0] = 0;
  for (int i = 0; i < sz; ++i) {
    prebest[i + 1] = std::max(prebest[i], best[children[i]]);
  }
  sufbest[sz] = 0;
  for (int i = sz - 1; i >= 0; --i) {
    sufbest[i] = std::max(sufbest[i + 1], best[children[i]]);
  }
  std::vector<long long> predown(sz + 1), predown2(sz + 1);
  predown[0] = predown2[0] = 0;
  for (int i = 0; i < sz; ++i) {
    predown[i + 1] = predown[i];
    predown2[i + 1] = predown2[i];
    long long x = down[children[i]];
    if (x > predown[i + 1]) {
      predown2[i + 1] = predown[i + 1];
      predown[i + 1] = x;
    } else if (x > predown2[i + 1]) {
      predown2[i + 1] = x;
    }
  }
  std::vector<long long> sufdown(sz + 1), sufdown2(sz + 1);
  sufdown[sz] = sufdown2[sz] = 0;
  for (int i = sz - 1; i >= 0; --i) {
    sufdown[i] = sufdown[i + 1];
    sufdown2[i] = sufdown2[i + 1];
    long long x = down[children[i]];
    if (x > sufdown[i]) {
      sufdown2[i] = sufdown[i];
      sufdown[i] = x;
    } else if (x > sufdown2[i]) {
      sufdown2[i] = x;
    }
  }
  for (int i = 0; i < sz; ++i) {
    long long cur = std::max(prebest[i], sufbest[i + 1]);
    cur = std::max(cur, up + std::max(predown[i], sufdown[i + 1]));
    cur = std::max(cur, a[u] + predown[i] + sufdown[i + 1]);
    cur = std::max(cur, a[u] + predown[i] + predown2[i]);
    cur = std::max(cur, a[u] + sufdown[i + 1] + sufdown2[i + 1]);
    cur += best[children[i]];
    ans = std::max(ans, cur);
  }
  for (int i = 0; i < sz; ++i) {
    int v = children[i];
    long long new_up = up;
    new_up = std::max(new_up, a[u] + std::max(predown[i], sufdown[i + 1]));
    DFS2(v, u, new_up);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int u, v, i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  DFS(1, 0);
  DFS2(1, 0, 0);
  printf("%I64d\n", ans);
  return 0;
}
