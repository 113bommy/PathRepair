#include <bits/stdc++.h>
using namespace std;
int a[500005], b[500005], nex[500005], las[500005], tmp[500005];
bool exist[500005];
inline char gc() {
  static char buf[100005], *l = buf, *r = buf;
  return l == r && (r = (l = buf) + fread(buf, 1, 100005, stdin), l == r)
             ? EOF
             : *l++;
}
inline void read(int &k) {
  char ch;
  while (ch = gc(), ch < '0' || ch > '9')
    ;
  k = ch - '0';
  while (ch = gc(), ch >= '0' && ch <= '9') k = k * 10 + ch - '0';
}
int main() {
  int m, k, n, s, i, j, max, l = 1, r = 0, num = 0, calc;
  read(n), read(k), read(m), read(s);
  max = n - m * k;
  for (i = 1; i <= n; ++i) read(a[i]);
  for (i = 1; i <= s; ++i) read(j), ++b[j], exist[j] = 1;
  for (i = n; i; --i) nex[i] = tmp[a[i]], tmp[a[i]] = i;
  while (r <= n && s) {
    las[a[++r]] = r, --b[a[r]];
    if (exist[a[r]] && b[a[r]] >= 0) --s;
  }
  if (r > n) {
    puts("-1");
    return 0;
  }
  for (; l <= n; ++l) {
    calc = r - l + 1 - k;
    if (calc < 0) calc = 0;
    if (calc + num <= max) {
      printf("%d\n", calc + num);
      for (i = 1; i <= num; ++i) printf("%d ", i - num);
      for (i = l, j = calc; i <= r && j; ++i) {
        if (exist[a[i]]) {
          if (b[a[i]] < 0) ++b[a[i]], printf("%d ", i);
        } else
          --j, printf("%d ", i);
      }
      return 0;
    }
    if (exist[a[l]] && b[a[l]] >= 0) {
      i = nex[las[a[l]]];
      if (!i) {
        puts("-1");
        return 0;
      }
      while (r < i) {
        las[a[++r]] = r;
        if (exist[a[r]]) --b[a[r]];
      }
    }
    ++b[a[l]], ++num;
    if (num == k) num = 0;
  }
  puts("-1");
  return 0;
}
