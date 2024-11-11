#include <bits/stdc++.h>
using namespace std;
class mstream {
 private:
  int res = 0;
  bool right = 0, sign = 0, space = 0, zero = 0;
  int width = 0, precision = 0, maxwidth = 1e6;
  string interval = "";
  const char* formstr(bool ri, bool si, bool sp, bool ze, bool wi, bool pr,
                      string ty) {
    string f = "%";
    if (ri && right) f += "-";
    if (si && sign) f += "+";
    if (sp && space) f += " ";
    if (ze && zero) f += "0";
    if (wi) f += "*";
    if (pr) f += ".*";
    f += ty;
    f += "%s";
    return f.c_str();
  }

 public:
  operator int() { return res; }
  mstream() {}
  mstream operator()() {
    res = 0;
    return *this;
  }
  mstream setright(bool n = 1) {
    right = n;
    return *this;
  }
  mstream setleft(bool n = 1) {
    right = !n;
    return *this;
  }
  mstream setsign(bool n = 1) {
    sign = n;
    return *this;
  }
  mstream notsign(bool n = 1) {
    sign = !n;
    return *this;
  }
  mstream setspace(bool n = 1) {
    space = n;
    return *this;
  }
  mstream notspace(bool n = 1) {
    space = !n;
    return *this;
  }
  mstream setzero(bool n = 1) {
    zero = n;
    return *this;
  }
  mstream notzero(bool n = 1) {
    zero = !n;
    return *this;
  }
  mstream setwidth(int n = 0) {
    width = n;
    return *this;
  }
  mstream setprecision(int n = 6) {
    precision = n;
    return *this;
  }
  mstream setmaxwidth(int n = 1e6) {
    maxwidth = n;
    return *this;
  }
  mstream setinterval(string n = " ") {
    interval = n;
    return *this;
  }
  mstream notinterval(string n = "") {
    interval = n;
    return *this;
  }
  mstream operator>>(int& x) {
    int r = scanf("%d", &x);
    if (r != EOF) res += r;
    return *this;
  }
  mstream operator>>(long long& x) {
    int r = scanf("%I64d", &x);
    if (r != EOF) res += r;
    return *this;
  }
  mstream operator>>(float& x) {
    int r = scanf("%f", &x);
    if (r != EOF) res += r;
    return *this;
  }
  mstream operator>>(double& x) {
    int r = scanf("%lf", &x);
    if (r != EOF) res += r;
    return *this;
  }
  mstream operator>>(char& x) {
    int r = scanf("%c", &x);
    if (r != EOF) res += r;
    return *this;
  }
  mstream operator>>(string& x) {
    char s[maxwidth + 1];
    int r = scanf("%s", s);
    if (r != EOF) x = s, res += r;
    return *this;
  }
  mstream operator<<(int x) {
    int r = printf(formstr(1, 1, 1, 1, 1, 0, "d"), width, x, interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
  mstream operator<<(long long x) {
    int r =
        printf(formstr(1, 1, 1, 1, 1, 0, "I64d"), width, x, interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
  mstream operator<<(float x) {
    int r = printf(formstr(1, 1, 1, 1, 1, 1, "f"), width, precision, x,
                   interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
  mstream operator<<(double x) {
    int r = printf(formstr(1, 1, 1, 1, 1, 1, "lf"), width, precision, x,
                   interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
  mstream operator<<(char x) {
    int r = printf(formstr(1, 0, 0, 1, 1, 0, "c"), width, x, interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
  mstream operator<<(string x) {
    int r = printf(formstr(1, 0, 0, 1, 1, 1, "s"), width, maxwidth, x.c_str(),
                   interval.c_str());
    if (r > 0) res += r;
    return *this;
  }
};
mstream mstr = mstream();
int main() {
  int q;
  mstr >> q;
  for (long long i = 0, i_TO = q; i < i_TO; i++) {
    int n;
    mstr >> n;
    int d = n / 4, m = n % 4;
    if (m == 0)
      mstr << d << '\n';
    else if (m == 1) {
      if (d >= 2)
        mstr << d - 1 << '\n';
      else
        mstr << -1 << '\n';
    } else if (m == 2) {
      if (d >= 1)
        mstr << d << '\n';
      else
        mstr << -1 << '\n';
    } else {
      if (d >= 3)
        mstr << d - 1 << '\n';
      else
        mstr << -1 << '\n';
    }
  }
}
