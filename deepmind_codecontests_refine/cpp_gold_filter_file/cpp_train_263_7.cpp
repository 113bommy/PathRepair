#include <bits/stdc++.h>
using namespace std;
const int N = 210;
struct node {
  long long l, r;
} a[N];
bool cmp(const node& u, const node& v) { return u.l < v.l; }
int main() {
  int n, cnt = 0;
  long long l, r, d;
  a[++cnt] = (node){0, 0};
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &l, &d);
    r = l + d - 1;
    int flag = 1;
    for (int j = 1; j <= cnt; j++)
      if ((a[j].l <= l && a[j].r >= l) || (a[j].l <= r && a[j].r >= r) ||
          (a[j].l >= l && a[j].r <= r))
        flag = 0;
    if (flag == 1) {
      printf("%lld %lld\n", l, r);
      a[++cnt] = (node){l, r};
    } else {
      for (int j = 2; j <= cnt; j++)
        if (a[j].l - a[j - 1].r - 1 >= d) {
          flag = 1;
          l = a[j - 1].r + 1, r = l + d - 1;
          break;
        }
      if (flag == 0) l = a[cnt].r + 1, r = l + d - 1;
      printf("%lld %lld\n", l, r);
      a[++cnt] = (node){l, r};
    }
    sort(a + 1, a + cnt + 1, cmp);
  }
  return 0;
}
