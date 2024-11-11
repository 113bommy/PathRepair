#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653689793238460;
const long long inf = 0x3f3f3f3f3f3f;
const int N = 2e5 + 5;
const int pr = 31;
using ld = long double;
int mod = 1e9 + 7;
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i % mod;
  return res % mod;
}
int ncr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }
int power(long long x, unsigned int y, int p) {
  int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long nCr(long long n, long long k) {
  long long C[105][1005];
  long long i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  return C[n][k] % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(17);
  int n, k;
  cin >> n >> k;
  int x[100005];
  map<int, int> s;
  for (int i = 0; i < (int)k; i++) {
    cin >> x[i];
    s[x[i]]++;
  }
  int cnt = (n - 1) * 2 + n;
  map<int, int> m;
  map<pair<int, int>, bool> is;
  for (int i = 0; i < (int)k; i++) {
    if (m[x[i] - 1] > 0 && is[make_pair(x[i] - 1, x[i])] == false) {
      cnt--;
      is[make_pair(x[i] - 1, x[i])] = true;
    }
    if (m[x[i] + 1] > 0 && is[make_pair(x[i] + 1, x[i])] == false) {
      cnt--;
      is[make_pair(x[i] + 1, x[i])] = true;
    }
    m[x[i]]++;
  }
  cnt -= s.size();
  cout << cnt << endl;
}
