#include <bits/stdc++.h>
using namespace std;
const int inf = 10e8;
int otv(int a, int b, int c) { return max(0, a - b * c); }
int main() {
  int n, c, d, x = 0, point1 = 0, point2 = 0;
  cin >> n >> c;
  vector<int> p(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  for (int i = 0; i < p.size(); i++) {
    x += t[i];
    point1 += otv(p[i], c, x);
  }
  x = 0;
  for (int i = n - 1; i >= 0; i--) {
    x += t[i];
    point1 += otv(p[i], c, x);
  }
  if (point1 > point2) {
    cout << "Limak";
  } else if (point1 < point2) {
    cout << "Radewoosh";
  } else {
    cout << "Tie";
  }
  return 0;
}
