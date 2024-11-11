#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, w;
  bool operator<(const node &N) const { return x + w < N.x + N.w; }
} a[200020];
int main() {
  int n, ans = 0, l = -0x7fffffff;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].w);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (a[i].x - a[i].w > l) l = a[i].x - a[i].w, ans++;
  }
  printf("%d\n", ans);
  return 0;
}
