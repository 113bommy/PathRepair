#include <bits/stdc++.h>
using namespace std;
inline long long mod(long long n, long long m) {
  long long ret = n % m;
  if (ret < 0) ret += m;
  return ret;
}
long long gcd(long long a, long long b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long long exp(long long a, long long b, long long m) {
  if (b == 0LL) return 1LL;
  if (b == 1LL) return mod(a, m);
  long long k = mod(exp(a, b / 2, m), m);
  if (b & 1LL) {
    return mod(a * mod(k * k, m), m);
  } else
    return mod(k * k, m);
}
const int N = 1e6 + 10;
bool isp[N];
vector<int> primes[N];
int inc_exc(int p, int n, int id, int cur) {
  if (abs(cur) > n) return 0;
  if (id == primes[p].size()) {
    return n / cur;
  }
  return inc_exc(p, n, id + 1, cur) +
         inc_exc(p, n, id + 1, -(cur * primes[p][id]));
}
long long cnt(int p, int n) { return inc_exc(p, n, 0, 1); }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 2; i < N; i++) {
    isp[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (isp[i]) {
      for (int j = i; j < N; j += i) {
        primes[j].push_back(i);
        isp[j] = 0;
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int x, p, k;
    cin >> x >> p >> k;
    int lo = cnt(p, x);
    int l = lo + 1, r = 1e9;
    int ans = lo + 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (cnt(p, mid) - lo >= k) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << ans << "\n";
  }
}
