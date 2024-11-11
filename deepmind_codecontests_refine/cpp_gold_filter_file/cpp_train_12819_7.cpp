#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
void pairsort(long long a[], long long b[], long long n) {
  pair<long long, long long> pairt[n];
  for (long long i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long isPrime(long long n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
long long C(long long n, long long r) {
  if (r > n - r) r = n - r;
  long long ans = 1;
  for (long long i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }
  return ans;
}
long long mod = 1e9 + 7;
long long modexpo(long long x, long long p) {
  long long res = 1;
  x = x % mod;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % mod;
    res %= mod;
  }
  return res;
}
long long n, r1, c1, r2, c2;
vector<long long> v1, v2, v3, v4;
string s[100];
map<pair<long long, long long>, long long> m1, m2;
void rec1(long long x, long long y) {
  v1.push_back(x);
  v2.push_back(y);
  m1[{x, y}] = 1;
  if (x < n - 1 && s[x + 1][y] == '0' && m1[{x + 1, y}] == 0) rec1(x + 1, y);
  if (x > 0 && s[x - 1][y] == '0' && m1[{x - 1, y}] == 0) rec1(x - 1, y);
  if (y < n - 1 && s[x][y + 1] == '0' && m1[{x, y + 1}] == 0) rec1(x, y + 1);
  if (y > 0 && s[x][y - 1] == '0' && m1[{x, y - 1}] == 0) rec1(x, y - 1);
}
void rec2(long long x, long long y) {
  v3.push_back(x);
  v4.push_back(y);
  m2[{x, y}] = 1;
  if (x < n - 1 && s[x + 1][y] == '0' && m2[{x + 1, y}] == 0) rec2(x + 1, y);
  if (x > 0 && s[x - 1][y] == '0' && m2[{x - 1, y}] == 0) rec2(x - 1, y);
  if (y < n - 1 && s[x][y + 1] == '0' && m2[{x, y + 1}] == 0) rec2(x, y + 1);
  if (y > 0 && s[x][y - 1] == '0' && m2[{x, y - 1}] == 0) rec2(x, y - 1);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  cin >> r1 >> c1 >> r2 >> c2;
  for (long long i = 0; i < n; i++) cin >> s[i];
  rec1(r1 - 1, c1 - 1);
  rec2(r2 - 1, c2 - 1);
  long long ans = 1e9;
  for (long long i = 0; i < v1.size(); i++)
    for (long long j = 0; j < v3.size(); j++)
      ans = (ans < (v1[i] > v3[j] ? v1[i] - v3[j] : v3[j] - v1[i]) *
                             (v1[i] > v3[j] ? v1[i] - v3[j] : v3[j] - v1[i]) +
                         (v2[i] > v4[j] ? v2[i] - v4[j] : v4[j] - v2[i]) *
                             (v2[i] > v4[j] ? v2[i] - v4[j] : v4[j] - v2[i])
                 ? ans
                 : (v1[i] > v3[j] ? v1[i] - v3[j] : v3[j] - v1[i]) *
                           (v1[i] > v3[j] ? v1[i] - v3[j] : v3[j] - v1[i]) +
                       (v2[i] > v4[j] ? v2[i] - v4[j] : v4[j] - v2[i]) *
                           (v2[i] > v4[j] ? v2[i] - v4[j] : v4[j] - v2[i]));
  cout << ans;
  return 0;
}
