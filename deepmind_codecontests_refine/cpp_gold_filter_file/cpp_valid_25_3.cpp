#include <bits/stdc++.h>
using namespace std;
vector<long long int> p[300005], q[300005], f(500005), a(500005),
    g(400005, 100), h(400005, 0);
vector<vector<long long int>> b(400005, vector<long long int>(20, 0));
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
void check() {
  cout << "HI"
       << "\n";
}
long long int comb(long long int i, long long int j) {
  if (j > i) return 0;
  long long int k = f[i];
  long long int g = (f[j] * (f[i - j])) % 998244353;
  long long int h = bpow(g, 998244353 - 2);
  return (k * h) % 998244353;
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
  cin >> t;
  while (t--) {
    string s, g;
    cin >> s >> g;
    long long int f = 0;
    for (long long int i = 0; i < s.size(); i++) {
      string a = "";
      for (long long int j = i; j < s.size() && a.size() <= g.size(); j++) {
        a += s[j];
        if (a.size() == g.size() && a == g) {
          f = 1;
          break;
        }
        string b = a;
        for (long long int k = j - 1; k >= 0 && b.size() <= g.size(); k--) {
          b += s[k];
          if (b.size() == g.size() && b == g) {
            f = 1;
            break;
          }
        }
        if (f) break;
      }
      if (f) break;
    }
    if (f) {
      cout << "YES"
           << "\n";
    } else {
      cout << "NO"
           << "\n";
    }
  }
}
