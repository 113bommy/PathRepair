#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k1, k2;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k1 >> k2;
    int a, b, ma = 0, mb = 0;
    for (int j = 0; j < k1; j++) {
      cin >> a;
      ma = max(a, ma);
    }
    for (int j = 0; j < k2; j++) {
      cin >> b;
      mb = max(b, ma);
    }
    if (ma > mb)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
