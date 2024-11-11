#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  long long y = n, x = 0, c = 0, py = n;
  while (x != n) {
    py = y;
    x++;
    while (y * y + x * x > n * n) y--;
    c += max((long long)1, py - y);
  }
  cout << 4 * c << endl;
}
