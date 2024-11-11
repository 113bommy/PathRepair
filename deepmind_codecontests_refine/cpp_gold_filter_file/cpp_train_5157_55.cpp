#include <bits/stdc++.h>
using namespace std;
struct vec {
  int x;
  int y;
  vec() {}
  vec(const int &x, const int &y) : x(x), y(y) {}
  void read() { scanf("%d %d", &x, &y); }
  vec operator-(const vec &right) const { return {x - right.x, y - right.y}; }
};
long long cross_product(const vec &left, const vec &right) {
  return 1LL * left.x * right.y - 1LL * left.y * right.x;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<vec> pts(n);
  for (int i = 0; i < n; ++i) pts[i].read();
  int f1 = 0, f2 = 0;
  for (int i = 0; i < n; ++i) {
    long long cp = cross_product(pts[(i + 1) % n] - pts[i],
                                 pts[(i + 1) % n] - pts[(i + 2) % n]);
    if (cp < 0)
      f1++;
    else if (cp > 0)
      f2++;
  }
  printf("%d", f1);
  return 0;
}
