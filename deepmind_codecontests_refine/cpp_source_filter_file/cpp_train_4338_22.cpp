#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 50;
const int inf = 1e8 + 10;
int l[maxn], e[maxn];
int bs(int a[], int x, int n) {
  int l = 0, r = n;
  int m;
  while (l < r) {
    m = (l + r) / 2;
    if (a[m] >= x)
      r = m;
    else
      l = m + 1;
  }
  return l;
}
int get_dis(int x1, int x2, int t) { return abs(x1 - t) + abs(x2 - t); }
int main() {
  int n, m;
  int cl, ce;
  int v;
  cin >> n >> m >> cl >> ce >> v;
  l[0] = e[0] = -inf;
  for (int i = 1; i <= cl; ++i) scanf("%d", &l[i]);
  for (int i = 1; i <= ce; ++i) scanf("%d", &e[i]);
  l[cl + 1] = e[ce + 1] = inf;
  int q;
  scanf("%d", &q);
  while (q--) {
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
    int dy = abs(y1 - y2);
    if (!dy) {
      printf("%d\n", abs(x1 - x2));
      continue;
    }
    int ans = inf * 4;
    int a = bs(l, x1, cl + 2);
    ans = min(ans, dy + min(get_dis(x1, x2, l[a]), get_dis(x1, x2, l[a - 1])));
    a = bs(l, x2, cl + 2);
    ans = min(ans, dy + min(get_dis(x1, x2, l[a]), get_dis(x1, x2, l[a - 1])));
    int b = bs(e, x1, ce + 2);
    ans = min(ans, (dy + v - 1) / v +
                       min(get_dis(x1, x2, e[b]), get_dis(x1, x2, e[b - 1])));
    b = bs(e, x2, ce + 2);
    ans = min(ans, (dy + v - 1) / v +
                       min(get_dis(x1, x2, e[b]), get_dis(x1, x2, e[b - 1])));
    printf("%d\n", ans);
  }
  return 0;
}
