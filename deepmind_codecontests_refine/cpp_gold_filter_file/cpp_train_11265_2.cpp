#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) ans = ans * a % mod;
  return ans;
}
long long pre[500000], nxt[500000];
long long n;
long long a[500000];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  a[0] = 2e9, a[n + 1] = -2e9;
  for (long long i = 1; i <= n; i++) {
    pre[i] = 1;
    if (a[i - 1] < a[i]) pre[i] += pre[i - 1];
  }
  for (long long i = n; i; i--) {
    nxt[i] = 1;
    if (a[i] < a[i + 1]) nxt[i] += nxt[i + 1];
  }
  long long ans = 1;
  for (long long i = 1; i + 2 <= n; i++) {
    if (a[i] < a[i + 2]) {
      ans = max(ans, pre[i] + nxt[i + 2]);
    }
  }
  for (long long i = 1; i <= n; i++) ans = max(ans, pre[i] + nxt[i] - 1);
  cout << ans << endl;
  getchar();
  getchar();
}
