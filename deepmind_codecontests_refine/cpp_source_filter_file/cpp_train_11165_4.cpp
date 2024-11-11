#include <bits/stdc++.h>
using namespace std;
int t;
long long mod_exp(long long a, long long b) {
  if (b == 0) return 1;
  long long q = mod_exp(a, b / 2);
  if (b & 1) {
    return q * q % 1000000007 * a % 1000000007;
  } else {
    return q * q % 1000000007;
  }
}
long long mod_exp2(long long a, long long b) {
  if (b == 0) return 1;
  long long q = mod_exp(a, b / 2);
  if (b & 1) {
    return min(1000000LL, min(1000000LL, q * q) * a);
  } else {
    return min(1000000LL, q * q);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    int n;
    long long p;
    cin >> n >> p;
    map<int, long long> k;
    long long mx = -1;
    for (int i = 0; i < n; i++) {
      long long a;
      cin >> a;
      k[a]++;
      mx = max(mx, a);
    }
    long long nt = 0;
    long long sumt = 0;
    long long h = 0;
    for (auto it = k.rbegin(); it != k.rend(); ++it) {
      int a = it->first;
      int b = 0;
      if (next(it, 1) != k.rend()) b = next(it, 1)->first;
      if (k[a] >= nt) {
        k[a] = k[a] - nt;
        if (k[a] % 2) {
          nt = mod_exp2(p, a - b);
          h = mod_exp(p, a);
        } else {
          h = 0;
          nt = 0;
        }
        sumt = 0;
      } else if (h) {
        if (nt < n) nt = mod_exp2(p, a - b) * (nt - k[a]);
        sumt = (sumt + k[a] * mod_exp(p, a) % 1000000007) % 1000000007;
      }
    }
    cout << (h + 1000000007 - sumt) % 1000000007 << endl;
  }
  return 0;
}
