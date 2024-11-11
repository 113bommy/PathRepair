#include <bits/stdc++.h>
using namespace std;
int n, les, m, f[5010], g[5010];
char s[5010];
template <class Aqua>
inline void read(Aqua &s) {
  s = 0;
  Aqua f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = s * 10 + c - '0', c = getchar();
  s *= f;
}
int main() {
  scanf("%s", s + 1);
  m = n = strlen(s + 1);
  for (les = 1, n--; n; n >>= 1, les <<= 1)
    ;
  (les >>= 1)--;
  for (int i = 0; i <= les; i++) f[i] = 1;
  for (int i = 1; i <= m - les; i++) {
    char mn = 'z' + 1;
    for (int j = 0; j <= les; j++)
      if (f[j]) mn = min(mn, s[i + j]);
    putchar(mn);
    for (int j = 0; j <= les; j++) {
      if (f[j] && s[i + j] == mn)
        g[j] = 1;
      else {
        g[j] = 0;
        for (int k = 0; (1 << k) <= j; k++)
          if ((j >> k) & 1) g[j] |= g[j ^ (1 << k)];
      }
    }
    memcpy(f, g, sizeof(g));
  }
  puts("");
  return 0;
}
