#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e5 + 5, MOD = 998244353;
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
bool seive[13000];
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
  long long n;
  cin >> n;
  long long a[n + 5];
  long long i;
  pair<long long, long long> b[n + 5];
  long long k;
  long long sum1 = 0;
  for (i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
    sum1 += b[i].first;
  }
  k = b[0].first / 2;
  long long sum = 0;
  sum += b[0].first;
  sort(b, b + n);
  set<long long> ans;
  for (i = 0; i < n; i++) {
    if (b[i].first > k) break;
    sum += b[i].first;
    ans.insert(b[i].second);
  }
  if (sum >= ((sum1 + 1) / 2)) {
    ans.insert(0);
    cout << ans.size();
    cout << "\n";
    for (auto it : ans) {
      cout << it + 1 << " ";
    }
  } else {
    cout << 0;
  }
}
