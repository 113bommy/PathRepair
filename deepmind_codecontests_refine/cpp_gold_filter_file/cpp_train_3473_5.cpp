#include <bits/stdc++.h>
#pragma warning(disable : 4786)
using namespace std;
template <class T>
int cntb(T i) {
  int ret = 0;
  while (i) i = (i - 1) & i, ret++;
  return ret;
}
template <class T>
int cntlz(T i) {
  int ret = 0;
  while (!((i) & (1 << 0)) && i) i /= 2, ret++;
  return ret;
}
template <class T>
T gcd(T a, T b) {
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
void frstring(string s, T& r) {
  r = 0;
  istringstream ci(s);
  ci >> r;
}
template <class T>
string tostring(T n) {
  ostringstream co;
  co << n;
  co.flush();
  return co.str();
}
template <class T>
T bigmod(T x, T n, T m) {
  T ret = 1;
  while (n > 0) {
    if (n % 2 == 1) ret = (ret * x) % m;
    x = (x * x) % m;
    n /= 2;
  }
  return ret;
}
vector<string> parse(char* ch, char* tk) {
  vector<string> ret;
  char* pch = strtok(ch, tk);
  while (pch != NULL) {
    ret.push_back(string(pch)), pch = strtok(NULL, tk);
  }
  return ret;
}
struct point {
  double x, y;
  point(double _x, double _y) {
    x = _x;
    y = _y;
  }
};
point operator-(point a) { return point(-a.x, -a.y); }
point operator-(point a, point b) { return point(a.x - b.x, a.y - b.y); }
point operator+(point a, point b) { return point(a.x + b.x, a.y + b.y); }
point operator/(point a, double b) { return point(a.x / b, a.y / b); }
point operator*(double a, point b) { return point(a * b.x, a * b.y); }
double operator*(point a, point b) { return a.x * b.y - a.y * b.x; }
double operator^(point a, point b) { return a.x * b.x - a.y * b.y; }
double mag(point a) { return sqrt(((a.x) * (a.x)) + ((a.y) * (a.y))); }
double dist(point a, point b) {
  return sqrt(((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y)));
}
point unit(point a) { return a / mag(a); }
double proj(point a, point b) { return a ^ unit(b); }
point projv(point a, point b) {
  point ub = unit(b);
  return (a ^ ub) * ub;
}
point rotate(point a, double ang) {
  point b = point(-a.y, a.x);
  return cos(ang) * a + sin(ang) * b;
}
int cn[10];
void f(string s) {
  int d = 1;
  int pos = 0;
  int i;
  for (i = (0); i <= (9); i++) cn[i] = 0;
  bool flag = 1;
  while (s.size() && flag) {
    if (isdigit(s[pos])) {
      cn[s[pos] - 48]++;
      if (s[pos] == '0') {
        s.erase(pos, 1);
        if (d == -1) pos--;
        if (pos < 0 || pos >= s.size()) flag = false;
      } else {
        s[pos] -= 1;
        pos += d;
        if (pos < 0 || pos >= s.size()) flag = false;
      }
    } else if (s[pos] == '<') {
      d = -1;
      pos--;
      if (pos < 0) {
        flag = false;
      } else if (!isdigit(s[pos])) {
        s.erase(pos + 1, 1);
      }
    } else if (s[pos] == '>') {
      d = 1;
      pos++;
      if (pos >= s.size()) {
        flag = false;
      } else if (!isdigit(s[pos])) {
        s.erase(pos - 1, 1);
        pos--;
      }
    }
  }
}
int main() {
  int i, j, k;
  int a, b, c;
  int y, n;
  int q;
  string real;
  cin >> n >> q;
  cin >> real;
  for (i = (0); i < (q); i++) {
    int l, r;
    cin >> l >> r;
    f(real.substr(l - 1, r - l + 1));
    for (j = (0); j <= (9); j++) {
      cout << cn[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
