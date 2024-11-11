#include <bits/stdc++.h>
using namespace std;
int par[256], sz[256];
int get(int u) { return u == par[u] ? u : par[u] = get(par[u]); }
int main() {
  for (int i = 0; i < 256; i++) par[i] = i, sz[i] = 1;
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0, a; i < 8; i++) {
    scanf("%d", &a);
    for (int j = a - 1; j >= 0; j--)
      if (get(a) != get(j) && sz[get(j)] + sz[get(a)] <= k) {
        sz[get(j)] += sz[get(a)];
        par[get(a)] = get(j);
      } else
        break;
    printf("%d ", get(a));
  }
}
