#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long maxn = 100005;
long long n;
vector<long long> v(maxn), cnt(maxn), subseq(maxn);
long long pow_exp(long long a, long long b, long long n) {
  a %= n;
  long long result = 1;
  while (b > 0) {
    if (b & 1) result = result * a % n;
    a = a * a % n;
    b >>= 1;
  }
  return result;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  long long nmax = 1;
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    ++cnt[v[i]];
    nmax = max(nmax, v[i]);
  }
  for (long long i = nmax; i >= 1; i--) {
    long long _count = cnt[i];
    long long extra = 0;
    for (long long j = 2 * i; j <= nmax; j += i) {
      extra += subseq[j];
      extra %= mod;
      _count += cnt[j];
    }
    subseq[i] = (pow_exp(2, _count, mod) - 1 - extra) % mod;
  }
  cout << subseq[1] << endl;
}
