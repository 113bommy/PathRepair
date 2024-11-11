#include <bits/stdc++.h>
using namespace std;
const int imax = INT_MAX;
const long long lmax = LONG_LONG_MAX;
int a[100050], b[100050];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m, y0, y1;
  cin >> n >> m >> y0 >> y1;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  int d = 0, p = 0, l = -1;
  for (int i = 0; i < n; i++) {
    while (d < m && abs(a[i] - b[d + 1]) < abs(a[i] - b[d])) d++;
    if (l < d || abs(a[i - 1] - b[d]) == abs(a[i] - b[d])) {
      p++;
      l = d;
    } else if (d < m && abs(a[i] - b[d + 1]) == abs(a[i] - b[d])) {
      p++;
      l = d++;
    } else
      l = d;
  }
  cout << n - p << endl;
  return 0;
}
