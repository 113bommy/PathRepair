#include <bits/stdc++.h>
int flag[300110], prime[300110], count[300110];
int cnt;
long long exp(long long x, long long y, long long mod) {
  long long ans = 1, num = x;
  while (y != 0) {
    if (y & 1) {
      ans = (ans * num) % mod;
    }
    num = (num * num) % mod;
    y >>= 1;
  }
  return ans;
}
long long cal(int n, long long mod) {
  long long ans = 1;
  int num;
  memset(count, 0, sizeof(count));
  int maxn, i;
  for (i = 0; i < cnt && prime[i] <= n * 2; i++) {
    num = 2 * n;
    while (num != 0) {
      count[i] += (num / prime[i]);
      num /= prime[i];
    }
  }
  maxn = i;
  for (int i = 0; i < cnt && prime[i] <= n; i++) {
    num = n;
    while (num != 0) {
      count[i] -= (num / prime[i]);
      num /= prime[i];
    }
  }
  for (int i = 0; i < cnt && prime[i] <= n; i++) {
    num = n;
    while (num != 0) {
      count[i] -= (num / prime[i]);
      num /= prime[i];
    }
  }
  for (int i = 0; i <= maxn; i++) {
    int num = exp(prime[i], count[i], mod);
    ans = (ans * num) % mod;
  }
  return ans;
}
int main() {
  long long mod = 1000000007LL;
  memset(flag, -1, sizeof(flag));
  cnt = 0;
  for (int i = 2; i <= 100010; i++) {
    if (flag[i]) {
      prime[cnt++] = i;
      for (int j = 2; j <= 100010 / i; j++) {
        flag[i * j] = 0;
      }
    }
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    long long ans = cal(n, mod * 2);
    long long temp = ((ans + mod * 2) % (mod * 2)) / 2;
    temp = ((temp * 2 - n) % mod + mod) % mod;
    printf("%I64d\n", temp % mod);
  }
  return 0;
}
