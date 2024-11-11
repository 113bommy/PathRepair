#include <bits/stdc++.h>
using namespace std;
const long long base = 31;
int xx[] = {0, 0, 1, -1};
int yy[] = {-1, 1, 0, 0};
int zz[] = {0, 0, 0, 0, 1, -1};
string step = "URDL";
const int maxn = 1000 + 2;
const long long mod = 1e9 + 7;
long long Pow(long long a, long long b) {
  long long res = 1;
  if (b <= 0) return 1;
  while (b > 0) {
    if (b % 2) {
      res = (res % mod * a % mod);
      res %= mod;
    }
    a = (a % mod * a % mod) % mod;
    b /= 2;
  }
  return res % mod;
}
long long maybe[] = {11,     111,     1111,     11111,
                     111111, 1111111, 11111111, 111111111};
void solve() {
  long long n;
  cin >> n;
  long long min1 = LLONG_MAX;
  long long max1 = LLONG_MIN;
  for (long long i = 1; i * i * i <= n; i++) {
    if (n % i) continue;
    for (long long j = i; j * j <= n / i; j++) {
      if ((n / i) % j) continue;
      long long k = n / (i * j);
      vector<long long> a;
      a.push_back(i);
      a.push_back(j);
      a.push_back(k);
      do {
        long long have = (a[0] + 1) * (a[1] + 2) * (a[2] + 2);
        min1 = min(min1, have - n);
        max1 = max(max1, have - n);
      } while (next_permutation(a.begin(), a.end()));
    }
  }
  cout << min1 << " " << max1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
