#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
void _main();
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  _main();
}
struct UnionFind {
  vector<int> par, cnt;
  UnionFind(int NV) {
    par.clear();
    cnt.resize(NV, 1);
    for (int i = 0; i < NV; i++) par.push_back(i);
  }
  void reset() {
    for (int i = 0; i < cnt.size(); i++) cnt[i] = 1;
    for (int i = 0; i < par.size(); i++) par[i] = i;
  }
  int operator[](int x) {
    return par[x] == x ? x : par[x] = operator[](par[x]);
  }
  void operator()(int x, int y) {
    x = operator[](x);
    y = operator[](y);
    if (x != y) par[x] = y, cnt[y] += cnt[x];
  }
};
int N, M, K;
int X[10101], Y[10101];
set<int> E[10101];
int ans[10101];
int vis[10101];
void _main() {
  cin >> N >> M >> K;
  UnionFind uf(K);
  for (int i = 0; i < K; i++) cin >> X[i] >> Y[i];
  for (int a = 0; a < K; a++)
    for (int b = 0; b < K; b++) {
      if (abs(X[a] - X[b]) == 1 && Y[a] == Y[b]) uf(a, b);
      if (abs(Y[a] - Y[b]) == 1 && X[a] == X[b]) uf(a, b);
    }
  for (int a = 0; a < K; a++)
    for (int b = 0; b < K; b++)
      if (uf[a] != uf[b]) {
        int aa = uf[a], bb = uf[b];
        if (abs(X[a] - X[b]) <= 1) {
          E[aa].insert(bb);
          E[bb].insert(aa);
        }
        if (abs(Y[a] - Y[b]) <= 1) {
          E[aa].insert(bb);
          E[bb].insert(aa);
        }
      }
  for (int i = 0; i < K; i++) ans[i] = INT_MAX / 2;
  queue<int> que;
  for (int i = 0; i < K; i++)
    if (X[i] == 1 && Y[i] == 1) {
      int ii = uf[i];
      ans[ii] = 0;
      que.push(ii);
      vis[ii] = 1;
    }
  while (!que.empty()) {
    queue<int> nque;
    while (!que.empty()) {
      int q = que.front();
      que.pop();
      for (int to : E[q])
        if (!vis[to]) {
          nque.push(to);
          ans[to] = ans[q] + 1;
          vis[to] = 1;
        }
    }
    swap(que, nque);
  }
  int an = INT_MAX / 2;
  for (int i = 0; i < K; i++) {
    if (X[i] == N && Y[i] == M)
      an = min(an, ans[uf[i]]);
    else if (abs(X[i] - N) <= 1)
      an = min(an, ans[uf[i]] + 1);
    else if (abs(Y[i] - M) <= 1)
      an = min(an, ans[uf[i]] + 1);
  }
  if (an == INT_MAX / 2) an = -1;
  cout << an << endl;
}
