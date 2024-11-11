#include <bits/stdc++.h>
const long long maxn = 100010;
long long T, n, top, pla, l, r, cnt;
long long a[maxn], s[maxn], ans[maxn];
inline long long read() {
  char c = getchar();
  long long f = 1, x = 0;
  for (; !isdigit(c); (c == '-') && (f = -1), c = getchar())
    ;
  for (; isdigit(c); x = (x << 1) + (x << 3) + (c ^ 48), c = getchar())
    ;
  return f * x;
}
int main(void) {
  T = read();
  for (; T; --T) {
    n = read();
    top = pla = cnt = 0, l = 1, r = 0;
    for (register int i(1); i <= n; a[i] = read(), ++i)
      ;
    for (register int i(1); i <= n; ++i) {
      if (a[i] > a[i - 1]) {
        if (!pla)
          r = i;
        else {
          pla ^= 1;
          if (l != r)
            s[++top] = l, s[++top] = r;
          else
            s[++top] = r;
          l = i - 1, r = l + 1;
        }
      }
      if (a[i] < a[i - 1]) {
        if (pla)
          r = i;
        else {
          pla ^= 1;
          if (l != r)
            s[++top] = l, s[++top] = r;
          else
            s[++top] = r;
          l = i - 1, r = l + 1;
        }
      }
    }
    s[++top] = l, s[++top] = r;
    for (register int i(1); i <= top; ++i)
      if (a[s[i]] != a[s[i - 1]]) ans[++cnt] = a[s[i]];
    printf("%lld\n", cnt);
    for (register int i(1); i <= cnt; printf("%lld ", ans[i]), ++i)
      ;
    printf("\n");
  }
  return 0;
}
