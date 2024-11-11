#include <bits/stdc++.h>
using namespace std;
const int N = 200 * 1000 + 100;
int shvls[N];
int sums[N];
int dyn[N];
int offers_a[N];
int offers_b[N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> shvls[i];
  }
  sort(shvls, shvls + n);
  sums[0] = 0;
  for (int i = 1; i <= n; i++) {
    sums[i] = sums[i - 1] + shvls[i - 1];
    dyn[i - 1] = -1;
  }
  offers_a[0] = 1;
  for (int i = 1; i <= m; i++) {
    cin >> offers_a[i] >> offers_b[i];
  }
  dyn[0] = 0;
  dyn[k] = -1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      if (offers_a[j] + i > k) continue;
      int result = dyn[i] + sums[i + offers_a[j]] - sums[i + offers_b[j]];
      if (dyn[i + offers_a[j]] > result || dyn[i + offers_a[j]] != -1) {
        dyn[i + offers_a[j]] = result;
      }
    }
  }
  cout << dyn[k];
}
