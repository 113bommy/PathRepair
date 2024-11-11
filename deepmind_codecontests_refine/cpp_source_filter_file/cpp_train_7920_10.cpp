#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = LLONG_MAX;
const long double pi = acos(-1);
const int S = 1e4 + 7;
const int MOD = 1e9 + 7;
int main() {
  cout << fixed << setprecision(6);
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int m, n, a[37], t;
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cout << m / 2 << endl;
    cin >> a[i];
    if (a[i] == 0) return 0;
  }
  int l = 1, r = m + 1, v, i = 0;
  while (r - l > 1) {
    v = (l + r) / 2;
    cout << v << endl;
    cin >> t;
    if (t == 0) return 0;
    if (t * a[i] == -1)
      r = v;
    else
      l = v;
    i = (i + 1) % n;
  }
  return 0;
}
