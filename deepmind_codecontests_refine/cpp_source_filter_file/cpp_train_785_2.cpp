#include <bits/stdc++.h>
using namespace std;
int v[101], out[100000];
int main() {
  int n, q, sum, nr, i, j, k, t, d;
  cin >> n >> q;
  for (i = 0; i < q; i++) {
    cin >> t >> k >> d;
    sum = 0;
    nr = 0;
    for (j = 1; j <= n && nr < k; j++)
      if (v[j] <= t) {
        nr++;
        sum += j;
        v[j] = -1;
      }
    if (nr == k) {
      out[i] = sum;
      for (j = 1; j <= n; j++)
        if (v[j] == -1) v[j] = t + d;
    } else
      out[i] = -1;
  }
  for (i = 0; i < q; i++) cout << out[i] << endl;
  return 0;
}
