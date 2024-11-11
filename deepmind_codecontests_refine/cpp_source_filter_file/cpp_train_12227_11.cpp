#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& val) {
  return out << "(" << val.first << ", " << val.second << ")";
}
template <class T>
ostream& operator<<(ostream& out, const vector<T>& val) {
  out << "{";
  for (int i = 0; i < (int)((int)((val).size())); ++i)
    out << (i ? ", " : "") << val[i];
  return out << "}";
}
namespace std {
bool operator<(const complex<double>& a, const complex<double>& b) {
  if (abs(a.real() - b.real()) > (1e-6)) return a.real() < b.real();
  return a.imag() < b.imag();
}
}  // namespace std
double dot(complex<double> a, complex<double> b) { return real(conj(a) * b); }
double crs(complex<double> a, complex<double> b) { return imag(conj(a) * b); }
complex<double> ortho(complex<double> a) {
  return complex<double>(imag(a), -real(a));
}
complex<double> ortho(pair<complex<double>, complex<double> > a) {
  return ortho(a.second - a.first);
}
complex<double> crspt(complex<double> a, complex<double> b, complex<double> c,
                      complex<double> d) {
  b -= a, d -= c;
  return a + b * crs(d, c - a) / crs(d, b);
}
complex<double> crspt(pair<complex<double>, complex<double> > a,
                      pair<complex<double>, complex<double> > b) {
  return crspt(a.first, a.second, b.first, b.second);
}
bool onl(complex<double> a1, complex<double> a2, complex<double> b) {
  return abs(b - a1) + abs(b - a2) < abs(a1 - a2) + (1e-6);
}
bool onl(pair<complex<double>, complex<double> > a, complex<double> b) {
  return onl(a.first, a.second, b);
}
bool iscrs(pair<complex<double>, complex<double> > a,
           pair<complex<double>, complex<double> > b) {
  complex<double> c = crspt(a, b);
  return onl(a, c) && onl(b, c);
}
void pkuassert(bool t) { t = 1 / t; };
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
enum { TOP, BTM, LFT, RGT, FRT, BCK };
int dxdy2ce[] = {RGT, FRT, LFT, BCK};
int s2i(string& a) {
  stringstream ss(a);
  int r;
  ss >> r;
  return r;
}
template <class T>
T shift(T a, int b, int c, int d, int e) {
  __typeof(a[0]) t = a[b];
  a[b] = a[c];
  a[c] = a[d];
  a[d] = a[e];
  a[e] = t;
  return a;
}
template <class T>
T rgt(T a) {
  return shift(a, TOP, LFT, BTM, RGT);
}
template <class T>
T lft(T a) {
  return shift(a, TOP, RGT, BTM, LFT);
}
template <class T>
T frt(T a) {
  return shift(a, TOP, BCK, BTM, FRT);
}
template <class T>
T bck(T a) {
  return shift(a, TOP, FRT, BTM, BCK);
}
pair<complex<double>, complex<double> > mkl(complex<double> a,
                                            complex<double> v) {
  return pair<complex<double>, complex<double> >(a, a + v);
}
double lpdist(pair<complex<double>, complex<double> > a, complex<double> b) {
  return abs(b - crspt(a, mkl(b, ortho(a))));
}
double spdist(pair<complex<double>, complex<double> > a, complex<double> b) {
  complex<double> c(crspt(a, mkl(b, ortho(a))));
  return onl(a, c) ? abs(b - c) : min(abs(a.first - b), abs(a.second - b));
}
double ssdist(pair<complex<double>, complex<double> > a,
              pair<complex<double>, complex<double> > b) {
  return iscrs(a, b)
             ? 0.
             : min((spdist(a, b.first)),
                   min(((spdist(a, b.second))),
                       min(((spdist(b, a.first))), ((spdist(b, a.second))))));
}
int main(int argc, char* argv[]) {
  int n, m;
  cin >> n >> m;
  double ans = 0;
  vector<double> in(n);
  for (int i = 0; i < (int)(n); ++i) cin >> in[i];
  for (int i = 0; i < (int)(m); ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    ans = max(ans, (in[a] + in[b]) / c);
  }
  printf("%.8f\n", ans);
  return 0;
}
