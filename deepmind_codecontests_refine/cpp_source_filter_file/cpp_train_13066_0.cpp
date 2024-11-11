#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000007;
int n, m, a[MaxN];
int l, r, t, c, s[MaxN];
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  i = j = 1;
  while (j <= n) {
    while (j <= n && c < m) {
      if (s[a[j]] == 0) c++;
      s[a[j++]]++;
    }
    while (j <= n && s[a[j]]) j++;
    if (j - i > t) t = j - i, l = i, r = j - 1;
    s[a[i]]--;
    if (s[a[i]] == 0) c--;
    i++;
  }
  printf("%d %d\n", l, r);
  return 0;
}
