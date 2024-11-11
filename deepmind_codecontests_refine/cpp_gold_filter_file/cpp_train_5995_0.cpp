#include <bits/stdc++.h>
using namespace std;
int i, j, n, k, x, y, freq[3005], aux[3005];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> x;
  for (i = 1; i <= n; ++i) cin >> y, ++freq[y];
  for (i = 1; i <= k; ++i) {
    memset(aux, 0, sizeof(aux));
    for (y = 0, j = 0; j <= 3000; ++j) {
      if (!freq[j]) continue;
      if (y & 1) {
        aux[j] += (freq[j] + 1) / 2;
        aux[j ^ x] += freq[j] - (freq[j] + 1) / 2;
      } else {
        aux[j] += freq[j] - (freq[j] + 1) / 2;
        aux[j ^ x] += (freq[j] + 1) / 2;
      }
      y += freq[j];
      if (y == n) j = 1e5;
    }
    for (j = 0; j <= 3000; ++j) freq[j] = aux[j];
  }
  int gmb = -1, fnc = 1e9;
  for (i = 0; i <= 3000; ++i)
    if (freq[i]) gmb = max(gmb, i), fnc = min(fnc, i);
  cout << gmb << ' ' << fnc << '\n';
  return 0;
}
