#include <bits/stdc++.h>
using namespace std;
int a[100002], n, m;
int main() {
  int v = 0, x, p, op, i;
  cin >> n >> m;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= m; i++) {
    cin >> op;
    if (op == 1) {
      cin >> p >> x;
      a[p] = x - v;
    } else if (op == 2) {
      cin >> x;
      v += x;
    } else {
      cin >> p;
      cout << (a[p] + v) << "\n";
    }
  }
  return 0;
}
