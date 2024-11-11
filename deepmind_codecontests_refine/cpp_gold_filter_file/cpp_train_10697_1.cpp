#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using l = long;
const ll FINAL_SAFE = 2250000000000LL;
const ll L = 1000000000000LL;
bool safe(ll x1, ll y1, ll x2, ll y2) {
  return (x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2) <= L;
}
bool fsafe(ll x1, ll y1, ll x2, ll y2) {
  return (x1 + x2) * (x1 + x2) + (y1 + y2) * (y1 + y2) <= FINAL_SAFE;
}
int trace(l i, vector<l>& pred, vector<int>& sgn) {
  if (i != pred[i]) {
    sgn[i] = sgn[i] * trace(pred[i], pred, sgn);
    pred[i] = i;
  }
  return sgn[i];
}
int main() {
  l n;
  while (cin >> n) {
    if (n == 1) {
      ll x;
      cin >> x >> x;
      cout << 1 << endl;
    } else if (n == 2) {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (safe(x1, y1, x2, y2))
        cout << 1 << " " << 1 << endl;
      else
        cout << 1 << " " << -1 << endl;
    } else {
      vector<l> pred(2 * n);
      vector<int> sgn(2 * n);
      l next = n - 1;
      l it = 3;
      ll x1, y1, x2, y2, x3, y3;
      l i1, i2, i3;
      cin >> x1 >> y1;
      cin >> x2 >> y2;
      i1 = 0;
      i2 = 1;
      i3 = 2;
      while (cin >> x3 >> y3) {
        if (safe(x1, y1, x2, y2)) {
          sgn[i1] = 1;
          sgn[i2] = 1;
          pred[i1] = pred[i2] = ++next;
          i1 = next;
          x1 = x1 + x2;
          y1 = y1 + y2;
          i2 = i3;
          x2 = x3;
          y2 = y3;
          i3 = it++;
        } else if (safe(x1, y1, -x2, -y2)) {
          sgn[i1] = 1;
          sgn[i2] = -1;
          pred[i1] = pred[i2] = ++next;
          i1 = next;
          x1 = x1 - x2;
          y1 = y1 - y2;
          i2 = i3;
          x2 = x3;
          y2 = y3;
          i3 = it++;
        } else if (safe(x1, y1, x3, y3)) {
          sgn[i1] = 1;
          sgn[i3] = 1;
          pred[i1] = pred[i3] = ++next;
          i1 = next;
          x1 = x1 + x3;
          y1 = y1 + y3;
          i2 = i2;
          x2 = x2;
          y2 = y2;
          i3 = it++;
        } else if (safe(x1, y1, -x3, -y3)) {
          sgn[i1] = 1;
          sgn[i3] = -1;
          pred[i1] = pred[i3] = ++next;
          i1 = next;
          x1 = x1 - x3;
          y1 = y1 - y3;
          i2 = i2;
          x2 = x2;
          y2 = y2;
          i3 = it++;
        } else if (safe(x2, y2, x3, y3)) {
          sgn[i2] = 1;
          sgn[i3] = 1;
          pred[i2] = pred[i3] = ++next;
          ll temp_x = x2 + x3;
          ll temp_y = y2 + y3;
          i2 = i1;
          x2 = x1;
          y2 = y1;
          i1 = next;
          x1 = temp_x;
          y1 = temp_y;
          i3 = it++;
        } else if (safe(x2, y2, -x3, -y3)) {
          sgn[i2] = 1;
          sgn[i3] = -1;
          pred[i2] = pred[i3] = ++next;
          ll temp_x = x2 - x3;
          ll temp_y = y2 - y3;
          i2 = i1;
          x2 = x1;
          y2 = y1;
          i1 = next;
          x1 = temp_x;
          y1 = temp_y;
          i3 = it++;
        } else
          cout << "never safe pre" << endl;
      }
      if (fsafe(x1, y1, x2, y2)) {
        sgn[i1] = 1;
        sgn[i2] = 1;
      } else if (fsafe(x1, y1, -x2, -y2)) {
        sgn[i1] = 1;
        sgn[i2] = -1;
      } else
        cout << "never safe" << endl;
      pred[i1] = i1;
      pred[i2] = i2;
      for (l i = 0; i < n; ++i) {
        trace(i, pred, sgn);
        cout << sgn[i] << (i != n - 1 ? " " : "");
      }
      cout << endl;
    }
  }
}
