#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, a, b, x, y, i;
  cin >> n >> a >> x >> b >> y;
  while (a != x || b != y) {
    if (a != x) a++;
    if (b != y) y--;
    if (a > n) a = 1;
    if (b < 1) b = n;
    if (a == b) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
