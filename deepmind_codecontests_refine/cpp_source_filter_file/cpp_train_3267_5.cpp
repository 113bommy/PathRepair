#include <bits/stdc++.h>
using namespace std;
double prodesc(complex<double> p1, complex<double> p2) {
  return real(conj(p1) * p2);
}
double prodvec(complex<double> p1, complex<double> p2) {
  return imag(conj(p1) * p2);
}
double error = 0.00000000001;
void llegeix(complex<double> &p) {
  int x, y;
  cin >> x >> y;
  p = complex<double>(x, y);
}
int n;
vector<complex<double> > poligon;
complex<double> a;
complex<double> v;
double vz;
double fdown;
complex<double> u;
double uz;
pair<double, double> tminim;
bool hihatminim;
complex<double> vfora;
void nout(pair<double, double> t) {
  if ((not hihatminim) or t < tminim) {
    tminim = t;
    hihatminim = true;
  }
}
complex<double> computavfora() {
  double time = vz / uz;
  return v + time * u;
}
complex<double> interseccio(complex<double> p1, complex<double> u1,
                            complex<double> p2, complex<double> u2) {
  return p1 + (prodvec(p2 - p1, u2) / prodvec(u1, u2)) * u1;
}
void interseccio(complex<double> p1, complex<double> u1, complex<double> p2,
                 complex<double> u2, complex<double> &p,
                 bool &hihainterseccio) {
  p = p1 + (prodvec(p2 - p1, u2) / prodvec(u1, u2)) * u1;
  if (prodesc(u1, p - p1) > -error and prodesc(u2, p - p2) > -error and
      prodesc(-u2, p - (p2 + u2)) > -error)
    hihainterseccio = true;
  else
    hihainterseccio = false;
}
void computapuntnoparalel(complex<double> p) {
  if ((prodvec(v, vfora) > 0 and prodvec(v, p - a) > -error and
       prodvec(p - a, vfora) > -error) or
      (prodvec(v, vfora) < 0 and prodvec(v, p - a) < error and
       prodvec(p - a, vfora) < error)) {
    complex<double> inter = interseccio(a, v, p, u);
    double vtime = abs(inter - a) / abs(v);
    double vh = vtime * vz;
    double utime = abs(inter - p) / abs(u);
    double uh = utime * uz;
    double ftime = (vh - uh) / fdown;
    nout(pair<double, double>(vtime, ftime));
  }
}
void computaminimnoparalel() {
  hihatminim = false;
  vfora = computavfora();
  for (int i = 0; i < n; i++) {
    complex<double> p = poligon[i];
    computapuntnoparalel(p);
    complex<double> pnext = poligon[(i + 1) % n];
    bool hihainterseccio;
    complex<double> inter;
    if (abs(prodvec(v, pnext - p)) > error) {
      interseccio(a, v, p, pnext - p, inter, hihainterseccio);
      if (hihainterseccio) computapuntnoparalel(inter);
    }
    if (abs(prodvec(vfora, pnext - p)) > error) {
      interseccio(a, vfora, p, pnext - p, inter, hihainterseccio);
      if (hihainterseccio) computapuntnoparalel(inter);
    }
  }
}
void computapuntcaiguda(complex<double> p) {
  if (abs(v) < error) return;
  if (abs(prodvec(v, p - a)) > error) return;
  if (prodesc(v, p - a) < -error) return;
  double vtime = abs(p - a) / abs(v);
  double vh = vtime * vz;
  double ftime = vh / fdown;
  nout(pair<double, double>(vtime, ftime));
}
void computapuntnocaiguda(complex<double> p) {
  complex<double> dir = v;
  if (abs(v) < error) dir = u;
  dir = dir / abs(dir);
  if (abs(prodvec(dir, p - a)) > error) return;
  complex<double> vv(prodesc(v, dir), vz);
  complex<double> uu(prodesc(u, dir), -uz);
  complex<double> pp(prodesc(p - a, dir), 0);
  complex<double> aa(0, 0);
  if (abs(prodvec(vv, uu)) < error) return;
  complex<double> inter = interseccio(aa, vv, pp, uu);
  double vtime = abs(inter - aa) / abs(vv);
  if (prodesc(vv, inter - aa) < error) return;
  if (prodesc(uu, pp - inter) < error) return;
  nout(pair<double, double>(vtime, 0));
}
void computaminimparalel() {
  hihatminim = false;
  for (int i = 0; i < n; i++) {
    complex<double> p = poligon[i];
    computapuntcaiguda(p);
    computapuntnocaiguda(p);
    complex<double> pnext = poligon[(i + 1) % n];
    complex<double> dir = v;
    if (abs(v) < error) dir = u;
    bool hihainterseccio;
    complex<double> inter;
    if (abs(prodvec(dir, pnext - p)) > error) {
      interseccio(a, dir, p, pnext - p, inter, hihainterseccio);
      if (hihainterseccio) {
        computapuntcaiguda(inter);
        computapuntnocaiguda(inter);
      }
      interseccio(a, -dir, p, pnext - p, inter, hihainterseccio);
      if (hihainterseccio) {
        computapuntcaiguda(inter);
        computapuntnocaiguda(inter);
      }
    }
  }
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(8);
  cin >> n;
  poligon = vector<complex<double> >(n);
  for (int i = 0; i < n; i++) llegeix(poligon[i]);
  llegeix(a);
  llegeix(v);
  cin >> vz;
  cin >> fdown;
  fdown = -fdown;
  llegeix(u);
  cin >> uz;
  uz = -uz;
  if (abs(v) < error and abs(u) < error)
    hihatminim = false;
  else if (abs(prodvec(v, u)) < error)
    computaminimparalel();
  else
    computaminimnoparalel();
  if (hihatminim)
    cout << tminim.first << " " << tminim.second << endl;
  else
    cout << -1.0 << " " << -1.0 << endl;
}
