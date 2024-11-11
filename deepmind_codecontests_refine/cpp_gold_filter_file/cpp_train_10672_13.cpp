#include <bits/stdc++.h>
const int inf = (int)1e9;
using namespace std;
int l[100011], r[100011];
int p;
long double h[100011];
long double f[100011];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n >> p;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    h[i] = r[i] / p - (l[i] - 1) / p;
  }
  h[0] = h[n];
  h[n + 1] = h[1];
  r[n + 1] = r[1];
  l[n + 1] = l[1];
  long double sum = 0;
  for (int i = 1; i <= n; i++) {
    long double length = r[i] - l[i] + 1;
    f[i] = (length - h[i]) / length;
  }
  f[n + 1] = f[1];
  for (int i = 1; i <= n; i++) {
    sum += 1.0 - (f[i] * f[i + 1]);
  }
  cout << fixed << setprecision(6) << sum * 2000;
  return 0;
}
