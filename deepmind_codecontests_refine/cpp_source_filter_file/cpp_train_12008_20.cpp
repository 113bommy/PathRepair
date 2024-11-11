#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M, x1, x2, y1, y2;
  cin >> N >> M >> x1 >> y1 >> x2 >> y2;
  int a = abs(x1 - x2);
  int b = abs(y1 - y2);
  if (a > 5 || b > 5 || a + b > 6)
    cout << "Second" << endl;
  else
    cout << "First" << endl;
  return 0;
}
