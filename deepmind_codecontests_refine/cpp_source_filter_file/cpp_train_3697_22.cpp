#include <bits/stdc++.h>
using namespace std;
const long double INF = 1e200;
const long double EPS = 1e-9;
struct point {
  long double x, y;
};
point operator-(const point &a, const point &b) {
  return (point){a.x - b.x, a.y - b.y};
}
long double operator*(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}
long double operator^(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
long double tan(const point &a, const point &b) {
  long double s = a ^ b, c = a * b;
  return c == 0 ? INF : s / c;
}
point perp(const point &p) { return (point){-p.y, p.x}; }
struct line {
  long double a, b, c;
};
point inter(const line &p, const line &q) {
  long double det = p.a * q.b - p.b * q.a;
  long double detX = p.c * q.b - p.b * q.c;
  long double detY = p.a * q.c - p.c * q.a;
  return (point){detX / det, detY / det};
}
const int MAXN = 2010;
int n;
line l[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < (int)(n); i++) cin >> l[i].a >> l[i].b >> l[i].c;
  long long int res = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (l[i].c == 0) {
      bool good = false;
      for (int j = i + 1; j < n; j++)
        if (l[j].c == 0) good = true;
      if (good) res += n - i - 2;
      continue;
    }
    vector<long double> ang;
    for (int j = i + 1; j < n; j++) {
      point n1 = (point){l[j].a, l[j].b};
      point x = inter(l[i], l[j]);
      point n2 = perp(x);
      ang.push_back(tan(n1, n2));
    }
    sort(ang.begin(), ang.end());
    int racha = 1;
    for (int j = 1; j < ((int)(ang).size()); j++) {
      if (fabs(ang[j] - ang[j - 1]) < EPS)
        res += racha++;
      else
        racha = 1;
    }
  }
  cout << res << endl;
  return 0;
}
