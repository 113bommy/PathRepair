#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int KINF = 0x3f3f3f3f;
const double eps = 1e-7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int _;
  cin >> _;
  while (_--) {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = (int)0; i < (int)n; ++i) cin >> a[i];
    int cnt = 1;
    for (int i = (int)0; i < (int)n - 1; ++i)
      if (a[i] != a[i + 1]) cnt++;
    if (k == 1) {
      if (cnt == 1)
        cout << 1 << endl;
      else
        cout << -1 << endl;
    } else
      cout << (cnt - 1 + k - 2) / (k - 1) << endl;
  }
  return 0;
}
