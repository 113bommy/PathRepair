#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int MAXN = 1e5 * 5 + 5;
vector<long long> a, b;
int n, m;
long long f(long long k) {
  long long res = 0;
  for (int i = 0; i < n; i++) res += (a[i] < k ? k - a[i] : 0);
  for (int i = 0; i < m; i++) res += (b[i] > k ? b[i] - k : 0);
  return res;
}
int main() {
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  long long res = 1e18;
  long long l = 1, r = 1e9;
  while (r - l > 3) {
    long long m1, m2;
    m1 = l + (r - l) / 3;
    m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  for (long long i = l; i <= r; i++) {
    res = min(f(i), res);
  }
  cout << res;
  return 0;
}
