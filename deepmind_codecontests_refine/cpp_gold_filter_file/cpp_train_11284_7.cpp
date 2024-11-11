#include <bits/stdc++.h>
using namespace std;
int a[200001], b, c, k, i, j, n, m;
long long sum, d[200001];
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  d[1] = 0;
  b = 2;
  k = n;
  for (i = 2; i <= n; i++) {
    if (sum - 1ll * (b - 1) * (k - b) * a[i] < m) {
      cout << i << endl;
      k--;
    } else {
      sum += 1ll * (b - 1) * a[i];
      b++;
    }
  }
  return 0;
}
