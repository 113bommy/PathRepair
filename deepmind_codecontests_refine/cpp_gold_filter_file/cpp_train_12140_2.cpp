#include <bits/stdc++.h>
const int N = 1e6;
const int M = 2e5 + 10;
const int mod = 1e9 + 7;
long long n, a[M], cnt[N], cnt2[N], sol[N];
long long brzo_stepenovanje(long long x, long long k) {
  if (k == -1) return 0;
  if (k == 0) return 1;
  if (k == 1) return x;
  if (k % 2)
    return (x * brzo_stepenovanje((x * x) % mod, k / 2)) % mod;
  else
    return brzo_stepenovanje((x * x) % mod, k / 2) % mod;
}
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) cnt[i] = 0, cnt2[i] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    cnt2[a[i]]++;
  }
  for (int i = 2; i <= N; i++)
    for (int j = i; j <= N; j += i) {
      cnt[i] += cnt2[j];
    }
  for (int i = 1; i <= N; i++) sol[i] = 0;
  for (int i = 2; i <= N; i++)
    sol[i] = (cnt[i] * brzo_stepenovanje(2, cnt[i] - 1)) % mod;
  for (int i = N; i >= 2; i--)
    for (int j = i + i; j <= N; j += i) {
      sol[i] -= sol[j];
      if (sol[i] < 0) sol[i] += mod;
    }
  long long ans = 0;
  for (int i = 2; i <= N; i++) {
    ans += (sol[i] * i) % mod;
    ans %= mod;
  }
  printf("%lld", ans);
  return 0;
}
