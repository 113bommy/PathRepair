#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  int a, mn = 1001, mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a;
    mn = min(mn, a);
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    mx = max(mx, a);
  }
  if (mx <= mn) {
    cout << r << endl;
  } else {
    cout << mx * (r / mn) + r % mn << endl;
  }
}
