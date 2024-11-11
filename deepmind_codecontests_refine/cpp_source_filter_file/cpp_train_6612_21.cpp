#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, x1, y1;
  cin >> x >> y >> x1 >> y1;
  cout << max(abs(x1 - x), abs(y1 - y));
}
