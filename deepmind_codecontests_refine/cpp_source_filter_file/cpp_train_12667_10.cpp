#include <bits/stdc++.h>
using namespace std;
int q[107], l, r, x, y, a, b, tmp, top, cnt, res = 1, i, j;
bool check(int x) { return x >= l && x <= r; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> l >> r >> x >> y;
  if (y % x)
    cout << 0 << endl;
  else {
    for (tmp = (y /= x), i = 2; i * i <= y; ++i)
      if (y % i == 0) {
        q[++top] = 1;
        while (y % i == 0) y /= i, q[top] *= i;
      }
    if (y != 1) q[++top] = y;
    for (i = 0; i < (1 << top); ++i) {
      for (res = 1, j = 1; j <= top; ++j)
        if ((1 << j - 1) & i) res *= q[j];
      a = res * x;
      b = tmp / res * x;
      if (check(x) && check(b)) cnt++;
    }
    cout << cnt << endl;
  }
  return 0;
}
