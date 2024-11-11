#include <bits/stdc++.h>
int d[305];
int f[63][200000 + 5];
int n, m;
void add(int x, int a, int y) {
  for (int i = x; i <= n; i += (i & (-i))) {
    f[y][i] += a;
  }
}
int sum(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= (i & (-i))) {
    ans += f[y][i];
  }
  return ans;
}
char s[200000 + 5];
int main() {
  for (int i = 0; i < 10; i++) {
    d[i + '0'] = i;
  }
  for (int i = 0; i < 26; i++) {
    d[i + 'A'] = 10 + i;
  }
  for (int i = 0; i < 26; i++) {
    d[i + 'a'] = 36 + i;
  }
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    add(i, 1, 62);
    add(i, 1, d[s[i]]);
  }
  int x, y;
  char qu[3];
  int l, r;
  int left, right, mid;
  int now, tmp;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    scanf("%s", qu);
    left = 1, right = n;
    while (left < right) {
      mid = (left + right) >> 1;
      if (sum(mid, 62) >= x) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    l = left;
    left = 1, right = n;
    while (left < right) {
      mid = (left + right) >> 1;
      if (sum(mid, 62) >= y) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    r = left;
    now = sum(r, d[*qu]) - sum(l - 1, d[*qu]);
    tmp = sum(l - 1, d[*qu]);
    for (int i = l, j = 0; i <= r, j < now; i = left, j++) {
      left = i, right = r;
      while (left < right) {
        mid = (left + right) >> 1;
        if (sum(mid, d[*qu]) - tmp == 1) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      add(left, -1, d[*qu]);
      add(left, -1, 62);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (sum(i, 62) - sum(i - 1, 62) < 1) {
      continue;
    }
    putchar(s[i]);
  }
  puts("");
  return 0;
}
