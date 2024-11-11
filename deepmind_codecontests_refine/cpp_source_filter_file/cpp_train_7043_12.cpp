#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e5 + 12;
const long long INF = 1e9 + 12;
long long n, m, l, p, a[maxN], b[maxN];
string s;
int32_t main() {
  cin >> n >> m;
  b[0] = INF;
  a[n] = INF;
  for (long long i = 1; i < n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    p = max(p, i - m);
    while (a[i] && p < n) {
      if (b[p] >= a[i]) {
        b[p] -= a[i];
        b[i] += a[i];
        a[i] = 0;
        break;
      }
      b[i] += b[p];
      a[i] -= b[p];
      b[p] = 0;
      p++;
    }
  }
  cout << b[n] << endl;
}
