#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
double cross(complex<long double> a, complex<long double> b) {
  return imag(conj(a) * b);
}
double area2(complex<long double> a, complex<long double> b,
             complex<long double> c) {
  return cross(b - a, c - a);
}
namespace std {
bool operator<(complex<long double> a, complex<long double> b) {
  if (a.real() != b.real()) return a.real() < b.real();
  return a.imag() < b.imag();
}
}  // namespace std
vector<complex<long double>> convex_hull(vector<complex<long double>> &P) {
  long long n = P.size(), k = 0;
  vector<complex<long double>> h(2 * n);
  sort(P.begin(), P.end());
  for (long long i = 0; i < n; h[k++] = P[i++])
    while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) < EPS) --k;
  for (long long i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
    while (k >= t && area2(h[k - 2], h[k - 1], P[i]) < EPS) --k;
  return vector<complex<long double>>(h.begin(), h.begin() + k - (k > 1));
}
vector<pair<complex<long double>, long long>> CH(
    vector<pair<complex<long double>, long long>> &P) {
  long long n = P.size(), k = 0;
  vector<pair<complex<long double>, long long>> h(2 * n);
  sort(P.begin(), P.end());
  for (long long i = 0; i < n; h[k++] = P[i++])
    while (k >= 2 && area2(h[k - 2].first, h[k - 1].first, P[i].first) < EPS)
      --k;
  for (long long i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
    while (k >= t && area2(h[k - 2].first, h[k - 1].first, P[i].first) < EPS)
      --k;
  h.resize(k - (k > 1));
  return h;
}
vector<complex<long double>> convex_hull2(vector<complex<long double>> &P) {
  long long n = P.size(), k = 0;
  vector<complex<long double>> h(2 * n);
  sort(P.begin(), P.end());
  for (long long i = 0; i < n; h[k++] = P[i++])
    while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) < -EPS) --k;
  for (long long i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
    while (k >= t && area2(h[k - 2], h[k - 1], P[i]) < -EPS) --k;
  return vector<complex<long double>>(h.begin(), h.begin() + k - (k > 1));
}
long double dist(complex<long double> p1, complex<long double> p2) {
  long double xx = p1.real() - p2.real();
  long double yy = p1.imag() - p2.imag();
  return sqrtl(xx * xx + yy * yy);
}
long double radio(complex<long double> p1, complex<long double> p2,
                  complex<long double> p3) {
  long double d1 = dist(p1, p2);
  long double d2 = dist(p1, p3);
  long double d3 = dist(p2, p3);
  long double S = abs(area2(p1, p2, p3)) / 2.0;
  if (S < EPS) return -1e18;
  return d1 * d2 * d3 / S / 4.0;
}
complex<long double> invert(complex<long double> p1, long double rad,
                            complex<long double> p2) {
  long double d1 = dist(p1, p2);
  long double d2 = rad * rad / d1;
  long double prop = d2 / d1;
  p2 -= p1;
  p2 *= prop;
  p2 += p1;
  return p2;
}
const long double RADIO = 100;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(10) << fixed << '\n';
  long long N, M;
  cin >> N >> M;
  vector<complex<long double>> v1, v2;
  for (long long i = 1; i <= N; i++) {
    long double x, y;
    cin >> x >> y;
    v1.push_back({x, y});
  }
  for (long long i = 1; i <= M; i++) {
    long double x, y;
    cin >> x >> y;
    v2.push_back({x, y});
  }
  swap(v1, v2);
  swap(N, M);
  if (N == 1) {
    cout << -1 << '\n';
    return 0;
  }
  long double res = -1e18;
  bool flag = true;
  for (long long i = 0; i < N; i++) {
    vector<complex<long double>> vect;
    vector<complex<long double>> vect2;
    for (long long j = 0; j < N; j++) {
      if (i == j) {
        vect.push_back(v1[i]);
      } else {
        vect.push_back(invert(v1[i], RADIO, v1[j]));
      }
    }
    set<pair<complex<long double>, complex<long double>>> st;
    set<pair<complex<long double>, complex<long double>>> st2;
    vect = convex_hull(vect);
    vect2 = vect;
    for (long long j = 0; j < M; j++) {
      vect2.push_back(invert(v1[i], RADIO, v2[j]));
    }
    vect2 = convex_hull2(vect2);
    for (long long j = 0; j < vect2.size(); j++) {
      complex<long double> p1 = vect2[j];
      complex<long double> p2 = vect2[(j + 1) % vect2.size()];
      if (p2 < p1) swap(p1, p2);
      st.insert({p1, p2});
    }
    auto vect3 = convex_hull(vect2);
    for (long long j = 0; j < vect3.size(); j++) {
      complex<long double> p1 = vect3[j];
      complex<long double> p2 = vect3[(j + 1) % vect3.size()];
      if (p2 < p1) swap(p1, p2);
      st2.insert({p1, p2});
    }
    for (long long j = 0; j < vect.size(); j++) {
      complex<long double> p1 = vect[j];
      complex<long double> p2 = vect[(j + 1) % vect.size()];
      if (p2 < p1) swap(p1, p2);
      if (st2.find({p1, p2}) == st2.end()) {
        if (p1 == v1[i] || p2 == v1[i]) {
          flag = false;
        }
      }
      if (st.find({p1, p2}) == st.end()) {
        if (p1 == v1[i] || p2 == v1[i]) {
        } else {
          p1 = invert(v1[i], RADIO, p1);
          p2 = invert(v1[i], RADIO, p2);
          res = max(res, radio(v1[i], p1, p2));
        }
      }
    }
    vector<pair<complex<long double>, long long>> vvv;
    for (long long j = 0; j < N; j++) {
      if (i == j) {
        vvv.push_back({v1[i], 1});
      } else {
        vvv.push_back({invert(v1[i], RADIO, v1[j]), 1});
      }
    }
    for (long long j = 0; j < M; j++) {
      vvv.push_back({invert(v1[i], RADIO, v2[j]), 2});
    }
    vvv = CH(vvv);
    for (long long j = 0; j < vvv.size(); j++) {
      long long k1 = vvv[j].second;
      long long k2 = vvv[(j + 1) % vvv.size()].second;
      if (k1 == k2) continue;
      complex<long double> p1 = vvv[j].first;
      complex<long double> p2 = vvv[(j + 1) % vvv.size()].first;
      if (p1 == v1[i] || p2 == v1[i]) continue;
      p1 = invert(v1[i], RADIO, p1);
      p2 = invert(v1[i], RADIO, p2);
      res = max(res, radio(v1[i], p1, p2));
    }
  }
  if (flag && res > 0) {
    cout << res << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
