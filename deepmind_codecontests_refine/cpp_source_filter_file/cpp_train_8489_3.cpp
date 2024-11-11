#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  int i;
  int x = (int)((n * t) / 100);
  for (i = 0; i < x; i++) {
    cout << k << " ";
  }
  float s = ((n * t) / 100.0) - ((int)((n * t) / 100.0));
  if (i < n) {
    if (fabs(s * k - ceil(s * k)) > 1e-10)
      cout << floor(s * k) << " ";
    else
      cout << ceil(s * k) << " ";
  }
  for (; i < n - 1; i++) cout << 0 << " ";
  return 0;
}
