#include <bits/stdc++.h>
using namespace std;
long long c[205][205], n, k;
long long f[205][205][5][3];
const int num[5] = {4, 3, 2, 1, 2};
const int num1[5] = {4, 2, 1, 0, 0};
long long get(long long n, long long k, long long cur, long long ty) {
  if (k == 0) return 1;
  long long &ret = f[n][k][cur][ty];
  if (ret != -1)
    return ret;
  else
    ret = 0;
  if (ty == 0) {
    long long now = num[cur];
    for (int i = 0; i <= min(k, now); i++)
      ret = (ret + get(n - 1, k - i, cur, 2) * c[now][i]) % 1000000007;
  } else if (ty == 1) {
    if (n == 0) return 0;
    long long now = num[cur] * 2, now1 = num1[cur];
    for (int i = 0; i <= min(now1, k); i++)
      for (int j = 0; j <= k - i; j++) {
        if (j > now - i * 2) break;
        ret =
            (ret + get(n, k - i - j, cur, 0) * c[now1][i] * c[now - i * 2][j]) %
            1000000007;
      }
  } else {
    ret = (ret + get(n, k, cur, 1)) % 1000000007;
    if (cur == 0) {
      if (k >= 1)
        ret = (ret + get(n, k - 1, 1, 1) * 4 + get(n, k - 1, 2, 1) * 4) %
              1000000007;
      if (k >= 2)
        ret = (ret + get(n, k - 2, 2, 1) * 4 + get(n, k - 2, 3, 1) * 8 +
               get(n, k - 2, 4, 1) * 2) %
              1000000007;
      if (k >= 3) ret = (ret + get(n, k - 3, 3, 1) * 4) % 1000000007;
      if (k == 2) ret = (ret + 2) % 1000000007;
      if (k == 3) ret = (ret + 4) % 1000000007;
      if (k == 4) ret = (ret + 1) % 1000000007;
    } else if (cur == 1) {
      if (k >= 1)
        ret = (ret + get(n, k - 1, 2, 1) * 2 + get(n, k - 1, 3, 1) * 2 +
               get(n, k - 1, 4, 1)) %
              1000000007;
      if (k >= 2) ret = (ret + get(n, k - 2, 3, 1) * 3) % 1000000007;
      if (k == 2) ret = (ret + 2) % 1000000007;
      if (k == 3) ret = (ret + 1) % 1000000007;
    } else if (cur == 2) {
      if (k >= 1) ret = (ret + get(n, k - 1, 3, 1) * 2) % 1000000007;
      if (k == 1) ret = (ret + 1) % 1000000007;
      if (k == 2) ret = (ret + 1) % 1000000007;
    } else if (cur == 3) {
      if (k == 1) ret = (ret + 1) % 1000000007;
    } else if (cur == 4) {
      if (k >= 1) ret = (ret + get(n, k - 1, 3, 1) * 2) % 1000000007;
      if (k == 2) ret = (ret + 1) % 1000000007;
    }
  }
  return ret;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  for (int i = 0; i <= 200; i++) {
    c[i][0] = 1;
    c[i][i] = 1;
    for (int j = 1; j <= i - 1; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
  }
  memset(f, 255, sizeof(f));
  long long ans = get(n, k, 0, 2);
  for (int i = 1; i <= k; i++) ans = ans * i % 1000000007;
  printf("%I64d", ans);
  return 0;
}
