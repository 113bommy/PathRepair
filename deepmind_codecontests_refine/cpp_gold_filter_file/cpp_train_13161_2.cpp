#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000006, MaxC = 0x3F3F3F3F, NA = -1;
char s[MaxN], t[MaxN];
bool b[MaxN], c[MaxN], d[MaxN];
int k, n;
int main(void) {
  int i;
  while (scanf(" %s %s", s, t) != EOF) {
    n = strlen(t);
    assert(n + 1 == (int)strlen(s));
    b[0] = true;
    c[n] = true;
    for (i = 0; i < n; i++) {
      b[i + 1] = (s[i] == t[i]);
      c[i] = (s[i + 1] == t[i]);
    }
    for (i = 1; i <= n; i++) b[i] &= b[i - 1];
    for (i = n - 1; i >= 0; i--) c[i] &= c[i + 1];
    for (i = 0; i <= n; i++) d[i] = b[i] && c[i];
    k = 0;
    for (i = 0; i <= n; i++) k += d[i];
    printf("%d\n", k);
    for (i = 0; i <= n; i++)
      if (d[i]) {
        k--;
        printf("%d%c", i + 1, k > 0 ? ' ' : '\n');
      }
  }
  return 0;
}
