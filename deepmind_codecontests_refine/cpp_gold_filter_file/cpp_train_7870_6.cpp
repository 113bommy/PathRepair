#include <bits/stdc++.h>
using namespace std;
int T[200100], ls[200100 * 40], rs[200100 * 40], num[200100 * 40], tot;
int n, q;
int update(int rt, int pos, int val) {
  int New = ++tot, tmp = New;
  int l = 1, r = n;
  num[New] = num[rt] + val;
  while (l != r) {
    if (pos <= ((l + r) >> 1)) {
      ls[New] = ++tot;
      rs[New] = rs[rt];
      New = ls[New];
      rt = ls[rt];
      r = ((l + r) >> 1);
    } else {
      rs[New] = ++tot;
      ls[New] = ls[rt];
      New = rs[New];
      rt = rs[rt];
      l = ((l + r) >> 1) + 1;
    }
    num[New] = num[rt] + val;
  }
  return tmp;
}
int query(int lf, int rf, int l, int r, int y1, int y2) {
  if (y1 <= l && y2 >= r) return num[rf] - num[lf];
  int cnt = 0;
  if (y1 <= ((l + r) >> 1))
    cnt += query(ls[lf], ls[rf], l, ((l + r) >> 1), y1, y2);
  if (y2 > ((l + r) >> 1))
    cnt += query(rs[lf], rs[rf], ((l + r) >> 1) + 1, r, y1, y2);
  return cnt;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    T[i] = update(T[i - 1], x, 1);
  }
  while (q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    long long ans = 1LL * n * (n - 1) / 2;
    int tmp = num[T[a - 1]];
    ans -= 1LL * tmp * (tmp - 1) / 2;
    tmp = num[T[n]] - num[T[c]];
    ans -= 1LL * tmp * (tmp - 1) / 2;
    if (b > 1) {
      tmp = query(T[0], T[n], 1, n, 1, b - 1);
      ans -= 1LL * tmp * (tmp - 1) / 2;
    }
    if (d < n) {
      tmp = query(T[0], T[n], 1, n, d + 1, n);
      ans -= 1LL * tmp * (tmp - 1) / 2;
    }
    if (b > 1) {
      tmp = query(T[0], T[a - 1], 1, n, 1, b - 1);
      ans += 1LL * tmp * (tmp - 1) / 2;
    }
    if (d < n) {
      tmp = query(T[0], T[a - 1], 1, n, d + 1, n);
      ans += 1LL * tmp * (tmp - 1) / 2;
    }
    if (b > 1) {
      tmp = query(T[c], T[n], 1, n, 1, b - 1);
      ans += 1LL * tmp * (tmp - 1) / 2;
    }
    if (d < n) {
      tmp = query(T[c], T[n], 1, n, d + 1, n);
      ans += 1LL * tmp * (tmp - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
