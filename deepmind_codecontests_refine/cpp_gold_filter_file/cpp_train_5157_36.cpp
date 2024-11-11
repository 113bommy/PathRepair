#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  cin >> n;
  int dangerous = 0;
  int x1, y1, x2, y2, x3, y3;
  int i = 0;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  while (i < n - 3) {
    if (y1 == y2 && x2 == x3) dangerous++;
    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
    cin >> x3;
    cin >> y3;
    i++;
  }
  cout << dangerous;
  return 0;
}
