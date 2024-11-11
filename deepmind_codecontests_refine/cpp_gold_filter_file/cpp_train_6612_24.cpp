#include <bits/stdc++.h>
using namespace std;
int x1, x2, y11, y2;
int main() {
  cin >> x1 >> y11 >> x2 >> y2;
  int l = abs(x1 - x2);
  int r = abs(y11 - y2);
  cout << max(l, r);
}
