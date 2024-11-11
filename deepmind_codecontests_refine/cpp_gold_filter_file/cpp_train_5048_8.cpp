#include <bits/stdc++.h>
using namespace std;
const int N = 2000, M = 1e5;
pair<int, int> a[N];
int k, n, m[400 * M + 1], v[N], h, zz;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < n; ++i) {
    k = 0;
    for (int j = i + 1; j < n; ++j) {
      int A = a[j].first - a[i].first;
      int B = a[j].second - a[i].second;
      if (!B)
        h = 4000001;
      else
        h = A * M / B + 200 * M;
      if (!m[h]) {
        v[k] = h;
        ++k;
      }
      zz += m[h];
      ++m[h];
    }
    for (int j = 0; j < k; ++j) m[v[j]] = 0;
  }
  cout << n * 1ll * (n - 1) * (n - 2) / 6 - zz;
}
