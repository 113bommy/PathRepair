#include <bits/stdc++.h>
using namespace std;
const int nmax = 100010;
const int inf = 1e9 + 7;
int n, k, dp[1010][1010];
int binpow(long long a, int b) {
  long long r = 1;
  while (b) {
    if (b & 1) r *= a;
    a *= a;
    r %= inf;
    a %= inf;
    b >>= 1;
  }
  return r;
}
int a[10], u[10];
int check() {
  memset(u, 0, sizeof u);
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    int j = a[i], t = k + 1;
    while (j != 1 && t--) j = a[j];
    if (j == 1) cnt++;
  }
  return (cnt == k);
}
inline int f(int pos) {
  if (pos == k + 1) return check();
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    a[pos] = i;
    ans += f(pos + 1);
    ans %= inf;
  }
  return ans;
}
int main() {
  cin >> n >> k;
  int pp = 2097152;
  long long ans = pp;
  if (k < 8) ans = f(1);
  ans *= binpow(n - k, n - k);
  ans %= inf;
  ans = (ans + inf) % inf;
  cout << ans << endl;
}
