#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
struct data {
  long a, b, c;
};
bool f(long n, long m) {
  if (n > m) swap(n, m);
  if (n == 1 || n == 2)
    return m < 5;
  else if (n == 3)
    return m <= 4;
  return false;
}
int main() {
  long n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  if ((x1 != x2 && f(x2 - x1, y2 - y1 + 1)) ||
      (y1 != y2 && f(x2 - x1 + 1, y2 - y1)))
    cout << "First";
  else
    cout << "Second";
  return 0;
}
