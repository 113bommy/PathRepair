#include <bits/stdc++.h>
using namespace std;
const long long int N = 1000000;
long long int n, m, k, a[N], b[N], c[N], ans = 0;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) cin >> a[i] >> b[i] >> c[i];
  for (int q = 0; q < k; ++q) {
    int d = 0;
    cin >> d;
    for (int i = 0; i < m; ++i)
      if (d >= a[i] && d <= b[i]) ans += (d - a[i]) + c[i];
  }
  cout << ans << endl;
  return 0;
}
