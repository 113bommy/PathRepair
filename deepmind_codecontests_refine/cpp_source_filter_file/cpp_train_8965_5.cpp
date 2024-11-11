#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 100;
int T, n, m;
int main() {
  cin >> n;
  int i;
  int l1, r1, l2, r2;
  for (i = 0; i < n; i++) {
    cin >> l1 >> r1 >> l2 >> r2;
    if (r1 == r2) {
      cout << r1 << " " << r2 << endl;
    } else {
      cout << r1 << " " << l2 << endl;
    }
  }
  return 0;
}
