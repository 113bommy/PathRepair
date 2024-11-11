#include <bits/stdc++.h>
using namespace std;
int a[500010], num[500010], m, n, k, s, ned[500010], f, al, ar, ss;
int ans = 1e9;
void inline up(int l, int r) {
  if (ans == k) return;
  l = (l - 1) / k * k + 1;
  if (r - l + 1 < k) {
    r = min(m, l + k - 1);
    l = min(l, r - k + 1);
    l = (l - 1) / k * k + 1;
  }
  if (ans > r - l + 1) {
    ans = r - l + 1;
    al = l;
    ar = r;
  }
}
int main() {
  scanf("%d%d%d%d", &m, &k, &n, &s);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= s; i++) {
    int t;
    scanf("%d", &t);
    if (num[t] == 0) ss++;
    num[t]++;
    ned[t]++;
  }
  int l = 1, r = 1;
  for (r = 1; r <= m; r++) {
    int t = a[r];
    if (ned[t]) {
      num[t]--;
      if (num[t] == 0) f++;
    }
    if (f == ss) {
      up(l, r);
      break;
    }
  }
  if (f != ss) {
    puts("-1");
    return 0;
  }
  while (f == ss) {
    int pl = l, pr = r;
    while (l < r) {
      int t = a[l];
      if (ned[t]) {
        num[t]++;
        if (num[t] > 0) {
          f--;
          l++;
          break;
        }
      }
      l++;
      if (f == ss) up(l, r);
    }
    while (r < m && f != ss) {
      r++;
      int t = a[r];
      if (ned[t]) {
        num[t]--;
        if (num[t] == 0) {
          f++;
          break;
        }
      }
    }
    if (l == pl && r == pr) break;
    if (f == ss) up(l, r);
  }
  ans = ans - k;
  if (m - ans < n * k) {
    puts("-1");
    return 0;
  }
  printf("%d\n", ans);
  bool f = 0;
  for (int i = al; i <= ar; i++) {
    if (ans == 0) break;
    int t = a[i];
    if (!ned[t]) {
      ans--;
      if (f)
        printf(" ");
      else
        f = 1;
      printf("%d", i);
    } else
      ned[t]--;
  }
  return 0;
}
