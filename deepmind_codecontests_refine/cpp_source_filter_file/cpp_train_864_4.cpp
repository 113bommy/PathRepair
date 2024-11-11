#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100005], t[15][3];
  int n, i, j, k, ans = 0, a, b, l;
  scanf("%s", &s);
  n = strlen(s);
  scanf("%d", &k);
  for (i = 1; i <= k; i++) scanf("%s", &t[i]);
  i = -1;
  while (i <= n - 3) {
    i++;
    a = 0;
    b = 0;
    for (j = 1; j <= k; j++) {
      if (s[j] == t[j][0]) {
        a = 1;
        l = j;
        break;
      }
      if (s[j] == t[j][1]) {
        b = 1;
        l = j;
        break;
      }
    }
    if (a == 0 && b == 0) continue;
    j = i + 1;
    while (j <= n - 1 && (s[j] == t[l][0] || s[j] == t[l][1])) {
      if (s[j] == t[l][0]) a++;
      if (s[j] == t[l][1]) b++;
      j++;
    }
    ans += min(a, b);
    i = j - 1;
  }
  printf("%d", ans);
  return 0;
}
