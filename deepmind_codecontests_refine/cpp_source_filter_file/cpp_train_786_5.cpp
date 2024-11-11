#include <bits/stdc++.h>
const int kMaxN = 100000;
std::pair<int, int> p[kMaxN + 1];
int yl[kMaxN + 2], nyl;
int cnt[kMaxN + 2];
int n;
int GetMax(int x) {
  int result = -1;
  while (x >= 0) {
    result = std::max(result, cnt[x]);
    x = (x & (x + 1)) - 1;
  }
  return result;
}
void Insert(int x, int y) {
  while (x < nyl) {
    cnt[x] = std::max(cnt[x], y);
    x = x | (x + 1);
  }
}
int Calc() {
  memset(cnt, -1, sizeof(cnt));
  Insert(std::lower_bound(yl, yl + nyl, p[0].second) - yl, 0);
  for (int i = 1; i <= n; ++i) {
    if (p[i].first < p[0].first) continue;
    int yid = std::lower_bound(yl, yl + nyl, p[i].second) - yl;
    int t = GetMax(yid) + 1;
    if (t > 0) Insert(yid, t);
  }
  return GetMax(n + 1);
}
int main() {
  int V, x, y;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x, &y);
    p[i] = std::pair<int, int>(x, y);
  }
  scanf("%d", &V);
  for (int i = 1; i <= n; ++i) p[i].second *= V;
  for (int i = 1; i <= n; ++i)
    p[i] =
        std::pair<int, int>(p[i].second + p[i].first, p[i].second - p[i].first);
  for (int i = 1; i <= n; ++i) yl[i] = p[i].second;
  yl[0] = 0;
  yl[n + 1] = -2000000000;
  nyl = n + 2;
  std::sort(yl, yl + nyl);
  nyl = std::unique(yl, yl + nyl) - yl;
  std::sort(p + 1, p + n + 1);
  p[0] = std::pair<int, int>(0, 0);
  printf("%d ", Calc());
  p[0] = std::pair<int, int>(-2000000000, -2000000000);
  printf("%d\n", Calc());
  return 0;
}
