#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, i, j, k;
  cin >> n >> m >> k;
  long long int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (m == 1) {
    cout << max(arr[0], arr[n - 1]) << "\n";
    return;
  }
  if (k >= (m - 1)) {
    long long int mm = 0;
    for (i = 0; i < m; i++) {
      mm = max(mm, arr[i]);
    }
    for (i = n - 1; i + m <= n; i--) {
      mm = max(mm, arr[i]);
    }
    cout << mm << "\n";
    return;
  }
  i = 0;
  j = k;
  long long int mm = 0;
  while (i <= k) {
    long long int x, y;
    x = i;
    y = n - j - 1;
    long long int re = m - k - 1;
    long long int ii, jj;
    ii = 0;
    jj = re;
    long long int pp = 1e12;
    while (ii <= re) {
      long long int ti, tj;
      ti = x + ii;
      tj = y - jj;
      pp = min({pp, max(arr[ti], arr[tj])});
      ii++;
      jj--;
    }
    mm = max(mm, pp);
    i++;
    j--;
  }
  cout << mm << "\n";
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
