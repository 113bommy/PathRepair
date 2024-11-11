#include <bits/stdc++.h>
using namespace std;
const int maxn = 300002;
char str[maxn];
int a[3 * maxn], b[3 * maxn];
int n;
int pos[3 * maxn], m;
int tmp[3 * maxn], t;
int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) {
    if (str[i] == '(')
      a[i] = 1;
    else
      a[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    b[i] = b[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i + n + n] = a[i + n] = a[i];
    b[i + n + n] = b[i + n] = b[i];
  }
  if (b[n] != 0) {
    printf("0\n1 1");
    return 0;
  }
  int minb = maxn;
  for (int i = 1; i <= n; i++) {
    minb = min(minb, b[i]);
  }
  for (int i = 1; i <= 3 * n; i++) {
    if (b[i] == minb) pos[++m] = i;
  }
  int ans = m / 3;
  int l = 1;
  int r = 1;
  for (int _ = 1; _ < m; _++) {
    int st = pos[_];
    int en = pos[_ + 1];
    t = 0;
    for (int i = st + 1; i < en; i++) {
      if (b[i] == minb + 1) tmp[++t] = i;
    }
    if (t > ans) {
      ans = t;
      l = st + 1;
      r = en;
    }
    for (int __ = 1; __ < t; __++) {
      int tst = tmp[__];
      int ten = tmp[__ + 1];
      int curcnt = 0;
      for (int i = tst + 1; i < ten; i++) {
        if (b[i] == minb + 2) curcnt++;
      }
      if (m / 3 + curcnt > ans) {
        ans = m / 3 + curcnt;
        l = tst + 1;
        r = ten;
      }
    }
  }
  while (l > n) l -= n;
  while (r > n) r -= n;
  printf("%d\n%d %d", ans, l, r);
  return 0;
}
