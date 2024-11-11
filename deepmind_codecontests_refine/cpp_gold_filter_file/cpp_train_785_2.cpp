#include <bits/stdc++.h>
using namespace std;
int v[101], out[100001];
int main() {
  int n, q, sum, nr, i, j, k, t, d;
  cin >> n >> q;
  for (i = 1; i <= q; i++) {
    cin >> t >> k >> d;
    sum = 0;
    nr = 0;
    for (j = 1; j <= n && nr < k; j++)
      if (v[j] <= t) {
        nr++;
        sum += j;
        v[j] = -i;
      }
    if (nr == k) {
      out[i] = sum;
      for (j = 1; j <= n; j++)
        if (v[j] == -i) v[j] = t + d;
    } else
      out[i] = -1;
  }
  for (i = 1; i <= q; i++) cout << out[i] << endl;
  return 0;
}
