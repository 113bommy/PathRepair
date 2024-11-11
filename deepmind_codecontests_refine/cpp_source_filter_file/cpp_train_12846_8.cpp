#include <bits/stdc++.h>
using namespace std;
int const N = 1111;
int n, m, a[N][N];
bitset<N> b[N];
bool check(int x) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) b[i][j] = (a[i][j] >= x);
  for (int i = 0; i < n; i++) {
    if (b[i].count() < 2) continue;
    for (int j = i + 1; j < n; j++)
      if ((b[i] & b[j]).count() > 1) return 1;
  }
  return 0;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  int lo = 0, hi = 1e9 + 1;
  while (hi - lo > 1) {
    int md = lo + hi >> 1;
    (check(md) ? lo : hi) = md;
  }
  printf("%d\n", lo);
}
