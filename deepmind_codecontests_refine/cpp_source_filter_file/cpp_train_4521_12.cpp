#include <bits/stdc++.h>
using namespace std;
double eps = 0.000000001;
struct line {
  double a, b;
  double sx, fx;
  line(double a_, double b_, double sx_, double fx_) {
    a = a_;
    b = b_;
    sx = sx_;
    fx = fx_;
  }
  double inX(double x) { return a * x + b; }
  double f() { return (inX(fx) + inX(sx)) * (fx - sx) / 2; }
};
bool over(line a, line b) {
  double sx = b.sx;
  double fx = b.fx;
  return a.inX(sx) >= b.inX(sx) && a.inX(fx) >= b.inX(fx);
}
double crossX(line a, line b) { return (b.b - a.b) / (a.a - b.a); }
vector<line> erase(vector<line> v, int ind) {
  vector<line> ret;
  for (int i = 0; i < v.size(); i++) {
    if (i != ind) {
      ret.push_back(v[i]);
    }
  }
  return ret;
}
vector<line> insert(vector<line> v, int ind, line e) {
  vector<line> ret;
  for (int i = 0; i < ind; i++) {
    ret.push_back(v[i]);
  }
  ret.push_back(e);
  for (int i = ind; i < v.size(); i++) {
    ret.push_back(v[i]);
  }
  return ret;
}
vector<double> ans(vector<pair<int, int> > input) {
  vector<line> hull;
  hull.push_back(line(0, 0, 0, 1));
  vector<double> ret;
  int n = input.size();
  for (int i = 0; i < n; i++) {
    double diff = 0;
    int y1, y2;
    y1 = input[i].first;
    y2 = input[i].second;
    line crr = line(y2 - y1, y1, 0, 1);
    int ind = 0;
    for (; ind < hull.size() && hull[ind].b >= crr.b; ind++) {
    }
    bool failed = 1;
    while (ind - 1 >= 0 && over(crr, hull[ind - 1])) {
      diff += line(crr.a, crr.b, hull[ind - 1].sx, hull[ind - 1].fx).f() -
              hull[ind - 1].f();
      hull = erase(hull, ind - 1);
      ind--;
      failed = 0;
    }
    while (ind < hull.size() && over(crr, hull[ind])) {
      diff +=
          line(crr.a, crr.b, hull[ind].sx, hull[ind].fx).f() - hull[ind].f();
      hull = erase(hull, ind);
      failed = 0;
    }
    if (failed) {
    }
    double sx = 0;
    double fx = 1;
    if (ind - 1 >= 0) {
      if (crr.inX(hull[ind - 1].fx) > hull[ind - 1].inX(hull[ind - 1].fx)) {
        sx = crossX(hull[ind - 1], crr);
      } else {
        sx = hull[ind - 1].fx;
      }
    }
    if (ind < hull.size()) {
      if (crr.inX(hull[ind].sx) > hull[ind].inX(hull[ind].sx)) {
        fx = crossX(hull[ind], crr);
      } else {
        fx = hull[ind].sx;
      }
    }
    crr.sx = sx;
    crr.fx = fx;
    if (fx - sx < eps) {
      ret.push_back(0);
      break;
    }
    if (ind - 1 >= 0) {
      diff += line(crr.a, crr.b, sx, hull[ind - 1].fx).f() -
              line(hull[ind - 1].a, hull[ind - 1].b, sx, hull[ind - 1].fx).f();
      hull[ind - 1].fx = sx;
    }
    if (ind < hull.size()) {
      diff += line(crr.a, crr.b, hull[ind].sx, fx).f() -
              line(hull[ind].a, hull[ind].b, hull[ind].sx, fx).f();
      hull[ind].sx = fx;
    }
    hull = insert(hull, ind, crr);
    for (int j = 0; j < hull.size(); j++) {
    }
    ret.push_back(diff);
  }
  return ret;
}
double rr[1024];
vector<int> input[1024];
vector<double> answers[1024];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      int t;
      cin >> t;
      input[i].push_back(t);
    }
  }
  for (int i = 0; i < k; i++) {
    vector<pair<int, int> > crr;
    for (int j = 0; j < n; j++) {
      crr.push_back(make_pair(input[j][i], input[j][i + 1]));
    }
    answers[i] = ans(crr);
    for (int j = 0; j < n; j++) {
      rr[j] += answers[i][j];
    }
  }
  cout << setprecision(10) << fixed;
  for (int i = 0; i < n; i++) {
    cout << rr[i] << "\n";
  }
  return 0;
}
