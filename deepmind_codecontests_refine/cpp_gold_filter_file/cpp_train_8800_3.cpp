#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2 * 1e5 + 10;
int binpow(long long a, int n) {
  long long result = 1;
  while (n) {
    if (n & 1) result = (result * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return result;
}
long long f[N];
int C(int m, int n) {
  long long up = f[m];
  long long down = (f[m - n] * f[n]) % mod;
  long long result = (up * binpow(down, mod - 2)) % mod;
  return result;
}
int n, k;
map<int, int> cnt;
int main() {
  scanf("%d %d", &n, &k);
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    cnt[l]++;
    cnt[r + 1]--;
  }
  int old = cnt.begin()->first;
  long long result = 0, sum = 0;
  for (auto it : cnt) {
    long long len = it.first - old;
    if (sum >= k) {
      result += (C(sum, k) * len) % mod;
    }
    if (result >= mod) result -= mod;
    old = it.first;
    sum += it.second;
  }
  printf("%I64d", result);
  return 0;
}
