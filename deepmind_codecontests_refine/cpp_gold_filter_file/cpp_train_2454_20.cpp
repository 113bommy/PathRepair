#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, count = 0;
  cin >> a >> b >> c;
  while (a > 0) {
    if (b >= 2 * a && c >= 4 * a) {
      count = a + 2 * a + 4 * a;
      break;
    }
    a--;
  }
  cout << count;
  return 0;
}
