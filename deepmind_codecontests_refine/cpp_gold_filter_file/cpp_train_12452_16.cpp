#include <bits/stdc++.h>
int star[100005];
int scnt;
int pack[100005];
int pcnt;
int unit(int x) {
  if (x > 0) return x;
  return 0;
}
int check(int time) {
  int i;
  int sat = 0;
  for (i = 1; i <= pcnt; i++) {
    if (sat >= star[scnt]) return 1;
    int l = 1, r = scnt, mid, idx;
    while (l <= r) {
      mid = (l + r) / 2;
      if (star[mid] > sat) {
        idx = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    if (star[idx] < pack[i]) {
      if (pack[i] - star[idx] > time) return 0;
      int t = pack[i] - star[idx];
      sat = pack[i] + unit(time - 2 * t);
      if (sat < pack[i] + (time - t) / 2) sat = pack[i] + (time - t) / 2;
    } else
      sat = pack[i] + time;
  }
  if (sat >= star[scnt]) return 1;
  return 0;
}
int main(void) {
  int n;
  char tmp[100005];
  scanf("%d", &n);
  scanf("%s", &tmp[1]);
  int i;
  for (i = 1; i <= n; i++) {
    if (tmp[i] == '*') star[++scnt] = i;
    if (tmp[i] == 'P') pack[++pcnt] = i;
  }
  int l = 1, r = 2 * n - 1, mid, ans;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d", ans);
}
