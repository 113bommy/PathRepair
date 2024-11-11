#include <bits/stdc++.h>
using namespace std;
struct vec {
  double a[3];
  double& operator[](int i) { return a[i]; }
  double operator[](int i) const { return a[i]; }
};
vec operator-(vec a, vec b) {
  vec r;
  for (int i = 0; i < 3; ++i) r[i] = a[i] - b[i];
  return r;
}
vec operator+(vec a, vec b) {
  vec r;
  for (int i = 0; i < 3; ++i) r[i] = a[i] + b[i];
  return r;
}
vec operator*(vec v, double x) {
  for (int i = 0; i < 3; ++i) v[i] *= x;
  return v;
}
double dist(vec v) {
  double r = 0;
  for (int i = 0; i < 3; ++i) r += v[i] * v[i];
  return sqrt(r);
}
ostream& operator<<(ostream& o, vec v) {
  o << '[';
  for (int i = 0; i < 3; ++i) o << v[i] << ' ';
  o << ']';
  return o;
}
vec P;
vec line[1 << 20];
double vp, vs;
int N;
int main() {
  cin >> N;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j < 3; ++j) cin >> line[i][j];
  }
  cin >> vp >> vs;
  for (int i = 0; i < 3; ++i) cin >> P[i];
  double t0 = 0;
  int k = 0;
  while (k < N) {
    vec a = line[k], b = line[k + 1];
    if (dist(P - b) * vs <= (t0 + dist(b - a)) * vp) {
      double tmin = 0;
      double dst = dist(b - a);
      double tmax = dst;
      vec pmid;
      for (int i = 0; i < 100; ++i) {
        double tmid = .5 * (tmin + tmax);
        vec mid = a + (b - a) * (tmid / (dst));
        double pt = dist(P - mid);
        if (pt * vs <= (t0 + tmid) * vp) {
          tmax = tmid;
        } else {
          tmin = tmid;
        }
        pmid = mid;
      }
      cout << "YES\n";
      cout << fixed << setprecision(15) << (t0 + tmin) / vs << '\n';
      for (int i = 0; i < 3; ++i) {
        if (i > 0) cout << ' ';
        cout << pmid[i];
      }
      cout << '\n';
      return 0;
    }
    t0 += dist(b - a);
    ++k;
  }
  cout << "NO\n";
}
