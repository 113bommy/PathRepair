#include <bits/stdc++.h>
using namespace std;
const double zero = 1e-8;
double xv, yv, xp, yp, xw1, yw1, xw2, yw2, xm1, ym1, xm2, ym2;
double min(double a, double b) {
  if (a < b)
    return (a);
  else
    return (b);
}
double max(double a, double b) {
  if (a > b)
    return (a);
  else
    return (b);
}
bool precheck() {
  double k, b, k2, b2, x, y;
  if (xm1 == xm2) {
    if (xv == xp)
      if (max(yv, yp) < min(ym1, ym2) || min(yv, yp) > max(ym1, ym2))
        return (true);
      else
        return (false);
    else {
      k = (yv - yp) / (xv - xp);
      b = yv - k * xv;
      y = k * xm1 + b;
      if (y >= min(ym1, ym2) && y <= max(ym1, ym2))
        return (false);
      else
        return (true);
    }
  } else {
    k = (ym1 - ym2) / (xm1 - xm2);
    b = ym1 - k * xm1;
    if (xv == xp) {
      y = k * xv + b;
      if (y >= min(yv, yp) && y <= max(yv, yp))
        return (false);
      else
        return (true);
    } else {
      k2 = (yv - yp) / (xv - xp);
      b2 = yv - k2 * xv;
      if (fabs(k2 - k) < zero) return (true);
      double x = (b2 - b) / (k - k2);
      if (x >= min(xv, xp) && x <= max(xv, xp) && x >= min(xm1, xm2) &&
          x <= max(xm1, xm2))
        return (false);
      else
        return (true);
    }
  }
}
bool check(double x1, double y1, double x2, double y2) {
  double k, b, k2, b2, x, y;
  if (xw1 == xw2) {
    if (x1 == x2)
      if (max(y1, y2) < min(yw1, yw2) || min(y1, y2) > max(yw1, yw2))
        return (true);
      else
        return (false);
    else {
      k = (y1 - y2) / (x1 - x2);
      b = y1 - k * x1;
      y = k * xw1 + b;
      if (y >= min(yw1, yw2) && y <= max(yw1, yw2))
        return (false);
      else
        return (true);
    }
  } else {
    k = (yw1 - yw2) / (xw1 - xw2);
    b = yw1 - k * xw1;
    if (x1 == x2) {
      y = k * x1 + b;
      if (y >= min(y1, y2) && y <= max(y1, y2))
        return (false);
      else
        return (true);
    } else {
      k2 = (y1 - y2) / (x1 - x2);
      b2 = y1 - k2 * x1;
      if (fabs(k2 - k) < zero) {
        if (fabs(b2 - b) > zero)
          return (true);
        else if (max(x1, x2) < min(xw1, xw2) || min(x1, x2) > max(xw1, xw2))
          return (true);
        else
          return (false);
      }
      x = (b2 - b) / (k - k2);
      if (x >= min(x1, x2) && x <= max(x1, x2) && x >= min(xw1, xw2) &&
          x <= max(xw1, xw2))
        return (false);
      else
        return (true);
    }
  }
}
bool check2() {
  double xp2, yp2, k, b, k2, b2, k3, b3, x, y;
  if (max(xm1, xm2) - min(xm1, xm2) <= zero) {
    if ((xv - xm1) * (xp - xm1) <= zero)
      return (false);
    else {
      xp2 = 2 * xw1 - xp;
      yp2 = yp;
      k = (yp2 - yv) / (xp2 - xv);
      b = yv - k * xv;
      y = k * xm1 + b;
      if (y <= min(ym1, ym2) || y >= max(ym1, ym2))
        return (false);
      else if (check(xv, yv, xm1, y) && check(xp, yp, xm1, y))
        return (true);
      else
        return (false);
    }
  } else {
    k = (ym2 - ym1) / (xm2 - xm1);
    b = ym1 - k * xm1;
    if ((xv * k + b - yv) * (xp * k + b - yp) <= 0)
      return (false);
    else {
      if (k > zero) {
        k3 = (-1) / k;
        b3 = yp - k3 * xp;
        xp2 = (b3 - b) / (k - k3);
        yp2 = k * xp2 + b;
        xp2 = xp2 * 2 - xp;
        yp2 = yp2 * 2 - yp;
      } else {
        xp2 = xp;
        yp2 = 2 * ym2 - yp;
      }
      if (fabs(xp2 - xv) <= zero) {
        y = xv * k + b;
        if (y < min(yv, yp2) || y > max(yv, yp2))
          return (false);
        else if (check(xv, yv, xv, y) && check(xp, yp, xv, y))
          return (true);
        else
          return (false);
      } else {
        k2 = (yp2 - yv) / (xp2 - xv);
        b2 = yv - k2 * xv;
        x = (b2 - b) / (k - k2);
        if (x < min(xv, xp2) || x > max(xv, xp2) || x < min(xm1, xm2) ||
            x > max(xm1, xm2))
          return (false);
        else {
          y = k * x + b;
          if (check(xv, yv, x, y) && check(xp, yp, x, y))
            return (true);
          else
            return (false);
        }
      }
    }
  }
}
int main() {
  cin >> xv >> yv >> xp >> yp >> xw1 >> yw1 >> xw2 >> yw2 >> xm1 >> ym1 >>
      xm2 >> ym2;
  if (!precheck())
    cout << "NO";
  else if (check(xv, yv, xp, yp))
    cout << "YES";
  else if (check2())
    cout << "YES";
  else
    cout << "NO";
  return (0);
}
