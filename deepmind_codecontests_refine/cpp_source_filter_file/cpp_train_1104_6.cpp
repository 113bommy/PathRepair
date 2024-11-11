#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long DP[11][1 << 11][70][2];
long long dp(int base, int mask, int digs, int started) {
  if (digs == 0) return (mask == 0);
  long long &ans = DP[base][mask][digs][started];
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 0; i < base; i++) {
    int new_started = started | (i > 0);
    int new_mask = mask ^ (new_started ? (1 << i) : 0);
    ans += dp(base, new_mask, digs - 1, new_started);
  }
  return ans;
}
int arr[70], sz;
long long solve(int base, long long n) {
  if (n == 0) return 1;
  sz = 0;
  while (n) {
    arr[sz++] = n % base;
    n /= base;
  }
  for (int i = 0; i < sz - 1 - i; i++) swap(arr[i], arr[sz - 1 - i]);
  if (sz == 1) return 0;
  long long ans = dp(base, 0, sz - 1, 0);
  for (int i = 1; i < arr[0]; i++) ans += dp(base, (1 << i), sz - 1, 1);
  int mask = (1 << arr[0]);
  for (int i = 1; i < sz; i++) {
    for (int j = 0; j < arr[i]; j++)
      ans += dp(base, mask ^ (1 << j), sz - 1 - i, 1);
    mask ^= (1 << arr[i]);
  }
  ans += (mask == 0);
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  memset(DP, -1, sizeof(DP));
  while (t--) {
    int base;
    long long L, R;
    scanf("%d%lld%lld", &base, &L, &R);
    printf("%lld\n", solve(base, R) - solve(base, L - 1));
  }
  return 0;
}
