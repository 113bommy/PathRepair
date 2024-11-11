#include <bits/stdc++.h>
using namespace std;
int m[200000 + 5], f[200000 + 5], n, ans;
struct data {
  int x, w, c, h;
} a[200000 + 5];
bool cmp(data a, data b) { return a.x < b.x; }
int Find(int x) {
  int l = 0, r = ans, re = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (m[mid] <= x)
      re = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return re;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &a[i].x, &a[i].w), a[i].h = a[i].x + a[i].w,
                                     a[i].c = a[i].x - a[i].w;
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; i++) m[i] = 1000000005;
  f[1] = 1, m[1] = a[1].h;
  ans = 1;
  for (int i = 2; i <= n; i++) {
    int k = Find(a[i].c);
    f[i] = k + 1;
    ans = max(ans, f[i]);
    if (a[i].c < m[f[i]]) m[f[i]] = a[i].c;
  }
  cout << ans << endl;
  return 0;
}
