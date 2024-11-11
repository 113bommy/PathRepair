#include <bits/stdc++.h>
const int MAXN = 1031, MAXK = 500004, INF = 0x1FFFFFFF;
inline int mymin(int x, int y) {
  int z = (x - y) >> 31;
  return x & z | y & ~z;
}
int n = 0, k = 0;
bool a[MAXN];
std::vector<int> ps, ng;
int fp[MAXK], fn[MAXK];
int main() {
  scanf("%d%d", &n, &k);
  for (int x = 0; k--;) scanf("%d", &x), a[x] = 1;
  if (a[n])
    puts("1");
  else {
    for (int i = 0; i < MAXN; i++)
      if (a[i]) i < n ? ng.push_back(n - i) : ps.push_back(i - n);
    std::fill(fp + 1, fp + MAXK, INF);
    for (auto x : ps) {
      int i = x;
      for (; i + 4 <= MAXK; i += 4) {
        fp[i] = mymin(fp[i], fp[i - x] + 1);
        fp[i + 1] = mymin(fp[i + 1], fp[i - x + 1] + 1);
        fp[i + 2] = mymin(fp[i + 2], fp[i - x + 2] + 1);
        fp[i + 3] = mymin(fp[i + 3], fp[i - x + 3] + 1);
      }
      for (; i < MAXK; i++) fp[i] = mymin(fp[i], fp[i - x] + 1);
    }
    std::fill(fn + 1, fn + MAXK, INF);
    for (auto x : ng) {
      int i = x;
      for (; i + 4 <= MAXK; i += 4) {
        fn[i] = mymin(fn[i], fn[i - x] + 1);
        fn[i + 1] = mymin(fn[i + 1], fn[i - x + 1] + 1);
        fn[i + 2] = mymin(fn[i + 2], fn[i - x + 2] + 1);
        fn[i + 3] = mymin(fn[i + 3], fn[i - x + 3] + 1);
      }
      for (; i < MAXK; i++) fp[i] = mymin(fn[i], fn[i - x] + 1);
    }
    int ans = INF;
    for (int i = 1; i < MAXK; i++) ans = mymin(ans, fp[i] + fn[i]);
    printf("%d\n", ans == INF ? -1 : ans);
  }
  return 0;
}
