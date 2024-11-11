#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
int n, m;
int a[5005];
int sum[5005];
int sz[5005];
int cur[5005][5005];
int num[5005];
int res = 0;
char s[5005];
int main(void) {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; ++i) {
    gets(s);
    for (int j = 1; j <= m; ++j) {
      int x = s[j - 1] - '0';
      a[j] = x;
      sum[j] = sum[j - 1] + x;
    }
    int r = 1;
    for (int j = 1; j <= m; ++j) {
      r = max(r, j);
      if (!a[j]) {
        continue;
      }
      while (r <= m && sum[r] - sum[j - 1] == r - j + 1) {
        ++r;
      }
      cur[j][sz[j]++] = r - j;
    }
  }
  for (int i = 1; i <= m; ++i) {
    for (long long(j) = 0; (j) < (long long)(m + 1); (j)++) {
      num[j] = 0;
    }
    for (long long(j) = 0; (j) < (long long)(sz[i]); (j)++) {
      ++num[cur[i][j]];
    }
    int it = 0;
    for (long long(j) = 0; (j) < (long long)(m + 1); (j)++) {
      while (num[j]) {
        cur[i][it++] = j;
        --num[j];
      }
    }
    for (int j = 0; j < sz[i]; ++j) {
      res = max(res, cur[i][j] * (sz[i] - j));
    }
  }
  printf("%d\n", res);
  return 0;
}
