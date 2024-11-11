#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n, k, l[maxn], r[maxn], sz;
char s[maxn], t[maxn];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%s", &n, &k, s + 1);
    for (int i = 1; i < k; i++) t[i * 2 - 1] = '(', t[i * 2] = ')';
    for (int i = 1; i <= n / 2 - k + 1; i++)
      t[2 * k + i] = '(', t[n - i + 1] = ')';
    for (int i = 1; i <= n; i++)
      if (s[i] != t[i])
        for (int j = i + 1; j <= n; j++)
          if (s[j] == t[i]) {
            int x = i, y = j;
            while (x < y) swap(s[x], s[y]), x++, y--;
            l[++sz] = i, r[sz] = j;
            break;
          }
    printf("%d\n", sz);
    for (int i = 1; i <= sz; i++) printf("%d %d\n", l[i], r[i]);
    sz = 0;
  }
  return 0;
}
