#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int, vector<long long int>, greater<long long int> >
    ti;
vector<long long int> p[200005], f(200005, 0), b(500005), a(500005);
map<pair<long long int, long long int>, long long int> mp;
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 998244353;
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res % 998244353;
}
void fact(long long int i) {
  f[0] = 1;
  for (long long int k = 1; k <= i; k++) {
    (f[k] = f[k - 1] * k) %= 998244353;
  }
}
long long int isprime(long long int n) {
  if (n == 1) return 0;
  for (long long int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return 0;
  return 1;
}
long long int find(long long int x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
bool cmp(long long int x, long long int y) { return x < y; }
long long int comb(long long int i, long long int j) {
  long long int k = f[i];
  long long int g = (f[j] * (f[i - j])) % 998244353;
  long long int h = bpow(g, 998244353 - 2);
  return (k * h) % 998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long int ans = min(a[n - 2], n - 2);
    cout << ans << "\n";
  }
}
