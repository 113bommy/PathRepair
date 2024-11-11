#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 500010, LOG = 20;
long long n, m, k, u, v, x, y, t, S, ans;
vector<long long> vec;
bool add(long long x) {
  for (long long a : vec)
    if (a & (-a) & x) x ^= a;
  if (!x) return 1;
  for (long long &a : vec)
    if (x & (-x) & a) a ^= x;
  vec.push_back(x);
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x >> y, S ^= x, add(x ^ y);
  if (!add(S)) return cout << "1/1" << '\n', 0;
  ans = 1 << vec.size();
  cout << ans - 1 << "/" << ans << '\n';
  return 0;
}
