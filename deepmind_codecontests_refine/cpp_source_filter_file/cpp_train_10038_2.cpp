#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
set<long long> st;
map<long long, long long> mp;
long long a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, t, tp, u, w, x,
    y, z, sz, sm, mx, mn, ln, ar[500005 + 5], br[500005 + 5], fr[55], cnt;
int main() {
  while (cin >> n >> m) {
    f = 1;
    for (i = 1; i <= n; i++) {
      cin >> ar[i];
    }
    for (i = 1; i <= m; i++) {
      cin >> br[i];
    }
    sort(ar + 1, ar + n + 1, greater<long long>());
    sort(br + 1, br + m + 1, greater<long long>());
    long long nw = 1;
    long long cnt = 0;
    for (i = 1; i <= n; i++) {
      long long x = ar[i];
      if (br[nw] >= x) {
        nw++;
        cnt++;
        if (nw == m) break;
      }
    }
    cout << n - cnt << endl;
  }
  return 0;
}
