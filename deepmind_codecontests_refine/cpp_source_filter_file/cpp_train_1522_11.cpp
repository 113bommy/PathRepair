#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
const int MOD = 1e9 + 7;
const int N = 1e6;
long long l, r, k;
bool isp[N];
int pr[N], tot = 0;
inline void sieve() {
  memset(isp, 1, sizeof(isp));
  for (int i = int(2); i <= int(N - 1); ++i) {
    if (isp[i]) pr[++tot] = i;
    for (int j = 1; j <= tot && i * pr[j] < N; ++j) {
      isp[pr[j] * i] = 0;
      if (i % pr[j] == 0) break;
    }
  }
}
inline bool check(long long n) {
  for (int i = 2; (long long)i * i <= n; ++i)
    if (n % i == 0) return 1;
  return 0;
}
long long DP(long long n, long long k) {
  if (check(k) || n < k) return 0;
  long long ret = n / k;
  for (int i = 1; i <= tot && pr[i] < k && pr[i] < n / k; ++i)
    ret -= DP(n / k, pr[i]);
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve();
  cin >> l >> r >> k;
  cout << DP(r, k) - DP(l - 1, k);
  return 0;
}
