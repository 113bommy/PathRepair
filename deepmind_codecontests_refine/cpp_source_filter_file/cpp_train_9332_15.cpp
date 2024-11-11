#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  vector<long long> a(n), b(m);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < m; i++) {
    cin >> b[i];
  }
  vector<long long> maxs(n);
  for (long long i = 0; i < n; i++) {
    maxs[i] = -1e10;
    for (long long k = 0; k < n; k++) {
      if (k == i) {
        for (long long p = 0; p < m; p++) {
          maxs[i] = max(maxs[i], a[k] * b[p]);
        }
      }
    }
  }
  sort(maxs.begin(), maxs.end());
  cout << maxs[n - 2];
  return 0;
}
