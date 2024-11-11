#include <bits/stdc++.h>
const long long INF = 2000000005;
const long long BIG_INF = 2000000000000000005;
const long long mod = 1000000007;
const long long P = 31;
const long double PI = 3.141592653589793238462643;
const double eps = 1e-9;
using namespace std;
vector<pair<long long, long long> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool valid(long long x, long long y, long long n, long long m) {
  return x >= 0 && y >= 0 && x < n && y < m;
}
mt19937 rng(1999999973);
const long long N = 200000 + 5;
long long b[N], n, col[64], ans = INF, colans = -1;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    col[__builtin_ctz(b[i])]++;
  }
  for (long long i = 0; i <= 63; i++) {
    if (n - col[i] < ans) {
      ans = n - col[i];
      colans = i;
    }
  }
  cout << ans << '\n';
  for (long long i = 0; i < n; i++) {
    if (__builtin_ctz(b[i]) != colans) {
      cout << b[i] << " ";
    }
  }
  return 0;
}
