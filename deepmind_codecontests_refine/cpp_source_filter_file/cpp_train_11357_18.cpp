#include <bits/stdc++.h>
using namespace std;
const int N = 400;
int n, c, a[N], len[N], sum[N];
int r[N][N];
char s[1 << 20];
map<string, int> mp;
int cal(int i, int j) {
  int res = 0, p = i;
  while (p <= n) {
    if (r[i][p] >= j) {
      res++;
      p += j;
    } else
      p++;
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    len[i] = strlen(s);
    string str = s;
    if (mp.find(str) == mp.end()) {
      mp[str] = ++c;
    }
    a[i] = mp[str];
    sum[i] = sum[i - 1] + len[i];
  }
  for (int i = 1; i <= n; i++) {
    r[i][i] = n - i + 1;
    for (int j = i + 1; j <= n; j++) {
      r[i][j] = 0;
      for (int k = 0; i + k < j && j + k <= n; k++) {
        if (a[i + k] != a[j + k]) break;
        r[i][j]++;
      }
    }
  }
  int ans = sum[n] + (n - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 2; i + 2 * j - 1 <= n; j++) {
      int x = cal(i, j);
      if (x < 2) continue;
      ans = min(ans, sum[n] + (n - 1) -
                         x * (sum[i + j - 1] - sum[i - 1] + j - 1) + x * j);
    }
  }
  printf("%d\n", ans);
}
