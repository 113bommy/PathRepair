#include <bits/stdc++.h>
const int X_MAX = 1000000 + 1;
int g[X_MAX];
std::vector<int> p[10];
int f(int x) {
  int p = 1;
  while (x) {
    if (x % 10) p *= x % 10;
    x /= 10;
  }
  return p;
}
int main(int argc, char *argv[]) {
  int q;
  scanf("%d", &q);
  for (int i = 1; i < X_MAX; i++) {
    g[i] = i < 10 ? i : g[f(i)];
    p[g[i]].push_back(i);
  }
  while (q--) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    int ans = std::lower_bound(p[k].begin(), p[k].end(), r) -
              std::lower_bound(p[k].begin(), p[k].end(), l);
    printf("%d\n", ans);
  }
  return 0;
}
