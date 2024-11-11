#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  if (max(abs(x1 - x2), abs(y1 - y2)) >= 5) {
    cout << "Second";
    return 0;
  }
  int d1 = min(x1, x2), d2 = min(y1, y2);
  x1 -= d1;
  x2 -= d1;
  y1 -= d2;
  y2 -= d2;
  if (max(abs(x1 - x2), abs(y1 - y2)) <= 2) {
    cout << "First";
    return 0;
  }
  if (min(abs(x1 - x2), abs(y1 - y2)) <= 4 &&
      max(abs(x1 - x2), abs(y1 - y2)) == 2) {
    cout << "First";
    return 0;
  }
  if (min(abs(x1 - x2), abs(y1 - y2)) <= 3 &&
      max(abs(x1 - x2), abs(y1 - y2)) == 3) {
    cout << "First";
    return 0;
  }
  if (min(abs(x1 - x2), abs(y1 - y2)) <= 2 &&
      max(abs(x1 - x2), abs(y1 - y2)) == 4) {
    cout << "First";
    return 0;
  }
  cout << "Second";
  return 0;
}
