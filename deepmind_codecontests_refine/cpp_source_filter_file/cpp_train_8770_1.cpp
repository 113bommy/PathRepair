#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
struct quat {
  long double s, x, y, z;
  quat(long double s = 0, long double x = 0, long double y = 0,
       long double z = 0)
      : s(s), x(x), y(y), z(z) {}
  quat operator+(quat q) { return quat(s + q.s, x + q.x, y + q.y, z + q.z); }
  quat operator-(quat q) { return quat(s - q.s, x - q.x, y - q.y, z - q.z); }
  quat operator*(quat q) {
    return quat(s * q.s - x * q.x - y * q.y - z * q.z,
                s * q.x + x * q.s + y * q.z - z * q.y,
                s * q.y - x * q.z + y * q.s + z * q.x,
                s * q.z + x * q.y - y * q.x + z * q.s);
  }
  quat conj() { return quat(s, -x, -y, -z); }
  long double norm() { return s * s + x * x + y * y + z * z; }
  quat inv() { return conj() * quat(1.0 / norm()); }
  bool check() {
    return abs(round(s) - s) < eps && abs(round(x) - x) < eps &&
           abs(round(y) - y) < eps && abs(round(z) - z) < eps;
  }
  void print() {
    printf("%lld %lld %lld\n", (long long)round(x), (long long)round(y),
           (long long)round(z));
  }
  quat qround() {
    quat q1 = quat(round(s), round(x), round(y), round(z));
    quat q2 = quat(round(s - 0.5) + 0.5, round(x - 0.5) + 0.5,
                   round(y - 0.5) + 0.5, round(z - 0.5) + 0.5);
    return (q1 - *this).norm() < (q2 - *this).norm() ? q1 : q2;
  }
  quat operator/(quat q) { return q.inv() * *this; }
  quat operator%(quat q) {
    quat t = (*this / q).qround();
    return *this - q * t;
  }
} a[10010], g;
quat gcd(quat x, quat y) { return y.norm() < eps ? x : gcd(y, x % y); }
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
int n, tot;
long long G, len[2000];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%LF%LF%LF", &a[i].x, &a[i].y, &a[i].z);
    g = gcd(g, a[i]);
    G = gcd(G, (long long)a[i].norm());
  }
  for (long long i = 1; i * i <= G; i++)
    if (!(G % (i * i))) len[++tot] = i;
  for (int i = tot; i; i--) {
    quat q = gcd(g, quat(len[i]));
    long long r = q.norm();
    if (r != len[i]) continue;
    quat tq = q / r, tiq = q.conj() / r;
    bool suc = 1;
    for (int j = 1; j <= n; j++)
      if (!(tq * a[j] * tiq).check()) {
        suc = 0;
        break;
      }
    if (!suc) continue;
    printf("%lld\n", r * r);
    (q * quat(0, 1) * q.conj()).print();
    (q * quat(0, 0, 1) * q.conj()).print();
    (q * quat(0, 0, 0, 1) * q.conj()).print();
    break;
  }
}
