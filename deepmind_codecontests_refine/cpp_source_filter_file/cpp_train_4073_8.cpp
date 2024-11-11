#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, ans;
  cin >> n >> m >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n - 1, q = 0, md;
  while (l < r) {
    md = (l + r) / 2;
    int sm = 0, p = 1, fl = 0;
    for (int i = md + 1; i < n; i++) {
      if (sm + a[i] > k) {
        sm = 0;
        p++;
      }
      sm += a[i];
      if (p > m) {
        fl = 1;
        break;
      }
    }
    if (fl)
      l = md + 1;
    else {
      ans = md;
      r = md - 1;
    }
  }
  cout << n - ans - 1 << endl;
  return 0;
}
