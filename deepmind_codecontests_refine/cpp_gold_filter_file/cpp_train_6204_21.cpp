#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, const pair<T1, T2>& p) {
  os << "[" << p.first << ", " << p.second << "]";
  return os;
}
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  bool first = true;
  for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end();
       ++it) {
    if (!first) os << ", ";
    first = false;
    os << *it;
  }
  os << "]";
  return os;
}
vector<string> _split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return v;
}
void _print(vector<string>::iterator) {}
template <typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
  string name = it->substr((*it)[0] == ' ', it->length());
  if (isalpha(name[0]))
    cerr << name << " = " << a << " ";
  else
    cerr << name << " ";
  _print(++it, args...);
}
const int N = (int)2e5;
const long double EPS = 1e-12;
const long double ldouble_INF = 1e18;
bool eq(long double a, long double b) { return fabsl(a - b) < EPS; }
bool ls(long double a, long double b) { return a < b && !eq(a, b); }
int n;
int x1, y1y1y1, x2, y2;
int start_x_list[N], start_y_list[N], vx_list[N], vy_list[N];
bool check_zero() {
  for (int i = 0; i < n; i++) {
    if (start_x_list[i] <= x1 || start_x_list[i] >= x2 ||
        start_y_list[i] <= y1y1y1 || start_y_list[i] >= y2)
      return false;
  }
  return true;
}
void fail() {
  printf("-1\n");
  exit(0);
}
pair<long double, long double> get_t(int start_x, int vx, int l, int r) {
  if (l < start_x && start_x < r) {
    long double t1 = 0;
    long double t2 = ldouble_INF;
    if (vx > 0) {
      t2 = fabsl((long double)(start_x - r) / vx);
    } else {
      t2 = fabsl((long double)(start_x - l) / vx);
    }
    return make_pair(t1, t2);
  }
  if (vx == 0) fail();
  if (vx > 0) {
    if (start_x >= r) fail();
    long double t1 = fabsl((long double)(l - start_x) / vx);
    long double t2 = fabsl((long double)(r - start_x) / vx);
    return make_pair(t1, t2);
  } else {
    if (start_x <= l) fail();
    long double t1 = fabsl((long double)(r - start_x) / vx);
    long double t2 = fabsl((long double)(l - start_x) / vx);
    return make_pair(t1, t2);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &x1, &y1y1y1, &x2, &y2);
  for (int i = 0; i < n; i++)
    scanf("%d%d%d%d", &start_x_list[i], &start_y_list[i], &vx_list[i],
          &vy_list[i]);
  if (x1 == x2 || y1y1y1 == y2) fail();
  if (check_zero()) {
    printf("0\n");
    return 0;
  }
  long double t_in = -ldouble_INF;
  long double t_out = ldouble_INF;
  for (int i = 0; i < n; i++) {
    pair<long double, long double> p1 =
        get_t(start_x_list[i], vx_list[i], x1, x2);
    pair<long double, long double> p2 =
        get_t(start_y_list[i], vy_list[i], y1y1y1, y2);
    t_in = max(t_in, p1.first);
    t_in = max(t_in, p2.first);
    t_out = min(t_out, p1.second);
    t_out = min(t_out, p2.second);
  }
  if (ls(t_in, t_out))
    printf("%.10lf\n", (double)t_in);
  else
    fail();
  return 0;
}
