#include <bits/stdc++.h>
using namespace std;
long long t, lens, lenc, i, j, k, l, g, f;
char s[502], c[1002];
int main() {
  scanf("%lld", &t);
  for (i = 1; i <= t; i++) {
    scanf("%s%s", s, c);
    lens = strlen(s);
    lenc = strlen(c);
    for (j = 0; j < lens; j++)
      for (k = j; k < lens; k++) {
        g = 0;
        for (l = j; l <= k; l++)
          if (s[l] ^ c[g] || g >= lenc)
            break;
          else
            g++;
        if (l > k || g >= lenc) {
          for (l = k - 1; l >= 0; l--)
            if (s[l] ^ c[g] || g >= lenc)
              break;
            else
              g++;
          if (g >= lenc) f = 1;
        }
      }
    if (f == 1)
      printf("YES\n");
    else
      printf("NO\n");
    f = 0;
  }
  return 0;
}
