#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vld = vector<long double>;
using pii = pair<long long int, long long int>;
using psi = pair<string, long long int>;
using pci = pair<char, long long int>;
using vpii = vector<pii>;
long long int mod = 1e9 + 7;
long long int const maxn = 1e5 + 5;
long long int const inf = 1e18;
long long int dx[] = {0, 0, 1, -1};
long long int dy[] = {1, -1, 0, 0};
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int mul(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int powm(long long int x, long long int n, long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % M;
    x = (x * x) % M;
    n = n / 2;
  }
  return result;
}
long long int modinverse(long long int a, long long int m) {
  return powm(a, m - 2, m);
}
bool prime(long long int x) {
  if (x <= 1) return false;
  for (int i = 2; i <= sqrt(x); i++)
    if (x % i == 0) return false;
  return true;
}
long long int divisor(long long int x) {
  long long int cnt = 0;
  for (int i = 1; i <= sqrt(x); i++) {
    if (x % i == 0) {
      if (i != x / i)
        cnt += 2;
      else
        cnt += 1;
    }
  }
  return cnt;
}
vector<long long int> sieve(long long int n) {
  bool prim[n + 1];
  memset(prim, true, sizeof(prim));
  for (long long int p = 2; p * p <= n; p++) {
    if (prim[p] == true) {
      for (int i = p * p; i <= n; i += p) prim[i] = false;
    }
  }
  vector<long long int> v;
  for (int i = 2; i <= n; i++)
    if (prim[i]) v.push_back(i);
  return v;
}
string tostring(long long int x) {
  string s = "";
  while (x > 0) {
    s += (x % 10 + '0');
    x /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
bool fun(long long int w, long long int m, long long int k, long long int x) {
  long long int tot = 0;
  long long int d = (long long int)tostring(m).size();
  long long int l = m;
  long long int r = pow(10LL, d) - 1;
  while (x > (r - l + 1)) {
    x -= (r - l + 1);
    tot += (r - l + 1) * d;
    l = r + 1;
    d++;
    r = pow(10LL, d) - 1;
  }
  tot += d * x;
  return tot * k <= w;
}
void solve() {
  long long int w, m, k;
  cin >> w >> m >> k;
  long long int low = 0, high = 1e15;
  long long int ans = 0;
  long long int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (fun(w, m, k, mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
