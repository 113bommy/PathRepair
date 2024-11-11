#include <bits/stdc++.h>
using namespace std;
struct classcomp {
  bool operator()(const int& lhs, const int& rhs) const { return lhs < rhs; }
};
int main() {
  int n, m;
  cin >> n >> m;
  if (m == 3) {
    if (n >= 5) {
      cout << "-1" << endl;
      return 0;
    }
    if (n == 4) {
      cout << "0 0" << endl;
      cout << "3 0" << endl;
      cout << "0 3" << endl;
      cout << "1 1" << endl;
      return 0;
    } else {
      cout << "0 0" << endl;
      cout << "3 0" << endl;
      cout << "0 3" << endl;
      return 0;
    }
  }
  int j = 0;
  double r = 10000000;
  double x = 0, y = 0;
  while (true) {
    for (int i = 0; i < m; i++, j++) {
      if (j >= n) return 0;
      printf(
          "%d %d\n",
          (int)(r * cos(2 * 3.1415926535897932384626433832795 * (i + x) / m)),
          (int)(r * sin(2 * 3.1415926535897932384626433832795 * (x + i) / m)));
    }
    r = r - 50000;
    x += 2;
  }
  return 0;
}
