#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long n, m, i;
  cin >> n >> m;
  vector<long long> a(n);
  vector<long long> b(n);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  double f = 0, s = 0;
  f = m + m / 1.0 / (b[0] - 1);
  s += m / 1.0 / (b[0] - 1);
  for (i = n - 1; i > 0; i--) {
    s += f / 1.0 / (a[i] - 1);
    f = f + f / 1.0 / (a[i] - 1);
    s += f / 1.0 / (b[i] - 1);
    f = f + f / 1.0 / (b[i] - 1);
  }
  s += f / 1.0 / (a[0] - 1);
  f = f + f / 1.0 / (a[0] - 1);
  if (s > 1e9)
    cout << -1;
  else
    cout << setprecision(10) << fixed << " " << s;
  return 0;
}
