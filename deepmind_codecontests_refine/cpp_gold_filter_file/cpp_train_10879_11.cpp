#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T, class U>
inline T tmin(T a, U b) {
  return (a < b) ? a : b;
}
template <class T, class U>
inline T tmax(T a, U b) {
  return (a > b) ? a : b;
}
template <class T, class U>
inline void amax(T &a, U b) {
  if (b > a) a = b;
}
template <class T, class U>
inline void amin(T &a, U b) {
  if (b < a) a = b;
}
template <class T>
inline T tabs(T a) {
  return (a > 0) ? a : -a;
}
template <class T>
T gcd(T a, T b) {
  while (b != 0) {
    T c = a;
    a = b;
    b = c % b;
  }
  return a;
}
const int N = 1000005;
int a[N], b[N], pos[N];
long long dp[N], tmp[N], s[N];
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  int n, k;
  long long l;
  cin >> n >> l >> k;
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(a, a + n);
  for (int i = (0); i < (n); ++i) {
    pos[i] = lower_bound(a, a + n, b[i]) - a;
  }
  long long lim = (l - 1) / n + 1, period = l / n;
  k = tmin(k, lim);
  int rest = static_cast<int>(l % n);
  period %= MOD;
  long long ret = l % MOD;
  for (int i = (0); i < (n); ++i) dp[i] = 1;
  for (int x = (2); x < (k + 1); ++x) {
    long long tot = 0;
    for (int i = (0); i < (n); ++i) tmp[i] = 0;
    for (int i = (0); i < (n); ++i) {
      tmp[pos[i]] += dp[i];
      if (tmp[pos[i]] >= MOD) tmp[pos[i]] -= MOD;
    }
    tot = tmp[0];
    for (int i = (1); i < (n); ++i) {
      tmp[i] += tmp[i - 1];
      if (tmp[i] >= MOD) tmp[i] -= MOD;
      (tot += tmp[i]) %= MOD;
    }
    ret = (ret + (period - x + 1) * tot) % MOD;
    for (int i = (0); i < (rest); ++i) (ret += tmp[pos[i]]) %= MOD;
    for (int i = (0); i < (n); ++i) dp[i] = tmp[pos[i]];
  }
  if (ret < 0) ret += MOD;
  cout << ret << endl;
  return 0;
}
