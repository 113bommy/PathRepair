#include <bits/stdc++.h>
using namespace std;
struct pt {
  double x, y;
  pt() { x = 0, y = 0; }
  pt(double a, double b) { x = a, y = b; }
  double len() { return sqrt(x * x + y * y); }
  pt operator*(double u) { return pt(x * u, y * u); }
  pt operator+(pt u) { return pt(x + u.x, y + u.y); }
  pt operator-(pt u) { return pt(x - u.x, y - u.y); }
};
double cals(pt a, pt b, pt c) {
  double l1 = (a - b).len(), l2 = (b - c).len(), l3 = (a - c).len();
  double aco = (l1 * l1 + l2 * l2 - l3 * l3) / (2 * l1 * l2);
  double c2 = aco * aco * 2 - 1;
  int tp = 1;
  if (aco < 0) tp = -1;
  return tp * sqrt(1 - c2 * c2);
}
pt cer(pt a, pt b, pt c) {
  double n2 = cals(a, b, c), n1 = cals(b, a, c), n3 = cals(a, c, b);
  pt fn = a * n1 + b * n2 + c * n3;
  fn = fn * (1 / (n1 + n2 + n3));
  return fn;
}
struct cr {
  pt u;
  double r;
} x[5];
double ls = 0.88, rs = 1.12;
int mn = 4005;
int n, k;
int fl[4005];
bool check(cr a, pt b) {
  double n1 = (a.u - b).len();
  return (n1 >= a.r * ls) && (n1 <= a.r * rs);
}
void cal(vector<pt> u) {
  int lst = 4005;
  vector<pt> r;
  int tm = 0;
  while (1) {
    tm++;
    if (!(tm % 1000))
      if (clock() / CLOCKS_PER_SEC > 10) break;
    cr y[5];
    r = u;
    int fl = 1;
    for (int j = 1; j <= k; j++) {
      int ns = r.size();
      if (ns <= 3) {
        fl = 0;
        break;
      }
    l1:
      int u1 = rand() % ns, v = rand() % ns, w = rand() % ns;
      if (u1 == v || u1 == w || v == w) goto l1;
      pt a = r[u1], b = r[v], c = r[w];
      pt o = cer(a, b, c);
      y[j].u = o, y[j].r = (o - a).len();
      double u2 = (o - b).len();
      if (y[j].r > 750000 || y[j].r < 250000) {
        fl = 0;
        break;
      }
      vector<pt> g;
      for (int m = 0; m < ns; m++)
        if (!check(y[j], r[m])) g.push_back(r[m]);
      r = g;
    }
    if (!fl) continue;
    int ns[5] = {0, 0, 0, 0, 0};
    cr z[5];
    for (int i = 0; i < 5; i++) z[i].u = pt(0, 0), z[i].r = 0;
    vector<pt> s[5];
    for (int j = 0; j < u.size(); j++) {
      int nmm = 4005, mpl = 0;
      for (int t = 1; t <= k; t++)
        if (check(y[t], u[j]))
          if (ns[t] < nmm) nmm = ns[t], mpl = t;
      ns[mpl]++;
      s[mpl].push_back(u[j]);
    }
    int dv = 0;
    for (int j = 1; j <= k; j++) dv += abs(ns[j] - n);
    if (dv < mn) {
      for (int i = 1; i <= k; i++) {
        z[i].u = y[i].u;
        for (int t = 0; t < s[i].size(); t++)
          z[i].r += (z[i].u - s[i][t]).len();
        z[i].r /= ns[i];
      }
      mn = dv;
      for (int j = 1; j <= k; j++) x[j] = z[j];
    }
  }
}
int main() {
  srand(5);
  cin >> k >> n;
  vector<pt> s;
  for (int i = 1; i <= n * k; i++) {
    int x, y;
    cin >> x >> y;
    s.push_back(pt(x, y));
  }
  cal(s);
  for (int i = 1; i <= k; i++)
    printf("%.10lf %.10lf %.10lf\n", x[i].u.x, x[i].u.y, x[i].r);
  return 0;
}
