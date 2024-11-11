#include <bits/stdc++.h>
using namespace std;
char s[100005], t[100005];
bitset<100005> p[27], ini, ans;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
int main() {
  int n, q, i, j, opt, l, r, len;
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (i = 1; i <= n; i++) {
    p[s[i] - 'a'][i] = 1;
    ini[i] = 1;
  }
  q = read();
  while (q--) {
    opt = read();
    if (opt == 1) {
      l = read();
      scanf("%s", t + 1);
      p[s[l] - 'a'][l] = 0;
      s[l] = t[1];
      p[s[l] - 'a'][l] = 1;
      continue;
    }
    l = read();
    r = read();
    scanf("%s", t + 1);
    len = strlen(t + 1);
    if (r - l + 1 < len) {
      puts("0");
      continue;
    }
    ans = ini;
    int res = 0;
    for (i = 1; i <= len; i++) {
      ans &= (p[t[i] - 'a'] >> (i - 1));
    }
    r -= (len - 1);
    if (r - l + 1 <= 66) {
      for (j = l; j <= r; j++) res += ans[j];
      printf("%d\n", res);
      continue;
    }
    int *o = (int *)&ans;
    while (l & 31) res += ans[l++];
    while (r & 31) res += ans[r--];
    res += ans[r];
    l >>= 5;
    r >>= 5;
    for (j = l; j < r; j++) {
      res += __builtin_popcount(o[j]);
    }
    printf("%d\n", res);
  }
  return 0;
}
