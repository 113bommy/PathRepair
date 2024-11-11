#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  long long x3, y3, x4, y4;
  cin >> x3 >> y3 >> x4 >> y4;
  long long x5, y5, x6, y6;
  cin >> x5 >> y5 >> x6 >> y6;
  long long altura;
  if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
    cout << "NO" << endl;
    return 0;
  }
  if (x5 <= x1 && y5 <= y1 && x6 >= x2 && y6 >= y2) {
    cout << "NO" << endl;
    return 0;
  }
  if (x3 <= x1 && x4 >= x2 && y4 >= y2) {
    altura = y3;
    if (x5 <= x1 && x6 >= x2 && y1 >= y5 && y6 >= altura) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (x5 <= x1 && x6 >= x2 && y6 >= y2) {
    altura = y5;
    if (x3 <= x1 && x4 >= x2 && y1 >= y3 && y4 >= altura) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (x3 <= x1 && y4 >= y2 && y1 >= y3) {
    altura = x4;
    if (x6 >= x2 && y6 >= y2 && y1 >= y5 && x5 <= altura) {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (x5 <= x1 && y6 >= y2 && y1 >= y5) {
    altura = x6;
    if (x4 >= x2 && y4 >= y2 && y1 >= y3 && x3 <= altura) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
