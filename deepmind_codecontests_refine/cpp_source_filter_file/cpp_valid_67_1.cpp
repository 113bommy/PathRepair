#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b - a < a) {
      cout << -1 << endl;
      continue;
    }
    int mid = a + (b - a) / 2;
    if (c > mid * 2) {
      cout << -1 << endl;
      continue;
    } else if (c > mid)
      cout << c - mid << endl;
    else
      cout << c + mid << endl;
  }
  return 0;
}
