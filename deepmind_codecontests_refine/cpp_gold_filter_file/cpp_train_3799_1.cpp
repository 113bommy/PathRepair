#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-12;
struct circle;
struct line;
struct segment;
struct half_line;
template <class a, class b>
pair<a, b> operator+(pair<a, b> x, pair<a, b> y) {
  return (pair<a, b>(x.first + y.first, x.second + y.second));
}
template <class a, class b>
pair<a, b> operator-(pair<a, b> x, pair<a, b> y) {
  return (pair<a, b>(x.first - y.first, x.second - y.second));
}
namespace std {
inline bool operator<(const complex<long double> &s,
                      const complex<long double> &t) {
  if (abs(s.real() - t.real()) > EPS) return (s.real() < t.real());
  if (abs(s.imag() - t.imag()) > EPS) return (s.imag() < t.imag());
  return (false);
}
}  // namespace std
struct circle {
  complex<long double> cen;
  long double r;
  circle(complex<long double> x, long double y) {
    cen = x;
    r = y;
  }
  bool is_in(const complex<long double> &s) const {
    return (abs(cen - s) <= r + EPS);
  }
  bool is_on(const complex<long double> &s) const {
    return (abs(abs(cen - s) - r) < EPS);
  }
  vector<complex<long double> > intersection(const circle &s) const;
  vector<complex<long double> > intersection(const line &s) const;
  vector<complex<long double> > intersection(const segment &s) const;
  vector<complex<long double> > intersection(const half_line &s) const;
};
struct line {
  complex<long double> a, b;
  line(complex<long double> x, complex<long double> y) {
    a = x;
    b = y;
  }
  bool is_on(const complex<long double> &s) const {
    complex<long double> A = a, B = b, C = s;
    if (B < A) swap(A, B);
    if (C < A) swap(A, C);
    if (C < B) swap(B, C);
    return (abs(abs(A - C) - abs(A - B) - abs(B - C)) < EPS);
  }
  vector<complex<long double> > intersection(const circle &s) const;
  vector<complex<long double> > intersection(const line &s) const;
  vector<complex<long double> > intersection(const segment &s) const;
  vector<complex<long double> > intersection(const half_line &s) const;
};
struct segment {
  complex<long double> a, b;
  segment(complex<long double> x, complex<long double> y) : a(x), b(y) {}
  bool is_on(const complex<long double> &s) const {
    return (abs(abs(a - b) - abs(a - s) - abs(b - s)) < EPS);
  }
  vector<complex<long double> > intersection(const circle &s) const;
  vector<complex<long double> > intersection(const line &s) const;
  vector<complex<long double> > intersection(const segment &s) const;
  vector<complex<long double> > intersection(const half_line &s) const;
};
struct half_line {
  complex<long double> a, b;
  half_line(complex<long double> x, complex<long double> y) : a(x), b(y) {}
  bool is_on(const complex<long double> &s) const {
    if ((b < a) != (s < a)) return (false);
    return (line(a, b).is_on(s));
  }
  vector<complex<long double> > intersection(const circle &s) const;
  vector<complex<long double> > intersection(const line &s) const;
  vector<complex<long double> > intersection(const segment &s) const;
  vector<complex<long double> > intersection(const half_line &s) const;
};
vector<complex<long double> > half_line::intersection(const circle &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans.back(), ans[i]);
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > half_line::intersection(const line &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > half_line::intersection(const segment &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > half_line::intersection(
    const half_line &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > segment::intersection(const circle &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans.back(), ans[i]);
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > segment::intersection(const line &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > segment::intersection(const segment &s) const {
  vector<complex<long double> > ans = line(a, b).intersection(s);
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
      i--;
    }
  return (ans);
}
vector<complex<long double> > segment::intersection(const half_line &s) const {
  return (s.intersection(*this));
}
vector<complex<long double> > line::intersection(const circle &s) const {
  complex<long double> cen = (s.cen - a) / (b - a);
  long double R = s.r / abs(b - a);
  if (abs(cen.imag()) > R + EPS) return (vector<complex<long double> >());
  vector<complex<long double> > ans;
  ans.push_back(complex<long double>(
      cen.real() - sqrt(pow(R, 2) - pow(cen.imag(), 2)), 0));
  if (abs(R - abs(cen.imag())) > EPS)
    ans.push_back(complex<long double>(
        cen.real() + sqrt(pow(R, 2) - pow(cen.imag(), 2)), 0));
  for (long long i = 0; i < ans.size(); i++) ans[i] = ans[i] * (b - a) + a;
  return (ans);
}
vector<complex<long double> > line::intersection(const line &s) const {
  complex<long double> A = (s.a - a) / (b - a), B = (s.b - a) / (b - a);
  if (abs(A.imag() - B.imag()) < EPS) return (vector<complex<long double> >());
  vector<complex<long double> > ans;
  ans.push_back(A + (B - A) * (A.imag() / (A - B).imag()));
  for (long long i = 0; i < ans.size(); i++) ans[i] = ans[i] * (b - a) + a;
  for (long long i = 0; i < ans.size(); i++)
    if (!is_on(ans[i])) {
      swap(ans[i], ans.back());
      ans.pop_back();
    }
  return (ans);
}
vector<complex<long double> > line::intersection(const segment &s) const {
  return (s.intersection(*this));
}
vector<complex<long double> > line::intersection(const half_line &s) const {
  return (s.intersection(*this));
}
vector<complex<long double> > circle::intersection(const circle &s) const {
  if (abs(cen - s.cen) < EPS) return (vector<complex<long double> >());
  long double r1 = r / (abs(cen - s.cen)), r2 = s.r / abs(cen - s.cen);
  if (abs(r1 - r2) > 1 + EPS) return (vector<complex<long double> >());
  if (r1 + r2 < 1) return (vector<complex<long double> >());
  long double x = 0.5 + (pow(r1, 2) - pow(r2, 2)) / 2;
  vector<complex<long double> > ans;
  ans.push_back(complex<long double>(x, sqrt(pow(r1, 2) - pow(x, 2))));
  if (abs(ans[0].imag()) > EPS)
    ans.push_back(complex<long double>(ans[0].real(), -ans[0].imag()));
  for (long long i = 0; i < ans.size(); i++)
    ans[i] = ans[i] * (s.cen - cen) + cen;
  return (ans);
}
vector<complex<long double> > circle::intersection(const line &s) const {
  return (s.intersection(*this));
}
vector<complex<long double> > circle::intersection(const segment &s) const {
  return (s.intersection(*this));
}
vector<complex<long double> > circle::intersection(const half_line &s) const {
  return (s.intersection(*this));
}
bool is_left(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.second * b.first > a.first * b.second);
}
long long cross(pair<long long, long long> a, pair<long long, long long> b) {
  return (a.first * b.second - a.second * b.first);
}
pair<long long, long long> rev(pair<long long, long long> s) {
  return (pair<long long, long long>(s.second, -s.first));
}
complex<long double> p(pair<long long, long long> s) {
  return (complex<long double>(s.first, s.second));
}
long double cross(complex<long double> s, complex<long double> t) {
  return (s.real() * t.imag() - t.real() * s.imag());
}
long double area(complex<long double> x, complex<long double> y,
                 complex<long double> z) {
  return (abs(cross(x, y) + cross(y, z) + cross(z, x)));
}
long long n;
long double cal(vector<pair<long long, long long> > num) {
  long long sum = 0, pointer = 1;
  long double ans = 1e20;
  for (long long i = 0; i < num.size(); i++) {
    while (is_left(num[(pointer + 1) % num.size()] - num[pointer],
                   rev(num[(i + 1) % num.size()] - num[i]))) {
      sum += cross(num[pointer], num[(pointer + 1) % num.size()]);
      pointer = (pointer + 1) % num.size();
    }
    if (pointer == (i + 1) % num.size()) {
      ans = 0;
      break;
    }
    vector<complex<long double> > q =
        line(p(num[i]), p(num[(i + 1) % num.size()]))
            .intersection(line(
                p(num[pointer]),
                p(num[pointer] + rev(num[(i + 1) % num.size()] - num[i]))));
    if (q.size()) {
      long double ar =
          area(p(num[(i + 1) % num.size()]), p(num[pointer]), q[0]);
      ans = min(ans,
                ar - abs(sum + cross(num[pointer], num[(i + 1) % num.size()])));
    }
    sum -= cross(num[(i + 1) % num.size()], num[(i + 2) % num.size()]);
  }
  return (ans);
}
int main() {
  cout << fixed;
  cout.precision(10);
  cin >> n;
  vector<pair<long long, long long> > num;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    num.push_back(pair<long long, long long>(a, b));
  }
  long double ans = cal(num);
  reverse(num.begin(), num.end());
  ans = min(ans, cal(num));
  cout << ans / 2 << endl;
}
