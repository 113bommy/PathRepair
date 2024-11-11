#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<long long> w(n, -1), k(m, -1);
  vector<long long> ile_w(n, 0), ile_k(m, 0);
  double puste = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == '.') {
        ++puste;
        ++ile_w[i];
        ++ile_k[j];
      } else {
        w[i] = j;
        k[j] = i;
      }
    }
  }
  long long odp = 0;
  for (long long i = 0; i < n; ++i)
    for (long long j = 0; j < i; ++j) odp += ile_w[i] * ile_w[j] * (i - j);
  for (long long i = 0; i < m; ++i)
    for (long long j = 0; j < i; ++j) odp += ile_k[i] * ile_k[j] * (i - j);
  odp *= 2;
  long long dod = 0;
  for (int i = 0; i < n; ++i)
    if (w[i] != -1)
      for (int j = i + 1; j < n && w[j] > w[j - 1] && w[j] != -1; ++j)
        dod += w[i] * (m - w[j] - 1);
  for (int i = 0; i < n; ++i)
    if (w[i] != -1)
      for (int j = i + 1; j < n && w[j] < w[j - 1] && w[j] != -1; ++j)
        dod += (m - w[i] - 1) * w[j];
  for (int i = 0; i < m; ++i)
    if (k[i] != -1)
      for (int j = i + 1; j < m && k[j] > k[j - 1] && k[j] != -1; ++j)
        dod += k[i] * (n - k[j] - 1);
  for (int i = 0; i < m; ++i)
    if (k[i] != -1)
      for (int j = i + 1; j < m && k[j] < k[j - 1] && k[j] != -1; ++j)
        dod += (n - k[i] - 1) * k[j];
  for (int i = 0; i < n; ++i)
    if (w[i] != -1) dod += w[i] * (n - w[i] - 1);
  for (int i = 0; i < m; ++i)
    if (k[i] != -1) dod += k[i] * (m - k[i] - 1);
  dod *= 2;
  odp += 2 * dod;
  cout << fixed << setprecision(6);
  cout << (double)odp / puste / puste;
  return 0;
}
