#include <bits/stdc++.h>
using namespace std;
const int inf = 2222222222222222222LL;
const int mod = 1000000007LL;
int n = 0, m = 0, ans = 0, cnt = 0, tmp = 0, ma = -inf, mi = inf;
string s;
bool ok, flag;
int dx[5] = {1, -1, 0, 0, 0}, dy[5] = {0, 0, 1, -1, 0};
int ddx[9] = {1, -1, 0, 0, 1, 1, -1, -1, 0},
    ddy[9] = {0, 0, 1, -1, 1, -1, 1, -1, 0};
int a[1 << 12], b[1 << 12][1201], w[15];
char c[15];
int main(void) {
  int q;
  cin >> n >> m >> q;
  for (int i = (int)(0LL); i < (int)(n); i++) scanf("%lld", &w[n - i - 1]);
  for (int i = (int)(0LL); i < (int)(m); i++) {
    scanf("%s", c);
    tmp = 0;
    for (int j = (int)(0LL); j < (int)(n); j++)
      if (c[j] == '1') tmp += 1 << (n - j - 1);
    a[tmp]++;
  }
  for (int i = (int)(0LL); i < (int)(1 << n); i++) {
    for (int j = (int)(0LL); j < (int)(1 << n); j++) {
      tmp = 0;
      for (int bit = (int)(0LL); bit < (int)(n); bit++)
        if (!((i ^ j) >> bit & 1)) tmp += w[bit];
      b[i][tmp] += a[j];
    }
  }
  for (int i = (int)(0LL); i < (int)(1 << n); i++)
    for (int j = (int)(1); j < (int)(1201); j++) {
      b[i][j] += b[i][j - 1];
    }
  for (int i = (int)(0LL); i < (int)(q); i++) {
    scanf("%s", c);
    scanf("%lld", &ans);
    tmp = 0;
    for (int j = (int)(0LL); j < (int)(n); j++)
      if (c[j] == '1') tmp += 1 << (n - j - 1);
    printf("%d\n", b[tmp][ans]);
  }
  return 0;
}
