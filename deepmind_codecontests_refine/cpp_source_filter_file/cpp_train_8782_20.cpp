#include <bits/stdc++.h>
using namespace std;
long long n, m, k, i, j, a[100001], b[100001], minx = 1000000000, res;
int main() {
  cin >> m;
  for (i = 1; i <= m; i++) {
    cin >> b[i];
    minx = min(minx, b[i]);
  }
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (i = n; i >= 1; i -= minx + 3) {
    for (j = i; j >= max(i - minx + 1, 1LL); j--) {
      res += a[j];
    }
  }
  cout << res;
}
