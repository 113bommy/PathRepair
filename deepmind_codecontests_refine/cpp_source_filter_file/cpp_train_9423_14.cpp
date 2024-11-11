#include <bits/stdc++.h>
using namespace std;
struct BIT {
  vector<long long> bit;
  BIT(long long n) { bit.assign(n + 1, 0); }
  long long psq(long long k) {
    long long sum = 0;
    for (; k; k -= (k & -k)) sum += bit[k];
    return sum;
  }
  long long rsq(long long a, long long b) { return psq(b) - psq(a - 1); }
  long long getmin(long long r) {
    long long ret = 1e10;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret = min(ret, bit[r]);
    return ret;
  }
  void add(long long k, long long v) {
    for (; k < bit.size(); k += (k & -k)) bit[k] += v;
  }
  void set(long long k, long long v) {
    long long aux = rsq(k, k);
    for (; k < bit.size(); k += (k & -k)) bit[k] += v - aux;
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k, a, b, q;
  cin >> n >> k >> a >> b >> q;
  BIT ST(n), ST2(n);
  while (q--) {
    long long p, ai, di, pi;
    cin >> p;
    if (p == 1) {
      cin >> di >> ai;
      ai += ST.rsq(di, di);
      if (ai > a) ai = a;
      ST2.set(di, ai);
      if (ai > b) ai = b;
      ST.set(di, ai);
    } else {
      long long ans = 0;
      cin >> pi;
      ans += ST.psq(pi - 1);
      if (pi + k <= n) ans += ST2.rsq(pi + k, n);
      cout << ans << "\n";
    }
  }
  return 0;
}
