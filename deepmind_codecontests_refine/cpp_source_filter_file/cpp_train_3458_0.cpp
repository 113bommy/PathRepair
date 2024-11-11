#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      --a[i][j];
    }
  int ans = 0;
  for (int j = 0; j < m; j++) {
    vector<int> cyc(n, 0);
    for (int i = 0; i < n; i++)
      if (a[i][j] % m == j) {
        int k = a[i][j] / m;
        if (k <= n) cyc[(i - k + n) % n]++;
      }
    int k = 1e9;
    for (int i = 0; i < n; i++) k = min(k, n - cyc[i] + i);
    ans += k;
  }
  cout << ans;
}
