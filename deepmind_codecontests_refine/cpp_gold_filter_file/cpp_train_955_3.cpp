#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e5 + 5, MOD = 1e9 + 7;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fastpowMOD(long long a, long long p, long long MOD) {
  if (p == 0) return 1;
  long long z = fastpowMOD(a, p / 2, MOD);
  z = (z * z) % MOD;
  if (p % 2) z = (z * a) % MOD;
  return z;
}
bool seive[100005];
void SieveOfEratosthenes(long long n) {
  memset(seive, true, sizeof(seive));
  for (long long p = 2; p * p <= n; p++)
    if (seive[p] == true)
      for (long long i = p * p; i <= n; i += p) seive[i] = false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> q;
  while (q--) {
    long long n, r;
    cin >> n >> r;
    long long a[n + 5];
    set<long long> s;
    long long i;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      s.insert(a[i]);
    }
    vector<long long> v;
    for (auto it : s) v.push_back(it);
    reverse(v.begin(), v.end());
    long long pre = 0;
    long long ans = 0;
    for (auto it : v) {
      if (it + pre > 0) {
        ans++;
        pre -= r;
      } else
        break;
    }
    cout << ans;
    cout << "\n";
  }
}
