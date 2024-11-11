#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, x, b, y;
  cin >> n >> a >> x >> b >> y;
  int l1, l2;
  l1 = x - a;
  l2 = b - y;
  if (l1 < 0) l1 = l1 + n;
  if (l2 < 0) l2 = l2 + n;
  int k;
  k = l1 > l2 ? l2 : l1;
  int z = 1;
  for (int i = 0; i < k; i++) {
    if (a == b) {
      cout << "YES";
      z = 0;
    } else {
      a++;
      b--;
      if (a > n) a = a % n;
      if (b == 0) b = b + n;
      if (a == b) {
        cout << "YES";
        z = 0;
        break;
      }
    }
  }
  if (z == 1) cout << "NO";
}
