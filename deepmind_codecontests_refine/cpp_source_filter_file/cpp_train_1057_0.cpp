#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  a = abs(a), b = abs(b);
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
long long fast_pow(long long x, long long exp, long long mod) {
  long long ret = 1;
  while (exp) {
    if (exp & 1) ret = (ret * x) % mod;
    x = (x * x) % mod;
    exp >>= 1;
  }
  return ret;
}
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const int inf = (int)1e9 + 5;
vector<vector<int> > adj;
vector<int> v;
priority_queue<int> q;
map<int, int> mp;
set<int> st;
long long x, y, z;
int32_t main(void) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> x >> y >> z;
  int res = (x / z) + (y / z), r = 0;
  x %= z;
  y %= z;
  if (x + y >= z) {
    res += 1;
    r = min(x, y) - (x + y) % z;
  }
  cout << res << " " << r;
  return 0;
}
