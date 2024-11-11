#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, max;
  cin >> x >> y;
  if (x <= y)
    max = x;
  else
    max = y;
  cout << max << " " << abs(x - y) / 2;
}
