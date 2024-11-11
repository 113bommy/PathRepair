#include <bits/stdc++.h>
const int inf = INT_MAX;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 111;
using namespace std;
int n, m, c1, c2, v, a[2 * maxn], b[2 * maxn], q;
int main() {
  cin >> n >> m >> c1 >> c2 >> v;
  for (int i = 1; i <= c1; i++) cin >> a[i];
  for (int i = 1; i <= c2; i++) cin >> b[i];
  a[0] = 1e8 * (-1) - 100;
  a[c1 + 1] = 1e8 + 100;
  b[0] = 1e8 * (-1) - 100;
  b[c2 + 1] = 1e8 + 100;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2, i = -1, j = -1, l = 1, r = c1, c = 1e8 + 100,
                        d = 1e8 + 100;
    cin >> x1 >> y1 >> x2 >> y2;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (a[mid] < min(y1, y2))
        l = mid + 1;
      else if (a[mid] > max(y1, y2))
        r = mid - 1;
      else {
        i = mid;
        break;
      }
    }
    if (i == -1) i = (int)(lower_bound(a, a + c1 + 2, min(y1, y2)) - a);
    l = 1, r = c2;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (b[mid] < min(y1, y2))
        l = mid + 1;
      else if (b[mid] > max(y1, y2))
        r = mid - 1;
      else {
        j = mid;
        break;
      }
    }
    if (j == -1) j = (int)(lower_bound(b, b + c2 + 2, min(y1, y2)) - b);
    if (i == c1 + 1) i--;
    if (j == c2 + 1) j--;
    if (i - 1 >= 0) d = a[i - 1];
    if (j - 1 >= 0) c = b[j - 1];
    int k = a[i];
    int h = b[j];
    int b = abs(x2 - x1) / v;
    if (abs(x2 - x1) % v != 0) b++;
    if (x1 == x2)
      cout << abs(y2 - y1) << endl;
    else {
      int x = abs(y1 - k) + abs(y2 - k) + abs(x2 - x1);
      int y = abs(y1 - h) + abs(y2 - h) + b;
      int g = abs(y1 - d) + abs(y2 - d) + abs(x2 - x1);
      int first = abs(y1 - c) + abs(y2 - c) + b;
      if (i == 0)
        cout << min(y, first) << endl;
      else if (j == 0)
        cout << min(x, g) << endl;
      else
        cout << min(min(y, first), min(x, g)) << endl;
    }
  }
}
