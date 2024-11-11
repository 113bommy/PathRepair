#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, k, l, a[200007], b[200007], p[400007], c[400007], cnt,
    MAX = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> m >> n;
  for (i = 0; i < m; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n - 1; i++) c[i] = b[i + 1] - b[i];
  c[n - 1] = MAX;
  for (i = n, j = 0; j < m - 1; j++) c[i + j] = a[j + 1] - a[j];
  for (i = 1, j = 0; i < n + m - 1; i++) {
    while (j > 0 && c[i] != c[j]) j = p[j - 1];
    if (c[i] == c[j]) j++;
    p[i] = j;
    if (i > n && p[i] == n - 1) cnt++;
  }
  cout << (n == 1 ? m : cnt);
}
