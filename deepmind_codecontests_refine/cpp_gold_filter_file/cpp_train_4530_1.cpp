#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &t) {
  os << "[";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &t) {
  os << "{";
  for (__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++) {
    if (it != t.begin()) os << ",";
    os << *it;
  }
  os << "}";
  return os;
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &t) {
  return os << "(" << t.first << "," << t.second << ")";
}
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
  return pair<S, T>(s.first - t.first, s.second - t.second);
}
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
int n, r, v;
double solve1(double s) {
  double l = 1e-9, h = 1e9;
  for (int _ = 0; _ < (int)(60); _++) {
    double t = (l + h) / 2;
    if (-r * sin(v * t / r) + v * t < s)
      l = t;
    else
      h = t;
  }
  return l;
}
double solve2(double s) {
  double l = 1e-9, h = 1e9;
  for (int _ = 0; _ < (int)(60); _++) {
    double t = (l + h) / 2;
    if (r * sin(v * t / r) + v * t < s)
      l = t;
    else
      h = t;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d%d%d", &n, &r, &v);
  vector<int> d(n);
  for (int i = 0; i < (int)(n); i++) {
    int s, f;
    scanf("%d%d", &s, &f);
    int w = f - s;
    double ans = 2 * min(solve1(w / 2.) - solve1(-w / 2.),
                         solve2(w / 2.) - solve2(-w / 2.));
    printf("%.20f\n", (double)ans);
  }
  return 0;
}
