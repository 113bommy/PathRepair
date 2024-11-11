#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
using namespace std;
const int maxn = (int)1e5 + 10;
struct vt {
  long double x, y;
};
vt operator-(vt a, vt b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}
vt operator+(vt a, vt b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}
vt operator*(vt a, long double x) {
  a.x *= x;
  a.y *= x;
  return a;
}
long double dst(vt a) { return hypotl(a.x, a.y); }
vt operator/(vt a, long double x) {
  a.x /= x;
  a.y /= x;
  return a;
}
const long double eps = 1e-18;
vector<vt> inter(vt a, long double r) {
  long double d = dst(a);
  if (d * d <= r * r) {
    return {};
  }
  long double x = r * r / d;
  long double y = r * sqrt(1. - (r / d) * (r / d));
  vt b = a * (x / dst(a));
  vt n = {-a.y, a.x};
  n = n / dst(n);
  return {b - n * y, b + n * y};
}
long double operator*(vt a, vt b) { return a.x * b.y - a.y * b.x; }
int tp(vt a) { return a.y > eps || (abs(a.y) < eps && a.x > eps); }
vt v[maxn];
bool operator<(vt a, vt b) {
  int tpa = tp(a);
  int tpb = tp(b);
  if (tpa != tpb) {
    return tpa < tpb;
  }
  return a * b > eps;
}
int tr[4 * maxn];
void change(int pos) {
  for (; pos < maxn; pos |= pos + 1) {
    tr[pos]++;
  }
}
int go(int pos) {
  int ans = 0;
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
    ans += tr[pos];
  }
  return ans;
}
int go(int l, int r) { return go(r) - go(l - 1); }
ostream& operator<<(ostream& out, vt a) { return out << a.x << ' ' << a.y; }
mt19937 rr;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v[i].x >> v[i].y;
  }
  k = (long long)n * (n - 1) / 2 - k;
  long double l = 0;
  long double r = sqrt(2.) * 1e4;
  for (int itr = 0; itr < 36; itr++) {
    long double m = (l + r) / 2;
    vector<vt> g;
    vector<pair<vt, vt> > f;
    for (int i = 0; i < n; i++) {
      auto a = inter(v[i], m);
      if (a.empty()) {
        continue;
      }
      f.push_back(make_pair(a[0], a[1]));
      g.push_back(a[0]);
      g.push_back(a[1]);
    }
    sort((g).begin(), (g).end());
    vector<pair<int, int> > a;
    memset(tr, 0, sizeof tr);
    for (int i = 0; i < (int)f.size(); i++) {
      a.push_back(make_pair(
          lower_bound((g).begin(), (g).end(), f[i].first) - g.begin(),
          lower_bound((g).begin(), (g).end(), f[i].second) - g.begin()));
      if (a.back().first > a.back().second) {
        change(a.back().second);
        a.back().second += (int)g.size();
      }
    }
    sort((a).begin(), (a).end());
    long long tot = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      tot += go(a[i].first, a[i].second);
      change(a[i].second);
    }
    if (tot <= k) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%.10lf\n", (double)r);
}
