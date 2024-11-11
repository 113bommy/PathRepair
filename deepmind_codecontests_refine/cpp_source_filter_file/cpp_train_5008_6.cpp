#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, linf = 0;
  cin >> n >> m;
  vector<long long> col(n);
  vector<long long> lin;
  for (long long i = 0; i < n; i++) cin >> col[i];
  sort(col.begin(), col.end());
  for (long long i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 1 && b == 1000000000) {
      linf++;
      continue;
    }
    if (a == 1 && n > 0 && b < col[0]) continue;
    if (a != 1) continue;
    lin.push_back(b);
  }
  if (lin.empty()) {
    cout << linf;
    return 0;
  }
  if (col.empty()) {
    cout << linf;
    return 0;
  }
  sort(lin.begin(), lin.end());
  m = lin.size();
  while (n > 0 && col[n - 1] > lin[m - 1]) {
    n--;
    col.resize(n);
  }
  if (col.empty()) {
    cout << linf;
    return 0;
  }
  long long ans = min(n, m);
  long long k = 0;
  for (long long l = 0; l < n; l++) {
    while (k < m && lin[k] < col[l]) k++;
    if (m - k + l + 1 < ans) ans = m - k + l;
  }
  cout << ans + linf;
}
