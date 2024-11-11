#include <bits/stdc++.h>
using namespace std;
const int BITS = 8;
const int N = (1 << BITS);
const int NODES = 50001;
int trie[NODES];
int msbs[NODES][200], lsbs[NODES][N];
int A[NODES];
int parent[NODES], h[NODES], to[NODES];
vector<int> stk;
list<int> e[NODES];
void update(int mask, int val) {
  int root = 1;
  for (int i = BITS - 1; i >= 0; --i) {
    root = (root << 1) + ((mask >> i) & 1);
    trie[root] += val;
  }
}
int query(int mask) {
  int res = 0;
  int root = 1;
  for (int i = BITS - 1; i >= 0; --i) {
    int b = (mask >> i) & 1;
    int broot = (root << 1) + (1 - b);
    if (trie[broot] > 0) {
      root = broot;
      res = (res << 1) + 1 - b;
    } else {
      root = (root << 1) + b;
      res = (res << 1) + b;
    }
  }
  return res;
}
void dfs(int u, int p) {
  stk.emplace_back(u);
  parent[u] = p;
  h[u] = h[p] + 1;
  int n = stk.size();
  update(A[u] >> BITS, 1);
  if (n > N) {
    to[u] = stk[n - N - 1];
    update(A[stk[n - N - 1]] >> BITS, -1);
  }
  for (int bucket = 0; bucket < 200; ++bucket) {
    msbs[u][bucket] = query(bucket);
  }
  for (int i = max(n - N, 0); i < n; ++i) {
    int a = A[stk[i]];
    lsbs[u][a >> BITS] = max(lsbs[u][a >> BITS], (a & 255) ^ (n - i - 1));
  }
  for (int v : e[u])
    if (v != p) {
      dfs(v, u);
    }
  if (n > N) {
    update(A[stk[n - N - 1]] >> BITS, +1);
  }
  update(A[u] >> BITS, -1);
  stk.pop_back();
}
int solve(int u, int v) {
  int res = 0;
  int dis = 0;
  for (int bno = 0; h[v] - h[u] >= 255; v = to[v], dis += N, bno++) {
    int maxMsb = msbs[v][bno];
    int maxLsb = lsbs[v][maxMsb];
    res = max(res, ((maxMsb ^ bno) << BITS) | maxLsb);
  }
  for (; v != parent[u]; v = parent[v], ++dis) {
    res = max(res, A[v] ^ dis);
  }
  return res;
}
int main() {
  int n, u, v, q;
  scanf("%d %d", &n, &q);
  stk.reserve(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", A + i);
  }
  for (int i = 0; i + 1 < n; ++i) {
    scanf("%d %d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  while (q--) {
    scanf("%d %d", &u, &v);
    printf("%d\n", solve(u, v));
  }
  return 0;
}
