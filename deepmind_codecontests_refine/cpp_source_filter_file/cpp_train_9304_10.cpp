#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<long double, long double>;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862;
const int inf_int = 1e9 + 5;
const ll inf_ll = 1e18 + 5;
const int NMax = 1e2 + 5;
const int dx[] = {-1, 0, 0, +1}, dy[] = {0, -1, +1, 0};
pld getIntersectionFromX(pld a, pld b, long double x) {
  long double slope = (b.second - a.second) / (b.first - a.first);
  long double yintercept = -slope * a.first + a.second;
  return {x, slope * x + yintercept};
}
pld getIntersectionFromY(pld a, pld b, long double y) {
  long double slope = (b.second - a.second) / (b.first - a.first);
  long double yintercept = -slope * a.first + a.second;
  return {(y - yintercept) / slope, y};
}
long double radToDeg(long double rad) { return rad * 180 / PI; }
long double degToRad(long double deg) { return deg * PI / 180.0l; }
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int w, h, angle;
  cin >> w >> h >> angle;
  if (w < h) {
    swap(w, h);
  }
  if (angle >= 90) {
    angle = 180 - angle;
  }
  if (angle == 0) {
    cout << w * h << '\n';
  } else if (angle == 90) {
    cout << min(w, h) * min(w, h) << '\n';
  } else {
    long double ldw = w, ldh = h, ldangle = angle;
    cout << fixed << setprecision(9);
    long double change = 2 * atan2(ldh, ldw);
    ldangle = degToRad(ldangle);
    if (ldangle >= change) {
      long double a =
          (angle < 90) ? (ldh / tan(ldangle)) : (ldh / tan(180 - ldangle));
      long double parallelogramBase = sqrt(a * a + ldh * ldh);
      cout << parallelogramBase * ldh << '\n';
    } else {
      pld s1[4], s2[4];
      s1[0] = {ldw / 2, -ldh / 2};
      s1[1] = {ldw / 2, ldh / 2};
      s1[2] = {-ldw / 2, ldh / 2};
      s1[3] = {-ldw / 2, -ldh / 2};
      for (int i = 0; i < 4; ++i) {
        s2[i].first = s1[i].first * cos(ldangle) - s1[i].second * sin(ldangle);
        s2[i].second = s1[i].first * sin(ldangle) + s1[i].second * cos(ldangle);
      }
      vector<pld> polygonPoints;
      polygonPoints.push_back(s2[0]);
      polygonPoints.push_back(getIntersectionFromX(s2[0], s2[1], ldw / 2));
      polygonPoints.push_back(s1[1]);
      polygonPoints.push_back(getIntersectionFromY(s2[0], s2[1], ldh / 2));
      polygonPoints.push_back(s2[1]);
      polygonPoints.push_back(getIntersectionFromY(s2[1], s2[2], ldh / 2));
      polygonPoints.push_back(s1[2]);
      polygonPoints.push_back(getIntersectionFromX(s2[1], s2[2], -ldw / 2));
      polygonPoints.push_back(s2[2]);
      polygonPoints.push_back(getIntersectionFromX(s2[2], s2[3], -ldw / 2));
      polygonPoints.push_back(s1[3]);
      polygonPoints.push_back(getIntersectionFromY(s2[2], s2[3], -ldh / 2));
      polygonPoints.push_back(s2[3]);
      polygonPoints.push_back(getIntersectionFromY(s2[3], s2[0], -ldh / 2));
      polygonPoints.push_back(s1[0]);
      polygonPoints.push_back(getIntersectionFromX(s2[3], s2[0], ldw / 2));
      polygonPoints.push_back(s2[0]);
      long double area = 0;
      polygonPoints.push_back(polygonPoints[0]);
      for (int i = 0; i < (int)polygonPoints.size() - 1; ++i) {
        area += polygonPoints[i].first * polygonPoints[i + 1].second -
                polygonPoints[i + 1].first * polygonPoints[i].second;
      }
      area /= 2;
      cout << 2 * ldw * ldh - area << '\n';
    }
  }
  return 0;
}
