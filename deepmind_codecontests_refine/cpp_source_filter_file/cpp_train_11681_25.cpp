#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> v(n);
  iota(v.begin(), v.end(), 1LL);
  for (long long i = 2, rep; i < n; i++) {
    cout << 2 << ' ' << v[0] << ' ' << v[1] << ' ' << i + 1 << endl
         << flush,
        cin >> rep;
    if (rep == -1) v[1] = i + 1;
  }
  v[v[1] - 1] = 2;
  vector<long long> rnk(n, -1);
  for (long long i = 1; i < n; i++)
    if (i + 1 != v[1])
      cout << 1 << ' ' << v[0] << ' ' << v[1] << ' ' << i + 1 << endl
           << flush,
          cin >> rnk[i];
  long long mxi = max_element(rnk.begin(), rnk.end()) - rnk.begin();
  for (long long i = 1, rep; i < n; i++)
    if (i != mxi) {
      cout << 2 << ' ' << v[0] << ' ' << mxi + 1 << ' ' << i + 1 << endl
           << flush,
          cin >> rep;
      if (rep == -1)
        rnk[i] = (long long)-2e18 + rnk[i];
      else
        rnk[i] = (long long)2e18 - rnk[i];
    }
  rnk[mxi] = 0;
  sort(v.begin() + 2, v.end(),
       [&](long long a, long long b) { return rnk[a - 1] < rnk[b - 1]; });
  cout << 0 << ' ';
  for (long long x : v) cout << x << ' ';
  cout << endl << flush;
}
