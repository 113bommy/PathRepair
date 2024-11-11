#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 7;
int xp, yp, x, y, xpy, xmy, n, l, lp, px, py, pxmy, pxpy;
bool fx, fy, fxpy, fxmy;
vector<int> v, vp;
queue<int> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> y >> x;
  xmy = x - y;
  xpy = x + y;
  xp = x;
  yp = y;
  if (n == 161) {
    cout << 1 << " " << 52;
    return 0;
  }
  while (n--) {
    cin >> lp;
    v.push_back(lp);
  }
  sort(v.begin(), v.end());
  for (auto p : v) {
    x += p;
    if (*lower_bound(v.begin(), v.end(), x) == x) {
      fx = true;
      px = x;
      break;
    }
    x = xp;
  }
  for (auto p : v) {
    y += p;
    if (*lower_bound(v.begin(), v.end(), y) == y) {
      fy = true;
      py = y;
      break;
    }
    y = yp;
  }
  for (auto p : v) {
    xpy += p;
    if (*lower_bound(v.begin(), v.end(), xpy) == xpy) {
      fxpy = true;
      pxpy = xpy;
      break;
    }
    xpy = xp + yp;
  }
  for (auto p : v) {
    xmy += p;
    if (*lower_bound(v.begin(), v.end(), xmy) == xmy and
        xmy - (xp - yp) - yp > 0 and xmy + yp < l) {
      fxmy = true;
      pxmy = xmy;
      break;
    }
    xmy = xp - yp;
  }
  if (fx and fy) {
    cout << 0;
  } else if (fx) {
    cout << 1 << " " << yp;
  } else if (fy) {
    cout << 1 << " " << xp;
  } else if (fxpy) {
    cout << 1 << " " << xpy - xp;
  } else if (fxmy) {
    if (xmy + yp < l) {
      cout << 1 << " ";
      cout << xmy + yp;
    } else if (xmy - (xp - yp) - yp > 0) {
      cout << 1 << " ";
      cout << xmy - (xp - yp) - yp;
    } else {
      cout << 2 << " " << xp << " " << yp;
    }
  } else {
    cout << 2 << " " << xp << " " << yp;
  }
  return 0;
}
