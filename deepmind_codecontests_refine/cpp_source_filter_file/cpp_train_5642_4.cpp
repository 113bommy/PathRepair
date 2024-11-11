#include <bits/stdc++.h>
#pragma gcc optimize("o-big")
#pragma gcc optimize("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> series(1e6 + 1), v(2e5 + 1);
  int q;
  cin >> q;
  for (int u = 0; u < q; u++) {
    int n, k, d, a, b;
    cin >> n >> k >> d;
    int sm = 0, mn = 1e9;
    for (int i = 0; i < d; i++) {
      cin >> a;
      if (!series[a]) sm++;
      series[a]++;
      v[i] = a;
    }
    mn = sm;
    for (int i = 0; i < n - d; i++) {
      cin >> a;
      v[i] = a;
      b = v[i];
      if (series[a] == 0) sm++;
      series[a]++;
      if (series[b] == 1) sm -= 1;
      series[b] -= 1;
      if (mn > sm) mn = sm;
    }
    for (int i = 0; i < n; i++) {
      series[v[i]] = 0;
      v[i] = 0;
    }
    if (mn != 1e9)
      cout << mn << endl;
    else
      cout << sm << endl;
  }
}
