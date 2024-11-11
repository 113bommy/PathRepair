#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  double a[n], b[n], s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  double mn = 99999999;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mn = min(mn, b[i] / a[i]);
  }
  printf("%0.1lf\n", min(mn * s, double(m)));
  return 0;
}
