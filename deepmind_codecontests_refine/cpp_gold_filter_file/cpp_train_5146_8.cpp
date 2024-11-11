#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long double INF = 1e20;
const long double eps = 1e-4;
int N, M;
pair<long double, long double> gen[MAXN], poly[MAXN];
long double tot, squares;
pair<long double, long double> centroid;
pair<long double, long double> get() {
  int p, q;
  scanf("%d%d", &p, &q);
  return {p, q};
}
void load() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) gen[i] = get();
  scanf("%d", &M);
  for (int i = 0; i < M; i++) poly[i] = get();
}
pair<long double, long double> operator+(
    const pair<long double, long double> &u,
    const pair<long double, long double> &v) {
  return {u.first + v.first, u.second + v.second};
}
pair<long double, long double> operator-(
    const pair<long double, long double> &u,
    const pair<long double, long double> &v) {
  return {u.first - v.first, u.second - v.second};
}
void operator+=(pair<long double, long double> &u,
                const pair<long double, long double> &v) {
  u = u + v;
}
long double operator*(const pair<long double, long double> &u,
                      const pair<long double, long double> &v) {
  return u.first * v.first + u.second * v.second;
}
pair<long double, long double> operator*(
    const long double &lambda, const pair<long double, long double> &v) {
  return {lambda * v.first, lambda * v.second};
}
void operator*=(pair<long double, long double> &v, const long double &lambda) {
  v = lambda * v;
}
long double norm(const pair<long double, long double> &v) { return v * v; }
long double eval(pair<long double, long double> v) {
  return N * norm(v) - 2 * N * centroid * v + squares;
}
long double area(pair<long double, long double> a,
                 pair<long double, long double> b,
                 pair<long double, long double> c) {
  return abs(a.first * (b.second - c.second) + b.first * (c.second - a.second) +
             c.first * (a.second - b.second));
}
bool inside(pair<long double, long double> v) {
  long double sum = 0;
  for (int i = 0; i < M; i++) sum += area(v, poly[i], poly[(i + 1) % M]);
  return abs(sum - tot) < eps;
}
long double optimize(pair<long double, long double> u,
                     pair<long double, long double> v) {
  long double t = (long double)1 / norm(v - u) * (centroid - u) * (v - u);
  if (t < 0 || t > 1) return INF;
  return eval((1 - t) * u + t * v);
}
long double solve() {
  for (int i = 0; i < N; i++) {
    squares += norm(gen[i]);
    centroid += gen[i];
  }
  centroid *= (long double)1 / N;
  for (int i = 1; i < M - 1; i++) tot += area(poly[0], poly[i], poly[i + 1]);
  if (inside(centroid)) return eval(centroid);
  long double sol = INF;
  for (int i = 0; i < M; i++) {
    sol = min(sol, eval(poly[i]));
    sol = min(sol, optimize(poly[i], poly[(i + 1) % M]));
  }
  return sol;
}
int main() {
  load();
  printf("%.10Lf\n", solve());
  return 0;
}
