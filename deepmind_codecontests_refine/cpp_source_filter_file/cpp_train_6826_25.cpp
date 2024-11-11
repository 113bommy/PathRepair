#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  string Leader, Handle;
  int x, y, a, b, c, d, e, p = 0, point = 0;
  cin >> Handle >> x >> y >> a >> b >> c >> d >> e;
  Leader = Handle;
  p += 50 * x - 50 * y + a + b + c + d + e;
  point = p;
  for (int i = 1; i < n; i++) {
    p = 0;
    cin >> Handle >> x >> y >> a >> b >> c >> d >> e;
    p += 50 * x - 50 * y + a + b + c + d + e;
    if (p > point) {
      point = p;
      Leader = Handle;
    }
  }
  cout << Leader;
}
