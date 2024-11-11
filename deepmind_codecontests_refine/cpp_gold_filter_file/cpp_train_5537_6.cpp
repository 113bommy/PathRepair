#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;
  int nr = n - (a1 * (k1 - 1) + a2 * (k2 - 1));
  if (nr <= 0) nr = 0;
  cout << min(nr, a1 + a2) << ' ';
  int rasp = 0;
  if (k1 < k2) {
    rasp += min(n / k1, a1);
    n -= k1 * rasp;
    rasp += min(n / k2, a2);
  } else {
    rasp += min(n / k2, a2);
    n -= k2 * rasp;
    rasp += min(n / k1, a1);
  }
  cout << rasp;
}
