#include <bits/stdc++.h>
int T, a, b, len, v[100005];
char ch[100005];
int main() {
  scanf("%d", &T);
  for (; T; --T) {
    scanf("%d%d %s", &a, &b, ch);
    int num = 0, l = 1, l2 = 0, cnt = 0;
    for (char *s = ch; *s; ++s)
      if (*s == '1' && l)
        l = 0, ++num;
      else if (*s == '0')
        l = 1;
    if (a <= b) {
      printf("%lld\n", (long long)num * a);
      continue;
    }
    l = 0;
    for (char *s = ch; *s; ++s) {
      if (*s == '0' && l) ++l2;
      if (*s == '1' && l2) v[++cnt] = l2, l2 = 0;
      if (*s == '1') l = 1;
    }
    std::sort(v + 1, v + cnt + 1);
    l = l2 = 0;
    for (int i = 1; i <= cnt; ++i)
      if (v[i] * b < a) l += v[i], ++l2;
    printf("%lld\n", (long long)(num - l2) * a + (long long)l * b);
  }
  return 0;
}
