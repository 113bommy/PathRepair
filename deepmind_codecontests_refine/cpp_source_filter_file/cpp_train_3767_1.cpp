#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n, m, gs1 = 0, gs2 = 0, c[maxn], vis[maxn];
long long ans = 0;
struct Node1 {
  int x, y, xx;
  bool operator<(const Node1 &rhs) const { return y < rhs.y; }
} a[maxn];
struct Node2 {
  int x, y, yy;
  bool operator<(const Node2 &rhs) const { return yy < rhs.yy; }
} b[maxn];
int lowbit(int x) { return x & -x; }
int find(int x) {
  int ret = 0;
  while (x > 0) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
void add(int x, int val) {
  while (x <= 10001) {
    c[x] += val;
    x += lowbit(x);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y, xx, yy;
    scanf("%d%d%d%d", &x, &y, &xx, &yy);
    x += 5001, y += 5001, xx += 5001, yy += 5001;
    if (x == xx)
      b[++gs2] = (Node2){x, min(y, yy), max(y, yy)};
    else
      a[++gs1] = (Node1){min(x, xx), y, max(x, xx)};
  }
  sort(a + 1, a + 1 + gs1);
  sort(b + 1, b + 1 + gs2);
  sort(a + 1, a + 1 + gs1);
  sort(b + 1, b + 1 + gs2);
  for (int i = 1; i <= gs1; ++i) {
    for (int j = 0; j < maxn; ++j) c[i] = 0;
    for (int j = 1; j <= gs2; ++j) {
      if (b[j].y < a[i].y && b[j].yy > a[i].y) {
        add(b[j].x, 1);
        vis[j] = 1;
      } else
        vis[j] = 0;
    }
    int k = 1;
    for (int j = i + 1; j <= gs1; ++j) {
      while (k <= gs2 && b[k].yy < a[j].y) {
        if (vis[k]) add(b[k].x, -1);
        k++;
      }
      int l = max(a[i].x, a[j].x) - 1, r = min(a[i].xx, a[j].xx);
      if (l < r) {
        int x = find(r) - find(l);
        ans += 1LL * x * (x - 1) / 2;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
