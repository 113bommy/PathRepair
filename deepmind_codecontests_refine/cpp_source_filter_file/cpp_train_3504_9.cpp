#include <bits/stdc++.h>
using namespace std;
vector<long long int> p[300005], f(300005), b(300005), d(300005);
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int bpow(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return res % 1000000007;
}
void fact(long long int i) {
  f[0] = 1;
  for (long long int k = 1; k <= i; k++) {
    (f[k] = f[k - 1] * k) %= 1000000007;
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
void check() {
  cout << "HI"
       << "\n";
}
long long int comb(long long int i, long long int j) {
  if (j > i) return 0;
  long long int k = f[i];
  long long int g = (f[j] * (f[i - j])) % 1000000007;
  long long int h = bpow(g, 1000000007 - 2);
  return (k * h) % 1000000007;
}
pair<long double, long double> az(long double a, long double b, long double c,
                                  long double d, long double u) {
  long double x1 = (a - c) * cos(u) - (b - d) * sin(u) + c;
  long double y1 = (a - c) * sin(u) + (b - d) * cos(u) + d;
  return {x1, y1};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> b[70];
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      b[63 - __builtin_clzll(a[i])].push_back(a[i]);
    }
    for (long long int i = 0; i < 63; i++) {
      sort(b[i].rbegin(), b[i].rend());
    }
    long long int cur = 0;
    vector<long long int> ans;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < 63; j++) {
        if ((1 << j) & cur) continue;
        if (b[j].size() == 0) continue;
        ans.push_back(b[j].back());
        cur ^= b[j].back();
        b[j].pop_back();
        break;
      }
    }
    if (ans.size() != n) {
      cout << "No"
           << "\n";
    } else {
      cout << "Yes"
           << "\n";
      for (long long int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
}
