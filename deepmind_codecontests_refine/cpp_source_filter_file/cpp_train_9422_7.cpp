#include <bits/stdc++.h>
using namespace std;
long long a[100010], f[100010], ff[100010];
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i], f[a[i]] = i;
  long long res = 0;
  long long maxn = 0;
  long long cnt = 1;
  for (long long i = 2; i <= n; i++) {
    if (f[i] > f[i - 1])
      cnt++;
    else
      cnt = 1;
    maxn = max(maxn, cnt);
  }
  cout << n - maxn;
}
signed main() {
  solve();
  return 0;
}
