#include <bits/stdc++.h>
using namespace std;
int sum[100005];
int main() {
  int h1, h2, a, b, k, x;
  cin >> h1 >> h2 >> a >> b;
  int num = h1 + a * 8;
  if (num > h2)
    x = 0;
  else if (a <= b)
    x = -1;
  else {
    x = 1;
    num -= b * 12;
    for (int i = 1;; i++) {
      num += a * 12;
      if (num > h2)
        break;
      else {
        x++;
        num -= b * 12;
      }
    }
  }
  cout << x << endl;
  return 0;
}
