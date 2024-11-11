#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const unsigned long long base = 5, MOD = 1e17 + 7;
unsigned long long h[N][3], p[N];
char str[N];
int n, q, tot;
inline void Hash() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      tot++, p[tot] = (p[tot - 1] * base) % MOD;
      h[i][0] = h[i - 1][0] + 1;
      if (i & 1) {
        h[i][1] = (h[i - 1][1] * base + 1) % MOD;
        h[i][2] = (h[i - 1][2] * base + 2) % MOD;
      } else {
        h[i][1] = (h[i - 1][1] * base + 2) % MOD;
        h[i][2] = (h[i - 1][2] * base + 1) % MOD;
      }
    } else {
      h[i][0] = h[i - 1][0];
      h[i][1] = h[i - 1][1];
      h[i][2] = h[i - 1][2];
    }
  }
}
inline bool cmp(int l1, int l2, int len) {
  int num = h[l1 + len - 1][0] - h[l1 - 1][0];
  if ((l1 & 1) == (l2 & 1))
    return (h[l1 + len - 1][1] + (MOD - h[l1 - 1][1]) * p[num]) % MOD ==
           (h[l2 + len - 1][1] + (MOD - h[l2 - 1][1]) * p[num]) % MOD;
  else
    return (h[l1 + len - 1][1] + (MOD - h[l1 - 1][1]) * p[num]) % MOD ==
           (h[l2 + len - 1][2] + (MOD - h[l2 - 1][2]) * p[num]) % MOD;
}
inline void solve() {
  scanf("%d", &q);
  while (q--) {
    int l1, l2, len;
    scanf("%d%d%d", &l1, &l2, &len);
    if (h[l1 + len - 1][0] - h[l1 - 1][0] !=
        h[l2 + len - 1][0] - h[l2 - 1][0]) {
      puts("No");
      continue;
    }
    puts(cmp(l1, l2, len) ? "Yes" : "No");
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  Hash();
  solve();
  return 0;
}
