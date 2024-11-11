#include <bits/stdc++.h>
struct P {
  P() {}
  P(double x, double y) : x(x), y(y) {}
  void normalize() {
    double dist = std::sqrt(x * x + y * y);
    x /= dist;
    y /= dist;
  }
  P& operator+=(const P& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  const P operator+(const P& rhs) const {
    P p = *this;
    p += rhs;
    return p;
  }
  P& operator-=(const P& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  const P operator-(const P& rhs) const {
    P p = *this;
    p -= rhs;
    return p;
  }
  P& operator*=(double lamb) {
    x *= lamb;
    y *= lamb;
    return *this;
  }
  const P operator*(double lamb) const {
    P p = *this;
    p *= lamb;
    return p;
  }
  double x, y;
};
double distSquare(const P& l, const P& r) {
  return (l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y);
}
double dist(const P& l, const P& r) { return std::sqrt(distSquare(l, r)); }
bool signeNasochenoLice(const P& a, const P& b, const P& c) {
  return (a.x * b.y + b.x * c.y + c.x * a.y - c.x * b.y - b.x * a.y -
          a.x * c.y) < 0;
}
bool eq(double x, double y) { return std::abs(x - y) < 1e-9; }
struct C {
  C() {}
  C(double x, double y, double r) : c(x, y), r(r) {}
  P c;
  double r;
};
struct I {
  I() {}
  I(double x, double y) : x(x), y(y) {}
  double x, y;
};
int t1, t2, t3, t4;
int n;
P lineA;
P lineB;
P lineCenter;
C circles[100004];
P lineNormalLeft;
P lineNormalRight;
int leftICount = 0;
int rightICount = 0;
I leftI[100004];
I rightI[100004];
double forCloserBin(P normal, C circle) {
  double l = 0.0, r = 1e12, mid;
  for (int i = 0; i < 130; ++i) {
    mid = (l + r) / 2.0;
    if (dist(lineCenter + normal * mid, lineA) <
        dist(lineCenter + normal * mid, circle.c) - circle.r)
      l = mid;
    else
      r = mid;
  }
  return l;
}
double forFurtherBin(P normal, C circle) {
  double l = 0.0, r = 1e12, mid;
  for (int i = 0; i < 130; ++i) {
    mid = (l + r) / 2.0;
    if (dist(lineCenter + normal * mid, lineA) >
        dist(lineCenter + normal * mid, circle.c) + circle.r)
      r = mid;
    else
      l = mid;
  }
  return r;
}
double otherSideCloserBin(P normal, C circle) {
  double l = 0.0, r = 1e12, mid;
  for (int i = 0; i < 130; ++i) {
    mid = (l + r) / 2.0;
    if (dist(lineCenter + normal * mid, lineA) <
        dist(lineCenter + normal * mid, circle.c) - circle.r)
      r = mid;
    else
      l = mid;
  }
  return r;
}
double otherSidefurtherBin(P normal, C circle) {
  double l = 0.0, r = 1e12, mid;
  for (int i = 0; i < 130; ++i) {
    mid = (l + r) / 2.0;
    if (dist(lineCenter + normal * mid, lineA) >
        dist(lineCenter + normal * mid, circle.c) + circle.r)
      l = mid;
    else
      r = mid;
  }
  return l;
}
std::pair<double, int> arr[2 * 100004];
int main() {
  scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
  lineA = P(t1, t2);
  lineB = P(t3, t4);
  lineCenter = (lineB - lineA) * 0.5 + lineA;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &t1, &t2, &t3);
    circles[i] = C(t1, t2, t3);
  }
  lineNormalLeft = P(lineA.y - lineB.y, lineB.x - lineA.x);
  if (!signeNasochenoLice(lineA, lineB, lineNormalLeft)) lineNormalLeft *= -1.0;
  lineNormalRight = lineNormalLeft * (-1.0);
  lineNormalLeft.normalize();
  lineNormalRight.normalize();
  for (int i = 0; i < n; ++i) {
    if (signeNasochenoLice(lineA, lineB, lineA + lineNormalLeft) ==
        signeNasochenoLice(lineA, lineB, circles[i].c)) {
      double l = forCloserBin(lineNormalLeft, circles[i]);
      double r = forFurtherBin(lineNormalLeft, circles[i]);
      if (l < r && !eq(l, r)) leftI[leftICount++] = I(l, r);
    } else {
      double l = otherSidefurtherBin(lineNormalLeft, circles[i]);
      double r = otherSideCloserBin(lineNormalLeft, circles[i]);
      if (l < r && !eq(l, r)) leftI[leftICount++] = I(l, r);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (signeNasochenoLice(lineA, lineB, lineA + lineNormalRight) ==
        signeNasochenoLice(lineA, lineB, circles[i].c)) {
      double l = forCloserBin(lineNormalRight, circles[i]);
      double r = forFurtherBin(lineNormalRight, circles[i]);
      if (l < r && !eq(l, r)) rightI[rightICount++] = I(l, r);
    } else {
      double l = otherSidefurtherBin(lineNormalRight, circles[i]);
      double r = otherSideCloserBin(lineNormalRight, circles[i]);
      if (l < r && !eq(l, r)) rightI[rightICount++] = I(l, r);
    }
  }
  for (int i = 0; i < leftICount; ++i) {
    arr[2 * i].first = leftI[i].x;
    arr[2 * i + 1].first = leftI[i].y;
    arr[2 * i].second = 1;
    arr[2 * i + 1].second = -1;
  }
  double firstBest = 1e12;
  std::sort(
      arr, arr + 2 * leftICount,
      [](const std::pair<double, int>& l, const std::pair<double, int>& r) {
        if (eq(l.first, r.first)) {
          if (l.second == -1) return true;
          return false;
        } else {
          return l.first < r.first;
        }
      });
  int cntFB = 0;
  for (int i = 0; i < 2 * leftICount; ++i) {
    cntFB += arr[i].second;
    if (cntFB == 0) {
      firstBest = arr[i].first;
      break;
    }
  }
  for (int i = 0; i < rightICount; ++i) {
    arr[2 * i].first = rightI[i].x;
    arr[2 * i + 1].first = rightI[i].y;
    arr[2 * i].second = 1;
    arr[2 * i + 1].second = -1;
  }
  double secondBest = 1e12;
  std::sort(
      arr, arr + 2 * rightICount,
      [](const std::pair<double, int>& l, const std::pair<double, int>& r) {
        if (eq(l.first, r.first)) {
          if (l.second == -1) return true;
          return false;
        } else {
          return l.first < r.first;
        }
      });
  cntFB = 0;
  for (int i = 0; i < 2 * rightICount; ++i) {
    cntFB += arr[i].second;
    if (cntFB == 0) {
      secondBest = arr[i].first;
      break;
    }
  }
  bool isSimple = true;
  double distlinec = dist(lineCenter, lineA);
  for (int i = 0; i < n; ++i) {
    double curDiss = dist(lineCenter, circles[i].c);
    if (!(!(distlinec > curDiss - circles[i].r &&
            distlinec < curDiss + circles[i].r) ||
          eq(distlinec, curDiss - circles[i].r) ||
          eq(distlinec, curDiss + circles[i].r)))
      isSimple = false;
  }
  double resss;
  if (isSimple)
    resss = distlinec;
  else {
    resss = std::min(firstBest, secondBest);
    resss = dist(lineNormalLeft * resss + lineCenter, lineA);
  }
  printf("%lf\n", resss);
  return 0;
}
