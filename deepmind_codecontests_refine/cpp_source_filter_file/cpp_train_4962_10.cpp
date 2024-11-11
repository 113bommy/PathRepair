#include <bits/stdc++.h>
using namespace std;
struct Complex {
  double x, y;
  Complex(double xx = 0, double yy = 0) { x = xx, y = yy; }
};
inline Complex operator+(Complex a, Complex b) {
  return Complex(a.x + b.x, a.y + b.y);
}
inline Complex operator-(Complex a, Complex b) {
  return Complex(a.x - b.x, a.y - b.y);
}
inline Complex operator*(Complex a, Complex b) {
  return Complex(a.x * b.x - a.y * b.y, a.y * b.x + b.y * a.x);
}
inline int lowbit(int x) { return x & (-x); }
int n, A, B, C, T;
int cnt1;
long long ans = 0;
int a[1005];
int main() {
  cin >> n >> A >> B >> C >> T;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (-B + C < 0)
      ans = ans + A;
    else {
      ans = ans + (long long)(n - a[i]) * (C - B) + A;
    }
  }
  cout << ans << endl;
}
