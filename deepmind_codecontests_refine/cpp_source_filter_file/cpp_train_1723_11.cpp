#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int maxN = 3e6 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
long long gcd(long long a, long long b) { return !b ? a : gcd(b, a % b); }
long long sq(long long x) { return (x * x) % MOD; }
long long modP(long long a, long long b) {
  return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);
}
int cnt[maxN], ps[maxN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  int inp;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    cnt[inp] += 1;
  }
  for (int i = 1; i < maxN; i++) {
    for (int j = 1; j * i < maxN; j++) {
      ps[i * j] += cnt[i] * (cnt[j] - (i == j));
    }
  }
  for (int i = 1; i < maxN; i++) {
    ps[i] += ps[i - 1];
  }
  int q;
  cin >> q;
  while (q--) {
    cin >> inp;
    cout << n * (n - 1) - ps[inp - 1] << "\n";
  }
  return 0;
}
