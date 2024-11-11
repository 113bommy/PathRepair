#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
  point() {}
  point(double x_, double y_) {
    x = x_;
    y = y_;
  }
  point operator+(point b) { return point(x + b.x, y + b.y); }
  point operator-(point b) { return point(x - b.x, y - b.y); }
  double operator*(point b) { return x * b.y - b.x * y; }
  bool operator<(point b) { return make_pair(x, y) < make_pair(b.x, b.y); }
  double d() { return sqrt(x * x + y * y); }
  double d2() { return x * x + y * y; }
  void rot() {
    swap(x, y);
    x = -x;
  }
  void mult(double d) {
    x *= d;
    y *= d;
  }
};
point intersect(point a, point b, point c, point d) {
  point e = b - a;
  e.mult(((d - c) * (a - c)) / ((b - a) * (d - c)));
  return a + e;
}
double sp(point a, point b) { return a.x * b.x + a.y * b.y; }
double R;
int N;
vector<point> V;
bool CH_comporator(point a, point b) {
  double V = a * b;
  return V != 0 ? V > 0 : a.d2() < b.d2();
}
vector<point> ConvexHull(vector<point> A) {
  vector<point> CH;
  int n = A.size();
  for (int i = 1; i < n; i++)
    if (A[i] < A[0]) swap(A[i], A[0]);
  for (int i = 1; i < n; i++) A[i] = A[i] - A[0];
  sort(A.begin() + 1, A.end(), CH_comporator);
  CH.push_back(A[0]);
  CH.push_back(A[1] + A[0]);
  int CH_sz = 2;
  for (int i = 2; i < A.size(); i++) {
    point cur = A[i] + A[0];
    while (CH_sz >= 2 &&
           (CH[CH_sz - 1] - CH[CH_sz - 2]) * (cur - CH[CH_sz - 1]) <= 0) {
      CH.pop_back();
      CH_sz--;
    }
    CH.push_back(cur);
    CH_sz++;
  }
  return CH;
}
double duga_inc(point a, point b, double r) {
  double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
  double tetta = 2 * asin((d / 2) / r);
  double square_sect = tetta * r * r / 2;
  double p = (r + r + d) / 2.;
  double square_triang = sqrt(p * (p - r) * (p - r) * (p - d));
  return square_sect - square_triang;
}
double Calculus_answer(vector<point> &CH) {
  double ans = 0;
  int n = CH.size();
  if (n == 2) return 2 * duga_inc(CH[0], CH[1], R);
  for (int i = 0; i < n - 1; i++) ans += duga_inc(CH[i], CH[i + 1], R);
  ans += duga_inc(CH[n - 1], CH[0], R);
  double CH_S = 0;
  for (int i = 0; i < n - 1; i++) CH_S += (CH[i] * CH[i + 1]) / 2.;
  CH_S += (CH[n - 1] * CH[0]) / 2.;
  ans += abs(CH_S);
  return ans;
}
vector<point> CH_G;
int Lf[1000000];
int Rg[1000000];
struct vertex {
  int cur;
  vertex() {}
  vertex(int cur_) { cur = cur_; }
  double crit() {
    point u = CH_G[cur], l = CH_G[Lf[cur]], r = CH_G[Rg[cur]];
    point one = u - r;
    point two = l - r;
    one.mult(0.5);
    two.mult(0.5);
    point v1 = one, v2 = two;
    v1.rot();
    v2.rot();
    point O = intersect(r + one, r + one + v1, r + two, r + two + v2);
    return (r - O).d();
  }
};
bool operator<(vertex a, vertex b) {
  if (a.crit() == b.crit()) return a.cur < b.cur;
  return a.crit() > b.crit();
}
void update(multiset<vertex>::iterator &it, multiset<vertex> &S) {
  vertex v = *it;
  int cur = v.cur;
  int lft = Lf[cur];
  int rgt = Rg[cur];
  double rds = v.crit();
  S.erase(vertex(Lf[cur]));
  S.erase(vertex(cur));
  S.erase(vertex(Rg[cur]));
  Rg[Lf[cur]] = Rg[cur];
  Lf[Rg[cur]] = Lf[cur];
  S.insert(vertex(Rg[cur]));
  S.insert(vertex(Lf[cur]));
}
vector<point> CH_form(vector<point> CH, double R) {
  CH_G = CH;
  int n = CH.size();
  multiset<vertex> S;
  for (int i = 1; i < n - 1; i++) {
    Lf[i] = i - 1;
    Rg[i] = i + 1;
    S.insert(vertex(i));
  }
  Lf[0] = n - 1;
  Rg[0] = 1;
  S.insert(vertex(0));
  Lf[n - 1] = n - 2;
  Rg[n - 1] = 0;
  S.insert(vertex(n - 1));
  while (S.size() > 3) {
    multiset<vertex>::iterator it = S.begin();
    vertex v = *it;
    if (v.crit() < R) break;
    update(it, S);
  }
  if (S.size() == 3) {
    multiset<vertex>::iterator it = S.begin();
    vertex v = *it;
    if (v.crit() < R) {
      point a = CH[it->cur];
      it++;
      point b = CH[it->cur];
      it++;
      point c = CH[it->cur];
      it = S.begin();
      if (sp(b - a, c - a) <= 0)
        S.erase(it);
      else {
        it++;
        if (sp(c - b, a - b) <= 0)
          S.erase(it);
        else {
          it++;
          S.erase(it);
        }
      }
    }
  }
  vector<point> A;
  for (multiset<vertex>::iterator it = S.begin(); it != S.end(); it++) {
    A.push_back(CH[it->cur]);
  }
  return A;
}
int main() {
  cin >> N >> R;
  for (int i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y;
    V.push_back(point(x, y));
  }
  if (N == 1) {
    cout << 0.0000000 << endl;
    return 0;
  }
  vector<point> CH = ConvexHull(V);
  vector<point> A = CH_form(CH, R);
  A = ConvexHull(A);
  cout << setprecision(10) << fixed;
  cout << Calculus_answer(A) << endl;
  return 0;
}
