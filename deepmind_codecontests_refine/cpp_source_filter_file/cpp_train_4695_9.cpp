#include <bits/stdc++.h>
using namespace std;
template <typename T>
T getint() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') p = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * p;
}
mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
bool umin(T1 &x, const T2 &y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, const T2 &y) {
  if (x < y) return x = y, true;
  return false;
}
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = (int)1e9 + 7;
const long long llinf = (long long)1e18 + 5;
const long double pi = acos(-1.0);
struct pt {
  int x, y;
};
long long get(pt a, pt b, pt c) {
  return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
}
vector<pt> convex(vector<pt> p) {
  sort(p.begin(), p.end(),
       [&](pt a, pt b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
  pt A = p[0];
  pt B = p.back();
  vector<pt> u, d;
  u.push_back(A);
  d.push_back(A);
  for (int i = 1; i < p.size(); ++i) {
    if (i + 1 == p.size() || get(A, p[i], B) < 0) {
      while (u.size() > 1 && get(u[u.size() - 2], u[u.size() - 1], p[i]) >= 0) {
        u.pop_back();
      }
      u.push_back(p[i]);
    }
    if (i + 1 == p.size() || get(A, p[i], B) > 0) {
      while (d.size() > 1 && get(d[d.size() - 2], d[d.size() - 1], p[i]) <= 0) {
        d.pop_back();
      }
      d.push_back(p[i]);
    }
  }
  vector<pt> ret = u;
  for (int i = d.size() - 2; i > 0; --i) ret.push_back(d[i]);
  return ret;
}
long long dist(pt a, pt b) {
  return (a.x - b.x) * 1LL * (a.x - b.x) + (a.y - b.y) * 1LL * (a.y - b.y);
}
bool ok(vector<tuple<long long, long long, long long>> a,
        vector<tuple<long long, long long, long long>> b) {
  auto s = b;
  s.push_back(make_tuple(-1, 0, 0));
  s.insert(s.end(), a.begin(), a.end());
  int l = 0, r = 0;
  int n = s.size();
  vector<int> z(n);
  for (int i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = min(z[i - l], r - i + 1);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 >= r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  for (int i = 1; i < n; ++i) {
    if (z[i] == b.size()) return true;
  }
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<pt> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i].x >> b[i].y;
  }
  a = convex(a);
  b = convex(b);
  if (a.size() != b.size()) {
    cout << "NO\n";
    return 0;
  }
  n = a.size();
  a.push_back(a[0]);
  a.push_back(a[1]);
  b.push_back(b[0]);
  b.push_back(b[1]);
  vector<tuple<long long, long long, long long>> ca;
  for (int i = 0; i < n; ++i) {
    long long A = dist(a[i], a[i + 1]);
    long long B = dist(a[i + 1], a[i + 2]);
    long long C = dist(a[i + 2], a[i]);
    ca.push_back(make_tuple(A, B, C));
  }
  for (int i = 0; i < n; ++i) ca.push_back(ca[i]);
  vector<tuple<long long, long long, long long>> cb;
  for (int i = 0; i < n; ++i) {
    long long A = dist(b[i], b[i + 1]);
    long long B = dist(b[i + 1], b[i + 2]);
    long long C = dist(b[i + 2], b[i]);
    cb.push_back(make_tuple(A, B, C));
  }
  cout << (ok(ca, cb) ? "YES" : "NO") << endl;
  return 0;
}
