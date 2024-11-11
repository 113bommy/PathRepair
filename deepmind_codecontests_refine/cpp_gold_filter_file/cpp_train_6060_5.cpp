#include <bits/stdc++.h>
using namespace std;
int a1, b1, c1, a2, b2, c2;
int d1, d2, d3, d4, d5, d6, d7;
int f1, f2, f3, f4, f5, f6, f7;
bool check() {
  return f1 <= d1 && f2 <= d2 && f3 <= d3 && f4 <= d4 && f5 <= d5 && f6 <= d6 &&
         f7 <= d7 && (f1 + f2 + f3 + f4 <= a1) && (f1 + f2 + f5 + f6 <= b1) &&
         (f1 + f3 + f5 + f7 <= c1) &&
         (f1 + f2 + f3 + f4 >= d1 + d2 + d3 + d4 - a2) &&
         (f1 + f2 + f5 + f6 >= d1 + d2 + d5 + d6 - b2) &&
         (f1 + f3 + f5 + f7 >= d1 + d3 + d5 + d7 - c2);
}
void solve() {
  cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
  cin >> d1 >> d2 >> d3 >> d4 >> d5 >> d6 >> d7;
  if (d1 + d2 + d3 + d4 > a1 + a2 || d1 + d2 + d5 + d6 > b1 + b2 ||
      d1 + d3 + d5 + d7 > c1 + c2) {
    cout << "-1\n";
    return;
  }
  int t = d2 + d3 + d5;
  for (int A = 0; A <= a1; ++A) {
    for (int B = 0; B <= t; ++B) {
      int lf3 = max({0, A + B - b1});
      int rf3 = min({d3, A + B + b2 - d1 - d2 - d5});
      int lf5 = max({0, A + B - a1});
      int rf5 = min({d5, A + B + a2 - d1 - d2 - d3});
      int lf3f5 = max({0, B - d2, d1 + d3 + d5 - A - c2});
      int rf3f5 = min({d3 + d5, c1 - A, B});
      if (rf3 < lf3 || rf5 < lf5 || rf3f5 < lf3f5) continue;
      f3 = lf3;
      f5 = lf5;
      if (f3 + f5 > rf3f5) continue;
      if (f3 + f5 < lf3f5) {
        int tmp;
        int delta = lf3f5 - (f3 + f5);
        tmp = min(delta, rf3 - f3);
        f3 += tmp;
        delta -= tmp;
        tmp = min(delta, rf5 - f5);
        f5 += tmp;
        delta -= tmp;
        if (delta > 0) continue;
      }
      f1 = A;
      f2 = B - f3 - f5;
      f4 = max(0, d1 + d2 + d3 + d4 - a2 - A - B + f5);
      f6 = max(0, d1 + d2 + d5 + d6 - b2 - A - B + f3);
      f7 = max(0, d1 + d3 + d5 + d7 - c2 - A - B + f2);
      if (check()) {
        cout << f1 << " " << f2 << " " << f3 << " " << f4 << " " << f5 << " "
             << f6 << " " << f7 << '\n';
        return;
      }
    }
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
