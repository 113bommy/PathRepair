#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000000001;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
const long long mod3 = 1000000009;
const long long inf = 1000000000000000000;
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  long long mass[n];
  long long ans[n + 10000];
  memset(ans, 0, sizeof ans);
  for (long long i = 0; i < n; i++) cin >> mass[i];
  sort(mass, mass + n);
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    ans[i % m + 1] += mass[i];
    res += ans[i % m + 1];
    cout << res << " ";
  }
}
