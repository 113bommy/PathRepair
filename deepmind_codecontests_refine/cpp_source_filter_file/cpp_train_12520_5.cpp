#include <bits/stdc++.h>
const long long N = 2e5 + 7;
const long long M = 2e4 + 5;
const double eps = 1e-8;
const long long mod = 998244353;
const long long inf = 0x7fffffff;
const double pi = 3.1415926;
using namespace std;
vector<long long> v[N], num;
long long n;
long long dfs(long long x, long long fa) {
  long long sum = 1;
  for (long long i = 0; i < v[x].size(); i++) {
    if (v[x][i] == fa) continue;
    sum += dfs(v[x][i], x);
  }
  if (x != 1) num.push_back((n - sum) * sum);
  return sum;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 0; i <= n; i++) v[i].clear();
    num.clear();
    for (long long i = 1; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    long long m;
    cin >> m;
    vector<long long> p;
    for (long long i = 0; i < m; i++) {
      long long c;
      cin >> c;
      p.push_back(c);
    }
    dfs(1, -1);
    if (m < n - 1) {
      for (long long i = 0; i < n - 1 - m; i++) p.push_back(1);
    }
    sort(num.begin(), num.end());
    sort(p.begin(), p.end());
    long long ans = 0;
    if (m <= n - 1) {
      for (long long i = 0; i < n - 1; i++) {
        ans += (num[i] * p[i]) % mod;
        ans %= mod;
      }
    } else {
      for (long long i = 0; i < n - 2; i++) {
        ans += (num[i] * p[i]) % mod;
        ans %= mod;
      }
      long long add = 1;
      for (long long i = n - 2; i < m; i++) {
        add = (add * p[i]) % mod;
      }
      ans += (add * num[n - 2]) % mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
