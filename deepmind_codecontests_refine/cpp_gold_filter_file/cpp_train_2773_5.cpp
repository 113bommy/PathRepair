#include <bits/stdc++.h>
using namespace std;
bool isLucky(int h, int m) {
  if (h % 10 == 7 || h % 100 == 7 || m % 10 == 7 || m % 100 == 7) return true;
  return false;
}
int main() {
  int x, h, m;
  cin >> x >> h >> m;
  int i = 1;
  while (!isLucky(h, m)) {
    if (h == 0 && x > m) {
      h = 23;
      m = 60 - x + m;
    } else if (x > m) {
      h--;
      m = m + 60 - x;
    } else
      m -= x;
    i++;
  }
  cout << --i << endl;
  return 0;
}
