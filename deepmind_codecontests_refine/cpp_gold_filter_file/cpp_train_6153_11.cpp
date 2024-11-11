#include <bits/stdc++.h>
using namespace std;
struct coordinate {
  float x;
  float y;
};
float check1(coordinate c1, coordinate c2, coordinate c3, coordinate c4,
             coordinate x1) {
  float ans1 = (x1.y - c1.y) + (x1.x - c1.x);
  float ans2 = (x1.y - c3.y) + (x1.x - c3.x);
  if (ans1 == 0 || ans2 == 0)
    return 0;
  else {
    float ans = ans1 / ans2;
    return ans;
  }
}
float check2(coordinate c1, coordinate c2, coordinate c3, coordinate c4,
             coordinate x1) {
  float m = (c3.y - c1.y) / (c3.x - c1.x);
  float ans1 = (x1.y - c1.y) - m * (x1.x - c1.x);
  float ans2 = (x1.y - c2.y) - m * (x1.x - c2.x);
  if (ans1 == 0 || ans2 == 0)
    return 0;
  else {
    float ans = ans1 / ans2;
    return ans;
  }
}
int main() {
  float n, d;
  cin >> n >> d;
  coordinate c1, c2, c3, c4;
  c1.x = d;
  c1.y = 0;
  c2.x = 0;
  c2.y = d;
  c3.x = n;
  c3.y = n - d;
  c4.x = n - d;
  c4.y = n;
  int t;
  cin >> t;
  while (t--) {
    coordinate x1;
    cin >> x1.x >> x1.y;
    float ans1 = check1(c1, c2, c3, c4, x1);
    float ans2 = check2(c1, c2, c3, c4, x1);
    if (ans1 < 0 && ans2 < 0)
      cout << "YES" << endl;
    else if (ans1 == 0 || ans2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
