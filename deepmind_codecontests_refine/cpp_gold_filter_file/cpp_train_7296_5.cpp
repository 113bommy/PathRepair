#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long N = 1e3 + 1;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
int l, r, m, k;
int n, x, a[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> r >> n;
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    cin >> x;
    if (x == 0) {
      cout << 1;
      return 0;
    }
    a[i] = x;
  }
  l = 1;
  while (l < r) {
    m = (l + r) / 2;
    cout << m << endl;
    cin >> x;
    x *= a[k];
    k = (k + 1) % n;
    if (!x) return 0;
    if (x == -1)
      r = m - 1;
    else
      l = m + 1;
  }
  cout << l << endl;
  cin >> x;
}
