#include <bits/stdc++.h>
using namespace std;
int N, M, A, B;
struct UnionFind {
  int par[114514], ra[114514];
  UnionFind() {
    for (int(i) = 0; (i) < (114514); (i)++) par[i] = i, ra[i] = 0;
  }
  int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
  bool same(int a, int b) { return find(a) == find(b); }
  void unite(int a, int b) {
    if ((a = find(a)) != (b = find(b))) {
      if (ra[a] < ra[b]) swap(a, b);
      par[b] = a;
      ra[a] += ra[a] == ra[b];
    }
  }
} uf;
int main() {
  scanf("%d%d", &N, &M);
  int res = 1;
  while (M--) {
    scanf("%d%d", &A, &B), A--, B--;
    if (uf.same(A, B))
      res = res + res;
    else
      uf.unite(A, B);
    if (res >= 1000000009) res -= 1000000009;
    int tmp = res + 1000000009 - 1;
    if (tmp >= 1000000009) tmp -= 1000000009;
    printf("%d\n", tmp);
  }
}
