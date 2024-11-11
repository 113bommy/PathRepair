#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  float a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  float sum = 0.000000;
  float deno = (float)n - k + 1;
  int xx = n - k + 1;
  if (k <= n / 2) {
    for (int i = k - 1; i <= n - k; i++) sum += (k)*a[i];
    for (int i = 0; i <= k - 2; i++) sum += (i + 1) * (a[i] + a[n - i - 1]);
    cout << fixed << setprecision(10) << sum / deno;
  } else {
    for (int i = xx - 1; i <= n - xx; i++) sum += (xx)*a[i];
    for (int i = 0; i <= xx - 2; i++) sum += (i + 1) * (a[i] + a[n - i - 1]);
    cout << fixed << setprecision(10) << sum / deno;
  }
  return 0;
}
