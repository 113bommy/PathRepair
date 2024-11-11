#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long k, r, c, i, mid;
  cin >> k;
  i = sqrt(k);
  mid = (i * i) + i + 1;
  if (i * i == k) {
    c = 1;
    r = i;
  } else if (k <= mid) {
    c = i + 1;
    r = k - (i * i);
  } else {
    r = i + 1;
    c = (i + 1) * (i + 1) - k + 1;
  }
  cout << r << " " << c << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
