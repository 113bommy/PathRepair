#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:128000000")
using namespace std;
char s[100001] = {0};
map<char, char> a;
int main() {
  int x, y, z, n, m, p, v, l, r, t, i, k, j, fl;
  scanf("%s", &s);
  l = strlen(s);
  scanf("%i", &n);
  char c1, c2;
  for (i = 1; i <= n; i++) {
    cin >> c1 >> c2;
    a[c1] = c2;
    a[c2] = c1;
  }
  t = 0;
  for (i = 0; i < l - 1; i++) {
    if (a[s[i]] != s[i + 1]) continue;
    j = i;
    k = i + 1;
    p = x = 0;
    while (j >= 0 && (s[j] == s[i] || s[j] == s[i + 1])) {
      j--;
    }
    while (k < l && (s[k] == s[i + 1] || s[k] == s[i])) {
      k++;
    }
    for (y = j + 1; y <= k - 1; y++)
      if (s[y] == s[i])
        p++;
      else
        x++;
    t += min(p, x);
    i = k - 1;
  }
  printf("%i\n", t);
  return 0;
}
