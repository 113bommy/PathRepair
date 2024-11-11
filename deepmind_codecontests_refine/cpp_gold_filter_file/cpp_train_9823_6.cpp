#include <bits/stdc++.h>
using namespace std;
const int MAXN = 66;
const int MAXM = 2600;
const int INF = 0x3f3f3f3f;
const int MOD = 2520;
long long L, R, cnt[MAXN];
int bit[MAXN];
long long cal(int len, int k, long long n) {
  long long tmp = 0;
  for (int i = len - 1; i >= len - k; i--) tmp = (tmp << 1) + bit[i];
  long long x = tmp;
  for (int i = 0; i < len / k - 1; i++) x = (x << k) + tmp;
  return tmp - (1 << (k - 1)) + 1 - (n < x);
}
long long solve(long long n) {
  int len = 0;
  long long ans = 0, m = n;
  while (m) {
    bit[len++] = m & 1;
    m >>= 1;
  }
  for (int i = 2; i <= len; i++) {
    memset(cnt, 0, sizeof(cnt));
    for (int j = 1; j < i; j++)
      if (i % j == 0) {
        if (i < len)
          cnt[j] = (1 << (j - 1));
        else
          cnt[j] = cal(i, j, n);
        for (int k = 1; k < j; k++)
          if (j % k == 0) {
            cnt[j] -= cnt[k];
          }
        ans += cnt[j];
      }
  }
  return ans;
}
int main() {
  while (scanf("%I64d%I64d", &L, &R) != EOF) {
    printf("%I64d\n", solve(R) - solve(L - 1));
  }
  return 0;
}
