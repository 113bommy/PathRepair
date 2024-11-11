#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long i, j, k, n, m, t;
  cin >> n;
  long long a[2 * n];
  for (i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  long long temp1 = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  long long x1 = a[0], x2 = a[2 * n - 1];
  long long y1 = 1, y2 = n;
  while (y2 < 2 * n - 1) {
    temp1 = min(temp1, (x2 - x1) * (a[y2] - a[y1]));
    x2++;
    y2++;
  }
  cout << temp1;
  return 0;
}
