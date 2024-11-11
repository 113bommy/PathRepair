#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 5;
const long long INF = 1e18 + 5;
const long long maxn = 5e5 + 5;
long long n = 100000000000, d[151111], mx = -1000000001;
long long a[1511111], ok[100005], sum, cnt, rg[555555], v[555555];
long long bi(long long x, long long y) {
  if (y == 0) return 1ll;
  if (y == 1) return x;
  long long z = bi(x, y / 2);
  z = z * z % n;
  if (y & 1) z = z * x % n;
  return z % n;
}
bool ch(string a, string b) { return a > b; }
map<string, long long> mm;
map<pair<string, string>, long long> ma;
long long first(long long m) {
  long long ans = m;
  for (long long i = 2; i * i <= m; i++) {
    if (m % i == 0) {
      while (m % i == 0) m /= i;
      ans -= ans / i;
    }
  }
  if (m > 1) ans -= ans / m;
  return ans;
}
long long dp[555555][55], b[55][55];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(NULL);
  long long n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  if (k == -1 && n % 2 != m % 2) return cout << 0, 0;
  cout << bi(bi(2, (n - 1)), (m - 1));
  return 0;
}
