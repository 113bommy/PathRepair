#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmin(T &a, T b) {
  if (b < a) {
    a = b;
    return true;
  } else
    return false;
}
template <class T>
bool setmax(T &a, T b) {
  if (b > a) {
    a = b;
    return true;
  } else
    return false;
}
const int MAXN = 100010;
const int P = 800;
int f[P + 10], g[P + 10];
vector<int> xs[MAXN];
int n;
int main() {
  int tm;
  scanf("%d%d", &n, &tm);
  int ans = 0;
  for (int i = (int)(1); i <= (int)(n); ++i) xs[i].clear();
  while (tm--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > n - P)
      xs[y].push_back(x);
    else
      ans += 3;
  }
  memset(f, 50, sizeof(f));
  f[0] = 0;
  for (int y = (int)(1); y <= (int)(n); ++y) {
    memmove(g, f, sizeof(g));
    memset(f, 50, sizeof(f));
    sort(xs[y].begin(), xs[y].end());
    int i = 0;
    int min_g = 1 << 30;
    for (int d = (int)(P); d >= (int)(0); --d) {
      int x = n - d + 1;
      while (i < (int)xs[y].size() && xs[y][i] < x) ++i;
      setmin(f[max(0, d - 1)], g[d] + i * 3);
      setmin(min_g, g[d]);
    }
    i = 0;
    for (int d = (int)(P); d >= (int)(0); --d) {
      int x = n - d;
      while (i < (int)xs[y].size() && xs[y][i] < x) ++i;
      int h = n - x + 1;
      int num = h * (h + 1) / 2 + 2;
      setmin(f[d], min_g + i * 3 + num);
    }
  }
  int tmp = 1 << 30;
  for (int d = (int)(0); d <= (int)(P); ++d) setmin(tmp, f[d]);
  ans += tmp;
  printf("%d\n", ans);
  return 0;
}
