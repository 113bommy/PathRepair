#include <bits/stdc++.h>
using namespace std;
const int MAX = 5 * 10000;
const int MOD = 1e9 + 23;
const double PI = 3.1415926535;
double dist1(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
  int r, c, f, n;
  cin >> r >> c >> f >> n;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    s.insert(pair<int, int>(x, y));
  }
  int res = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = i; j <= r; j++) {
      for (int k = 1; k <= c; k++) {
        for (int l = k; l <= c; l++) {
          int count = 0;
          for (auto it = s.begin(); it != s.end(); it++) {
            if (it->first <= j && it->first >= i && it->second <= l &&
                it->second >= k)
              count++;
          }
          if (count >= f) res++;
        }
      }
    }
  }
  cout << res;
  return 0;
}
