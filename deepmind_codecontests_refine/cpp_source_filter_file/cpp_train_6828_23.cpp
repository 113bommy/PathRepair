#include <bits/stdc++.h>
using namespace std;
int a[(int)1e5 + 5], n, q, d[320][(int)1e5 + 5], p, k;
int K = 320;
int go(int k, int v) {
  if (v > n) return 0;
  return go(k, v + k + a[v]) + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < K; i++) {
    for (int j = n; j >= 1; j--)
      if (k + a[j] + i <= n)
        d[i][j] = d[i][j + a[j] + i] + 1;
      else
        d[i][j] = 1;
  }
  cin >> q;
  while (q--) {
    cin >> p >> k;
    if (k >= K)
      cout << go(k, p);
    else
      cout << d[k][p];
    cout << "\n";
  }
}
