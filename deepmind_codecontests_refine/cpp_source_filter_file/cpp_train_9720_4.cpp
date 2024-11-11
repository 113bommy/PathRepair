#include <bits/stdc++.h>
int n, t, len;
char s[500005];
bool check(int x) {
  int num = x, End;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H')
      num--, End = i;
    else if (s[i] == 'S') {
      num++;
      if (!num) End = i;
    }
  }
  if (num < 0) return 0;
  int last = -1, ans = 0;
  num = x;
  for (int i = 0; i < End; i++) {
    ans++;
    if (s[i] == 'H') {
      num--;
      if (num == -1) {
        if (ans + ((End - i) << 1) <= t) return 1;
        last = i;
      }
    } else if (s[i] == 'S') {
      num++;
      if (!num) {
        ans += ((i - last) << 1);
        last = -1;
      }
    }
  }
  if (ans <= t)
    return 1;
  else
    return 0;
}
int main() {
  scanf("%d %d %s", &n, &t, s);
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (check(l))
    printf("%d", l);
  else
    printf("-1");
  return 0;
}
