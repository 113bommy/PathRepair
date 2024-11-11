#include <bits/stdc++.h>
char str[100010];
int main() {
  int m, n, p, l, r;
  while (scanf("%d%d", &n, &p) != EOF) {
    scanf("%s", str);
    m = (n + 1) / 2;
    p--;
    if (p > m) {
      p = n - p;
    }
    l = r = -1;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      if (str[i] != str[n - 1 - i]) {
        if (l == -1) l = i;
        if (r < i) r = i;
        int x, y;
        x = (str[i] - str[n - 1 - i] + 26) % 26;
        y = (str[n - 1 - i] - str[i] + 26) % 26;
        ans += (x > y ? y : x);
      }
    }
    if (l == -1)
      ;
    else if (p >= r)
      ans += (p - l);
    else if (p <= l)
      ans += (r - p);
    else {
      ans += (r - l + (r - p > p - l ? p - l : r - p));
    }
    printf("%d\n", ans);
  }
  return 0;
}
