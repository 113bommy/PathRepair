#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int modi(long long int n, long long int m = 1000000007) {
  if (n == 0) return 0;
  n %= m;
  n += m;
  n %= m;
  return n;
}
long long int mpow(long long int base, long long int exp) {
  base %= 1000000007;
  long long int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long int)result * base) % 1000000007;
    base = ((long long int)base * base) % 1000000007;
    exp >>= 1;
  }
  return result;
}
const long long int INF = 1e18;
const long long int N = 2e5 + 5;
const long double pi = 4 * atan(1);
long long int n, m, k, t;
long long int p, q, l, r;
long long int arr[N];
long long int a, b, c, d;
long long int x[1000005], y[1000005];
map<char, long long int> m1, m2;
string s, s1, s2, s3;
vector<long long int> v, v1, v2;
long long int pre[N], suff[N];
char grid[11][11];
vector<pair<long long int, long long int>> pl;
long long int fac[N];
bool sortbysec(const pair<long long int, long long int> &a,
               pair<long long int, long long int> &b) {
  return (a.second > b.second);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int i = 0, j = 0;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  pre[0] = 1;
  suff[n - 1] = 1;
  for (long long int i = 1; i < n; i++) {
    if (v[i] >= v[i - 1])
      pre[i] = pre[i - 1] + 1;
    else
      pre[i] = 1;
  }
  for (long long int i = n - 2; i >= 0; i--) {
    if (v[i] >= v[i + 1])
      suff[i] = suff[i + 1] + 1;
    else
      suff[i] = 1;
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    ans = max(ans, pre[i] + suff[i + 1]);
  }
  cout << ans << '\n';
}
