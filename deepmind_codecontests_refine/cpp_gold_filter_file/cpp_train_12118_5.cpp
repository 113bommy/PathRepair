#include <bits/stdc++.h>
bool flag;
int n, m, i, tot0, tot1, x, l, r, mid, now, Ans, Ans2, A[110], D[110], a[110];
bool used[110];
char s[10];
inline bool cmp(int a, int b) {
  if (a > b)
    return (1);
  else
    return (0);
}
inline int max(int a, int b) {
  if (a > b)
    return (a);
  else
    return (b);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) {
    scanf("%s%d", s, &x);
    if (s[0] == 'A')
      A[++tot0] = x;
    else
      D[++tot1] = x;
  }
  std::sort(A + 1, A + tot0 + 1, cmp);
  for (i = 1; i <= m; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + m + 1, cmp);
  flag = 0;
  for (i = 1; i <= tot1; ++i) {
    l = 1;
    r = m;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (a[mid] <= D[i])
        r = mid - 1;
      else
        l = mid + 1;
    }
    while (used[r]) --r;
    if (!r) {
      flag = 1;
      break;
    }
    used[r] = 1;
  }
  if (!flag) {
    flag = 0;
    if (m >= tot0 + tot1) {
      now = 1;
      for (i = 1; i <= tot0; ++i) {
        while (used[now]) ++now;
        if (a[now] < A[i]) {
          flag = 1;
          break;
        }
        ++now;
      }
    } else
      flag = 1;
    if (!flag) {
      Ans = 0;
      for (i = 1; i <= m; ++i)
        if (!used[i]) Ans += a[i];
      for (i = 1; i <= tot0; ++i) Ans -= A[i];
    }
  }
  std::sort(A + 1, A + tot0 + 1);
  Ans2 = 0;
  for (i = 1; i <= tot0 && i <= m && a[i] >= A[i]; ++i) Ans2 += a[i] - A[i];
  printf("%d\n", max(Ans, Ans2));
  return 0;
}
