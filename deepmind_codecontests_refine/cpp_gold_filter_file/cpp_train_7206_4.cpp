#include <bits/stdc++.h>
using namespace std;
int find_area(int a, int b, int x, int y) {
  int s1 = max(x, abs(x - a + 1));
  int s2 = max(y, abs(y - b + 1));
  if (s1 * b > s2 * a) {
    return s1 * b;
  } else {
    return s2 * a;
  }
}
int main() {
  int t;
  cin >> t;
  while ((t--) > 0) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int area = find_area(a, b, x, y);
    cout << area << endl;
  }
  return 0;
}
