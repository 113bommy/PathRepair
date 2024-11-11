#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, k, parent[maxn], siz[maxn], a, b, l, sigma;
int findparent(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = findparent(parent[x]);
}
void merg(int x, int y) {
  x = findparent(x);
  y = findparent(y);
  if (x != y) {
    parent[x] = y;
    siz[y] = siz[y] + siz[x];
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  fill(siz, siz + n + 2, 1);
  for (int i = 1; i <= n; i++) parent[i] = i;
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    merg(a, b);
  }
  for (int i = 1; i <= n; i++)
    if (i == parent[i]) {
      sigma = sigma + min(k, siz[i]);
      l++;
    }
  if (k == 1)
    printf("%d", max(0, l - 2));
  else
    printf("%d", max(0, l - sigma / 2 - 1));
}
