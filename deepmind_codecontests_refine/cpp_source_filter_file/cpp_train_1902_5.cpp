#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long modpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
long long bpow(long long a, long long b) {
  if (b < 0) {
    return 0;
  }
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
const int N = 1e5 + 5;
vector<long long> adj[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> cnt(n + 5);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
    }
    long long mx = -1;
    for (long long i = n; i > 0; i--) {
      mx = max(mx, cnt[i]);
    }
    long long c = 0;
    for (long long i = 1; i <= n; i++) {
      if (cnt[i] == mx) {
        c++;
      }
    }
    long long left = (n - c * mx);
    if (left == 0) {
      cout << 0 << '\n';
      continue;
    }
    cout << (c - 1) + (left) / (mx - 1) << '\n';
  }
}
