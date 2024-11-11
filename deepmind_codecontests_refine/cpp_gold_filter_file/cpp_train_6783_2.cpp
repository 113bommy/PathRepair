#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void _read(T& x) {
  cin >> x;
}
void R() {}
template <typename T, typename... U>
void R(T& head, U&... tail) {
  _read(head);
  R(tail...);
}
template <typename T>
inline void _write(const T& x) {
  cout << x << ' ';
}
void W() { cout << endl; }
template <typename T, typename... U>
void W(const T& head, const U&... tail) {
  _write(head);
  W(tail...);
}
void go();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(15);
  go();
  return 0;
}
const int MAXN = 2e5 + 10;
int a[MAXN];
void go() {
  int n, d;
  R(n, d);
  for (int i = 1; i <= n; i++) {
    R(a[i]);
  }
  int m;
  R(m);
  while (m--) {
    int x;
    R(x);
    int r = lower_bound(a + 1, a + 1 + n, x) - a;
    long double ans;
    if (r == 1) {
      ans = atan2(1, a[r] - x);
    } else if (r == n + 1) {
      ans = atan2(1, x - (a[r - 1] + 1));
    } else {
      int l = r - 1;
      ans = atan2(1, min(a[r] - x, x - (a[l] + 1)));
      for (int i = 1; i <= 3500; i++) {
        int llen = x - (a[l] + 1);
        int rlen = a[r] - x;
        if (abs(llen - rlen) <= 1) {
          ans = max(ans, (long double)2 * atan2(1, max(llen, rlen)));
          break;
        } else if (llen < rlen) {
          if (l-- == 1) {
            break;
          }
        } else {
          if (r++ == n) {
            break;
          }
        }
      }
    }
    W(ans);
  }
}
