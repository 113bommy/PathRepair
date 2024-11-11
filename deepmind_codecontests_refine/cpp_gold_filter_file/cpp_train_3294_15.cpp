#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int z = 0; z < t; z++) {
    int n, k, f, l, m = -10000;
    cin >> n >> k;
    int a[k];
    for (long long int i = 0; i < k; i++) cin >> a[i];
    if (n == k)
      cout << 1 << endl;
    else {
      f = a[0];
      l = n - a[k - 1] + 1;
      for (int i = 1; i < k; i++) {
        if (a[i] - a[i - 1] > m) m = a[i] - a[i - 1];
      }
      m = ceil(m / 2) + 1;
      cout << max(m, max(f, l)) << endl;
      ;
    }
  }
  return 0;
}
