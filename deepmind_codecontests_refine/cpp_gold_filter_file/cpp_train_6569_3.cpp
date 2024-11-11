#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, id;
  bool operator<(const node &a) const { return x < a.x; }
};
set<node> v;
int a[400005];
bool b[400005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  {
    int cnt = 0;
    int l, r, rr;
    scanf("%d%d", &l, &r);
    rr = r;
    a[++cnt] = r - l;
    b[cnt] = 1;
    for (int i = 2; i <= n; i++) {
      scanf("%d%d", &l, &r);
      a[++cnt] = l - rr;
      b[cnt] = 0;
      rr = r;
      a[++cnt] = r - l;
      b[cnt] = 1;
    }
    a[++cnt] = m;
    b[cnt] = 0;
    l = 1;
    r = 1;
    int h = m;
    int maxx = 0;
    int ans = 0;
    while (l <= cnt && r <= cnt) {
      while (h > 0) {
        maxx = max(maxx, ans);
        ans += a[r];
        if (b[r] == 0) h -= a[r];
        r++;
      }
      while (h <= 0) {
        maxx = max(maxx, ans + h);
        ans -= a[l];
        if (b[l] == 0) h += a[l];
        l++;
      }
    }
    printf("%d\n", maxx);
  }
}
