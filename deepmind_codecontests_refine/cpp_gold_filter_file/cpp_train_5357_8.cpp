#include <bits/stdc++.h>
using namespace std;
const int oo = 2e6 + 1001;
const int N = 2e5 + 1001;
const int M = 2010;
int main() {
  int a[M], b[M], p, q, l, r;
  cin >> p >> q >> l >> r;
  set<int> ans;
  for (int i = 0; i < p; i++) cin >> a[i] >> b[i];
  int c, d;
  while (q--) {
    cin >> c >> d;
    for (int i = 0; i < p; i++) {
      int mi = a[i] - d, ma = b[i] - c;
      if (ma < l || mi > r) continue;
      int start = max(l, mi), end = min(r, ma);
      for (int i = start; i <= end; i++) ans.insert(i);
    }
  }
  cout << ans.size();
  return 0;
}
