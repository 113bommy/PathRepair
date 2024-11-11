#include <bits/stdc++.h>
using namespace std;
int N, M, Q;
pair<pair<int, int>, pair<int, int> > E[1000005];
int par[1005];
bool type[1005];
int find_parent(int x) {
  if (par[x] == x) return x;
  int y = par[x];
  par[x] = find_parent(par[x]);
  type[x] ^= type[y];
  return par[x];
}
bool merge(int a, int b) {
  int pa = find_parent(a), pb = find_parent(b);
  if (pa == pb) return type[a] != type[b];
  par[pa] = pb;
  type[pa] = type[a] ^ type[b] ^ 1;
  return true;
}
int go(int li, int ri) {
  memset(type, 0, sizeof(type));
  for (int i = 1; i <= N; i++) par[i] = i;
  for (int i = M - 1; i >= 0; i--)
    if (li <= E[i].first.second && E[i].first.second <= ri)
      if (!merge(E[i].second.first, E[i].second.second))
        return E[i].first.first;
  return -1;
}
int main() {
  scanf("%d %d %d", &N, &M, &Q);
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &E[i].second.first, &E[i].second.second,
          &E[i].first.first);
    E[i].first.second = i + 1;
  }
  sort(E, E + M);
  for (int i = 0, li, ri; i < Q; i++) {
    scanf("%d %d", &li, &ri);
    printf("%d\n", go(li, ri));
  }
  return 0;
}
