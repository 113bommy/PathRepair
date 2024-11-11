#include <bits/stdc++.h>
using namespace std;
using dbl = long double;
const dbl INF = 1e18;
const dbl EPS = 1e-9;
struct pt {
  dbl first, second;
  pt(dbl a, dbl b) : first(a), second(b) {}
  pt() : pt(0, 0) {}
};
set<pair<int, int>> s;
istream &operator>>(istream &in, pt &p) {
  int first, second;
  in >> first >> second;
  s.emplace(first, second);
  p.first = first, p.second = second;
  return in;
}
ostream &operator<<(ostream &out, pt p) {
  return out << p.first << " " << p.second;
}
pt operator+(pt a, pt b) { return {a.first + b.first, a.second + b.second}; }
pt vec(pt a, pt b) { return {b.first - a.first, b.second - a.second}; }
pt operator*(pt a, dbl k) { return {a.first * k, a.second * k}; }
pt rot(pt a) { return {a.second, -a.first}; }
dbl operator*(pt a, pt b) { return a.first * b.first + a.second * b.second; }
dbl operator%(pt a, pt b) { return a.first * b.second - a.second * b.first; }
pt cross(pt a, pt b, pt c, pt d) {
  dbl acd = vec(a, c) % vec(a, d);
  dbl bdc = vec(b, d) % vec(b, c);
  assert(abs(acd + bdc) > EPS);
  return a + vec(a, b) * (acd / (acd + bdc));
}
bool sharp(pt a, pt b, pt c) { return vec(a, b) * vec(a, c) > -EPS; }
bool stra(pt a, pt b, pt c) { return abs(vec(a, b) * vec(a, c)) < EPS; }
dbl dist(pt a, pt b) { return hypot(a.first - b.first, a.second - b.second); }
const int N = 110;
int n;
dbl ans = -1;
pt a[N];
bool sharp(int i, int j, int k) { return sharp(a[i], a[j], a[k]); }
bool stra(int i, int j, int k) { return stra(a[i], a[j], a[k]); }
bool fnd(pt p) {
  int first = (int)round(p.first);
  int second = (int)round(p.second);
  assert(abs(first - p.first) < EPS && abs(second - p.second) < EPS);
  return s.count(make_pair(first, second));
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (!sharp(i, j, k) || !sharp(j, i, k) || !sharp(k, i, j)) {
          continue;
        }
        if (stra(i, j, k) && !fnd(a[i] + vec(a[i], a[j]) + vec(a[i], a[k]))) {
          continue;
        }
        if (stra(j, i, k) && !fnd(a[j] + vec(a[j], a[i]) + vec(a[j], a[k]))) {
          continue;
        }
        if (stra(k, i, j) && !fnd(a[k] + vec(a[k], a[i]) + vec(a[k], a[j]))) {
          continue;
        }
        pt ij1 = (a[i] + a[j]) * 0.5;
        pt ij2 = ij1 + rot(vec(a[i], a[j]));
        pt ik1 = (a[i] + a[k]) * 0.5;
        pt ik2 = ik1 + rot(vec(a[i], a[k]));
        pt o = cross(ij1, ij2, ik1, ik2);
        dbl r = dist(o, a[i]);
        bool f = true;
        for (int t = 0; t < n; ++t) {
          if (dist(o, a[t]) < r - EPS) {
            f = false;
          }
        }
        if (f) {
          ans = max(ans, r);
        }
      }
    }
  }
  if (ans < 0) {
    cout << -1 << endl;
  } else {
    cout << fixed << setprecision(20) << ans << endl;
  }
  return 0;
}
