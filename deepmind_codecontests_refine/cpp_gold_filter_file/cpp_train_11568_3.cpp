#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
const int N = 15 * ((int)1e6) + 1;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % ((int)1e9 + 7);
    y = y >> 1;
    x = x * x % ((int)1e9 + 7);
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> f(N, 0);
  int maxi = INT_MIN;
  int gd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = x;
    gd = gcd(gd, x);
  }
  for (int i = 0; i < n; i++) {
    v[i] /= gd;
    f[v[i]]++;
    maxi = max(maxi, v[i]);
  }
  vector<int> mark(N, 0);
  int ans = INT_MAX;
  for (int i = 2; i <= maxi; i++) {
    int temp = 0;
    if (mark[i] == 0) {
      for (int j = i; j <= maxi; j += i) {
        mark[j] = 1;
        temp += f[j];
      }
    }
    ans = min(ans, n - temp);
  }
  if (ans == n or ans == INT_MAX) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
