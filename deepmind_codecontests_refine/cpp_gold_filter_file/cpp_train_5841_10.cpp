#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, y1, x2, y2, x3, y3;
  std::cin >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if ((x2 < x1 && y2 < y1 && x3 < x1 && y3 < y1) ||
      (x2 < x1 && y2 > y1 && x3 < x1 && y3 > y1) ||
      (x2 > x1 && y2 < y1 && x3 > x1 && y3 < y1) ||
      (x2 > x1 && y2 > y1 && x3 > x1 && y3 > y1))
    std::cout << "YES";
  else
    std::cout << "NO";
  return 0;
}
