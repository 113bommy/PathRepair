#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <typename T>
T sqr(T a) {
  return a * a;
}
template <typename T>
int sign(T a) {
  if (a == 0) return 0;
  return (a > 0 ? 1 : -1);
}
template <typename T>
bool uax(T& a, const T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool uin(T& a, const T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
mt19937_64 rnd(0);
const int LOG = 64;
const int N = (int)3e5 + 7;
const int MAXN = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const int CONST = 450;
const long long LINF = (int64_t)1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1;
struct Vector {
  int x, y;
  Vector(){};
  Vector(int x, int y) : x(x), y(y){};
};
Vector operator-(const Vector& a, const Vector& b) {
  return Vector(a.x - b.x, a.y - b.y);
}
long long operator*(const Vector& a, const Vector& b) {
  return 1LL * a.x * b.y - 1LL * a.y * b.x;
}
long long operator%(const Vector& a, const Vector& b) {
  return 1LL * a.x * b.x + 1LL * a.y * b.y;
}
bool operator<(const Vector& a, const Vector& b) { return a * b < 0; }
int n, xl[N], xr[N], y[N];
vector<pair<int, int>> inc(vector<pair<int, int>>& v) {
  sort(v.begin(), v.end());
  vector<pair<int, int>> res;
  int ind = 0, n = (int)v.size();
  while (ind < n) {
    int l = v[ind].first, r = v[ind].second;
    while (ind < n && v[ind].first == l) r = v[ind++].second;
    res.push_back(make_pair(l, r));
  }
  return res;
}
vector<pair<int, int>> dec(vector<pair<int, int>>& v) {
  sort(v.rbegin(), v.rend());
  vector<pair<int, int>> res;
  int ind = 0, n = (int)v.size();
  while (ind < n) {
    int l = v[ind].first, r = v[ind].second;
    while (ind < n && v[ind].first == l) r = v[ind++].second;
    res.push_back(make_pair(l, r));
  }
  return res;
}
long double inter(const pair<int, int>& a, const pair<int, int>& b) {
  return (b.second - a.second + .0) / (a.first - b.first + .0);
}
struct CHT {
  vector<pair<int, int>> line;
  vector<long double> x;
  CHT(){};
  CHT(const vector<pair<int, int>>& v) {
    for (int i = 0; i < (int)v.size(); i++) {
      int len = (int)line.size();
      while (len > 1) {
        long double xcur = inter(v[i], line[len - 2]);
        if (x.back() >= xcur) {
          len--;
          x.pop_back();
          line.pop_back();
          continue;
        }
        break;
      }
      if ((int)line.size()) x.push_back(inter(line.back(), v[i]));
      line.push_back(v[i]);
    }
  }
  long double get(long double coord) {
    int pos = lower_bound(x.begin(), x.end(), coord) - x.begin();
    return coord * line[pos].first + line[pos].second;
  }
};
void solve() {
  cin >> n;
  vector<pair<int, int>> line;
  int xleft = INF, xright = -INF;
  for (int i = 0; i < n; i++) {
    cin >> xl[i] >> xr[i] >> y[i];
    line.push_back(make_pair(y[i], xl[i]));
    line.push_back(make_pair(y[i], xr[i]));
    uin(xleft, xl[i]);
    uax(xright, xr[i]);
  }
  vector<pair<Vector, Vector>> seg;
  bool fl = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (y[i] >= y[j]) continue;
      fl = true;
      Vector l = Vector(xr[i] - xl[j], y[i] - y[j]);
      Vector r = Vector(xl[i] - xr[j], y[i] - y[j]);
      seg.push_back(make_pair(l, r));
      seg.push_back(make_pair(r, r));
    }
  }
  if (!fl) {
    cout << double(xright - xleft);
    return;
  }
  auto vinc = inc(line), vdec = dec(line);
  CHT maxx = CHT(vinc), minn = CHT(vdec);
  sort(seg.begin(), seg.end());
  Vector r = Vector(1, 0), ox = Vector(1, 0);
  long double ans = LINF;
  for (int i = 0; i < (int)seg.size(); i++) {
    if (r * seg[i].first >= 0) {
      if (seg[i].second * r > 0) r = seg[i].second;
      continue;
    }
    long double cot = (seg[i].first % ox + .0) / (seg[i].first * ox + .0);
    long double xl = minn.get(cot), xr = maxx.get(cot);
    uin(ans, xr - xl);
    if (seg[i].second * r > 0) r = seg[i].second;
  }
  cout << ans;
}
int main() {
  double start = clock();
  cout << fixed << setprecision(20);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  rnd.seed(time(0));
  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}
