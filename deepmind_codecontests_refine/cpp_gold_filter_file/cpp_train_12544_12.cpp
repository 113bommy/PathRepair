#include <bits/stdc++.h>
template <class T_>
void f_swap(T_ &a, T_ &b) {
  T_ t = a;
  a = b;
  b = t;
}
const int N = 1e6 + 1;
struct Point {
  int x, y, id;
  void Read() {
    scanf("%d%d", &x, &y);
    x /= 1700;
    y /= 1700;
  }
  bool operator<(const Point &tt) const {
    if (x != tt.x) return x < tt.x;
    if (x & 1)
      return y > tt.y;
    else
      return y < tt.y;
  }
} pt[N];
int n;
void GetData() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    pt[i].id = i;
    pt[i].Read();
  }
}
void Solve() {
  std::sort(pt + 1, pt + 1 + n);
  for (int i = 1; i <= n; ++i) printf("%d ", pt[i].id);
}
int main() {
  GetData();
  Solve();
  return 0;
}
