#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1;
  cin >> x1 >> y1;
  int x2, y2;
  cin >> x2 >> y2;
  int cnt = 0;
  int a = abs(x2 - x1);
  int b = abs(y2 - y1);
  cnt += a + abs(b - a);
  cout << cnt << "\n";
  return 0;
}
