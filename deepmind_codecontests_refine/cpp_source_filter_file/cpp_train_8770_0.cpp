#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld EPS = 1e-9;
const int N = 10005;
struct Quat {
  ld s, x, y, z;
  Quat conj() const { return {s, -x, -y, -z}; }
  inline Quat operator+(const Quat &rhs) const {
    return {s + rhs.s, x + rhs.x, y + rhs.y, z + rhs.z};
  }
  inline Quat operator-(const Quat &rhs) const {
    return {s - rhs.s, x - rhs.x, y - rhs.y, z - rhs.z};
  }
  Quat operator*(const Quat &rhs) const {
    return {s * rhs.s - x * rhs.x - y * rhs.y - z * rhs.z,
            s * rhs.x + x * rhs.s + y * rhs.z - z * rhs.y,
            s * rhs.y - x * rhs.z + y * rhs.s + z * rhs.x,
            s * rhs.z + x * rhs.y - y * rhs.x + z * rhs.s};
  }
  ld norm() const { return s * s + x * x + y * y + z * z; }
  Quat inv() const { return conj() * Quat{1.0 / norm(), 0, 0, 0}; }
  bool chk() const {
    return abs(round(s) - s) < EPS && abs(round(x) - x) < EPS &&
           abs(round(y) - y) < EPS && abs(round(z) - z) < EPS;
  }
  void print() { cout << ll(x) << ' ' << ll(y) << ' ' << ll(z) << endl; }
};
Quat round(Quat x) {
  Quat q1 = {round(x.s), round(x.x), round(x.y), round(x.z)};
  Quat q2 = {round(x.s - 0.5) + 0.5, round(x.x - 0.5) + 0.5,
             round(x.y - 0.5) + 0.5, round(x.z - 0.5) + 0.5};
  return (q1 - x).norm() < (q2 - x).norm() ? q1 : q2;
}
inline Quat operator/(const Quat &a, const Quat &b) { return b.inv() * a; }
inline Quat operator%(const Quat &a, const Quat &b) {
  return a - b * round(a / b);
}
Quat gcd(Quat a, Quat b) { return b.norm() < EPS ? a : gcd(b, a % b); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
Quat a[N], g, q, iq, tq, tiq;
int idx;
ll tg[N], r;
int main() {
  ios::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  ll gg = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%Lf%Lf%Lf", &a[i].x, &a[i].y, &a[i].z);
    g = gcd(g, a[i]);
    gg = gcd(gg, ll(a[i].norm()));
  }
  for (ll i = 1; i * i <= gg; i++)
    if (gg % (i * i) == 0) tg[++idx] = i;
  for (int i = idx; i > 0; --i) {
    q = gcd(q, Quat{ld(tg[i]), 0, 0, 0});
    iq = q.conj();
    r = q.norm();
    if (r != tg[i]) continue;
    tq = q / Quat{ld(r), 0, 0, 0};
    tiq = iq / Quat{ld(r), 0, 0, 0};
    bool ok = 1;
    for (int j = 1; j <= n; j++)
      if (!(tiq * a[j] * tq).chk()) {
        ok = 0;
        break;
      }
    if (!ok) continue;
    cout << r * r << endl;
    (q * Quat{0, 1, 0, 0} * iq).print();
    (q * Quat{0, 0, 1, 0} * iq).print();
    (q * Quat{0, 0, 0, 1} * iq).print();
    break;
  }
  return 0;
}
