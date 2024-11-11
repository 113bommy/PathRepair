#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
long long ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  int x1 = p2.first - p1.first, x2 = p3.first - p2.first,
      fdsafdsa = p2.second - p1.second, y2 = p3.second - p2.second;
  return x1 * 1ll * y2 - x2 * 1ll * fdsafdsa;
}
long long getpos(pair<int, int> p, int X, int Y) {
  long long cc = p.first * 1ll * Y - p.second * 1ll * X;
  if (cc < 0)
    return -1;
  else if (cc > 0)
    return 1;
  return 0;
}
long long getd(long long a11, long long a12, long long a21, long long a22) {
  return a11 * a22 - a12 * a21;
}
double getx(pair<int, int> p1, pair<int, int> p2, int X, int Y) {
  long long a1 = p1.second - p2.second;
  long long b1 = p2.first - p1.first;
  long long c1 = -p1.first * a1 - p1.second * b1;
  long long a2 = -Y;
  long long b2 = X;
  long long c2 = 0;
  return getd(-c1, b1, -c2, b2) * 1. / getd(a1, b1, a2, b2);
}
int main() {
  int n;
  cin >> n;
  int X, Y;
  cin >> X >> Y;
  vector<pair<int, int> > v;
  int maxx = 0, maxy = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    maxx = max(x, maxx);
    maxy = max(y, maxy);
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  vector<pair<int, int> > st;
  st.push_back(make_pair(0, maxy));
  for (int i = 0; i < n; i++) {
    if (st.size() < 2) {
      st.push_back(v[i]);
    } else {
      if (ccw(st[st.size() - 2], st[st.size() - 1], v[i]) > 0) {
        st.pop_back();
        i--;
        continue;
      }
      st.push_back(v[i]);
    }
  }
  st.push_back(make_pair(maxx, 0));
  for (int i = 0; i < (int)st.size() - 1; i++) {
    if (getpos(st[i], X, Y) * getpos(st[i + 1], X, Y) != 1) {
      double x = getx(st[i], st[i + 1], X, Y);
      double ans = X / x;
      cout.precision(10);
      cout << fixed << ans << "\n";
      return 0;
    }
  }
  return 0;
}
