#include <bits/stdc++.h>
using namespace std;
const long long maxn = 12;
long long n, p[maxn], no;
struct point {
  double x, y;
  point() { x = y = 0; }
  point operator-(point xx) {
    point yy;
    yy.x = x - xx.x;
    yy.y = y - xx.y;
    return yy;
  }
  double operator*(point xx) { return x * xx.y - y * xx.x; }
  double operator%(point xx) { return x * xx.x + y * xx.y; }
};
point a[maxn], b[maxn], aa[maxn], bb[maxn];
double eps = 0.000000000001;
double abs(point xx) { return sqrt(xx.x * xx.x + xx.y * xx.y); }
bool ok(double xx, double yy) {
  if (-eps < xx - yy && xx - yy < eps) {
    return 1;
  }
  return 0;
}
bool chek() {
  if (!ok(aa[1].x, aa[2].x) || !ok(aa[1].y, aa[2].y)) {
    return 0;
  }
  if (!(ok((aa[1] - aa[3]) * (bb[1] - aa[3]), 0) &&
        (aa[1] - aa[3]) % (bb[1] - aa[3]) < 0)) {
    return 0;
  }
  if (!(ok((aa[2] - bb[3]) * (bb[2] - bb[3]), 0) &&
        (aa[2] - bb[3]) % (bb[2] - bb[3]) < 0)) {
    return 0;
  }
  if (abs(aa[1] - aa[3]) + eps < 0.25 * abs(bb[1] - aa[3])) {
    return 0;
  }
  if (abs(aa[1] - aa[3]) > 4.0 * abs(bb[1] - aa[3]) + eps) {
    return 0;
  }
  if (abs(aa[2] - bb[3]) + eps < 0.25 * abs(bb[2] - bb[3])) {
    return 0;
  }
  if (abs(aa[2] - bb[3]) > 4.0 * abs(bb[2] - bb[3]) + eps) {
    return 0;
  }
  if ((bb[1] - aa[1]) % (bb[2] - aa[2]) < 0) {
    return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    no = 1;
    for (int j = 1; j <= 3; j++) {
      cin >> a[j].x >> a[j].y >> b[j].x >> b[j].y;
    }
    for (int j = 1; j <= 3; j++) {
      p[j] = j;
    }
    do {
      for (int j = 1; j <= 3; j++) {
        aa[j] = a[p[j]];
        bb[j] = b[p[j]];
      }
      for (int j = 0; j < 8; j++) {
        for (int l = 0; l < 3; l++) {
          if ((1 << l) & j) {
            swap(aa[l + 1], bb[l + 1]);
          }
        }
        if (chek()) {
          no = 0;
        }
        for (int l = 0; l < 3; l++) {
          if ((1 << l) & j) {
            swap(aa[l + 1], bb[l + 1]);
          }
        }
      }
    } while (next_permutation(p + 1, p + 1 + 3));
    if (!no) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
