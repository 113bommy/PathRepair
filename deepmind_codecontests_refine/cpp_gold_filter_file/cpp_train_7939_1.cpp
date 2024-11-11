#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long double pi = acos(-1);
const long long maxn = 105;
const int mod = 1e9 + 7;
const long long INF = 1e18;
const int MX = 2000000001;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long t, q, n, a, b, c, d, k, l, m, r, x = 0, y = 0, z = 0, sum = 0,
                                             ans = 0, temp = 0, res = 0;
  cin >> n;
  vector<long long> v(n), vc(n);
  for (long long i = 0; i < (n); i++) cin >> v[i];
  sort(v.begin(), v.end());
  l = res = 0, r = 1;
  while (l < n and r < n) {
    vc[r] = v[l++];
    r += 2;
  }
  r = 0;
  while (l < n and r < n) {
    vc[r] = v[l++];
    r += 2;
  }
  for (long long i = 1; i < (n - 1); i++) {
    if (vc[i] < vc[i - 1] and vc[i] < vc[i + 1]) res++;
  }
  cout << res << "\n";
  for (auto x : vc) cout << x << " ";
}
