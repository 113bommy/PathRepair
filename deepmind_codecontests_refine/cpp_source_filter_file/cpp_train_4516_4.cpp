#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long m;
  cin >> m;
  long long mi = 1e15;
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    mi = min(mi, x);
  }
  long long n;
  cin >> n;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i];
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    int j;
    for (j = i; j < min(i + mi, n); j++) ans += v[i];
    i = j + 1;
  }
  cout << ans << "\n";
  return 0;
}
