#include <bits/stdc++.h>
using namespace std;
long long xpow(long long a, long long b) {
  if (!b) return 1;
  if (b == 1) return a;
  if (b & 1) {
    return ((a * xpow(a, b - 1)));
  } else {
    long long p = xpow(a, b / 2);
    return ((p * p));
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long w, m;
  cin >> w >> m;
  vector<long long> v(102, 0);
  long long x = m, k = 0;
  while (x) {
    v[k] = x % w;
    x /= w;
    k++;
  }
  bool f = 0;
  for (long long i = 0; i < 102; i++) {
    if (v[i] == 1 || !v[i]) {
      continue;
    } else {
      if (v[i] == w - 1 || v[i] == w) {
        v[i + 1]++;
      } else {
        cout << "NO";
        f = 1;
        break;
      }
    }
  }
  if (!f) cout << "YES";
  cout << '\n';
  return 0;
}
