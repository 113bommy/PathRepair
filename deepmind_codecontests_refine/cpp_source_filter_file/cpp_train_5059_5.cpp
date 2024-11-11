#include <bits/stdc++.h>
using namespace std;
int n, a[25], p, x, y, b[20000], mi = 1000000;
vector<int> v;
bool check(int n) {
  int d = n;
  n = (d / 50) % 475;
  for (int i = 1; i <= 25; i++) {
    n = (n * 96 + 42) % 475;
    if (n + 26 == p) return 0;
  }
  return 1;
}
int main() {
  cin >> p >> y >> x;
  int s = 0;
  for (int i = y; i >= x; i -= 50) {
    if (check(i) == 0) {
      mi = 0;
      break;
    }
  }
  if (mi == 0) {
    cout << mi;
    return 0;
  }
  int i = y + 1;
  while (true) {
    if (check(i) == 0) {
      s = 0;
      s = i - y;
      s = s + 50;
      s /= 100;
      if (s < mi) mi = s;
      break;
    }
    i += 50;
  }
  cout << mi;
  return 0;
}
