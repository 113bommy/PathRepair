#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int p, n, j, i, k = 0, t = 0, l, h, mid, u = 0, v = 0,
                            cnt[26] = {0}, T, f = 0, q, r, x, y, a, b, c, d;
  cin >> a >> b >> c >> d;
  x = max((3 * a) / 10, a - ((a / 250) * c));
  y = max((3 * b) / 10, b - ((b / 250) * d));
  if (x > y) {
    cout << "Misha";
  }
  if (x < y) {
    cout << "Vasya";
  }
  if (x == y) {
    cout << "Tie";
  }
}
