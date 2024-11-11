#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int l, r;
  cin >> l >> r;
  if (l == r) {
    cout << l;
    return 0;
  }
  int d = r - l, max = 0, n = 2, a;
  while (1) {
    if (d / n > max) {
      max = d / n;
      a = n;
      if (l % n == 0 || r % n == 0) max++;
    }
    n++;
    if (n == 12) break;
  }
  cout << a;
}
