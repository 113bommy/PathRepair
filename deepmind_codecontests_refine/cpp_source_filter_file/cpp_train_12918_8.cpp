#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const long long inf = 2e12;
const long long N = 5e5;
const long long mod = 1e9 + 7;
long long n, m, i, j, l, r, x, y, k, col, ans, res, mx = -INF, mn = INF;
pair<long long, long long> a[N];
string s;
vector<long long> v;
set<long long> st;
map<long long, long long> mp;
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    cin >> a[i].first, a[i].second = i;
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (i = 0; i < m; ++i) {
    col += a[i].first;
    v.push_back(a[i].second);
  }
  v.push_back(0);
  sort(v.begin(), v.end());
  cout << col << endl;
  for (i = 1; i < v.size() - 1; ++i) {
    cout << v[i] - v[i - 1] << " ";
  }
  cout << n - v[i - 1] << endl;
  return 0;
}
