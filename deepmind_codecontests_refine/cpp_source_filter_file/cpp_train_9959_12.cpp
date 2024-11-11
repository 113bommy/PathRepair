#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const string nl = "\n";
long long n, k, hld = -INF, sum, hld1 = 0;
vector<long long> a;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n >> k;
  a.resize(n);
  for (auto& i : a) {
    cin >> i;
  }
  for (long long i = 0; i < n; ++i) {
    sum += a[i];
    hld = max(hld, sum);
    hld1 = min(hld1, sum);
  }
  cout << max(0LL, k - (hld - hld1 - 1)) << nl;
}
