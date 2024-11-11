#include <bits/stdc++.h>
using namespace std;
int n, m, q, k;
int v[4100][110], cnt[4100], w[15];
char s[15];
inline int tonum(char str[]) {
  int ans = 0;
  for (int j = 0; j < n; ++j) ans = (ans << 1) | (str[j] - '0');
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = n - 1; i >= 0; --i) scanf("%d", w + i);
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    cnt[tonum(s)]++;
  }
  for (int i = 0; i < (1 << n); ++i) {
    for (int num = 0; num < (1 << n); ++num) {
      int sum = 0;
      for (int j = 0; j < n; ++j)
        if ((num >> j & 1) == (i >> j & 1)) sum += w[j];
      if (sum <= 100) v[i][sum] = cnt[num];
    }
    for (int j = 1; j <= 100; ++j) v[i][j] += v[i][j - 1];
  }
  for (int i = 1; i <= q; ++i) {
    scanf("%s%d", s, &k);
    printf("%d\n", v[tonum(s)][k]);
  }
  return 0;
}
