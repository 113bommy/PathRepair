#include <bits/stdc++.h>
using namespace std;
int n;
double v;
vector<double> a, b;
int main() {
  cin >> n >> v;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  double mx = 1e9;
  for (int i = 0; i < n; i++) {
    mx = min(mx, b[i] / a[i]);
  }
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += mx * a[i];
  }
  printf("%1.10lf", min(ans, v));
}
