#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> pair) {
  return out << "(" << pair.X << ", " << pair.Y << ")";
}
const int N = 1 << 21;
const double kEps = .0000001;
const double kPi = 2 * acos(0);
int pot2(int n) {
  int bla = 1;
  while (bla <= n) {
    bla *= 2;
  }
  return bla;
}
complex<double> t[N];
void fft(int n, int p, int s, int q, int znak, complex<double> *A) {
  if (n == 1) {
    t[q] = A[p];
    return;
  }
  complex<double> en = exp(complex<double>(0, 2 * kPi * znak / n));
  complex<double> e = 1;
  fft(n / 2, p, 2 * s, q, znak, A);
  fft(n / 2, p + s, 2 * s, q + n / 2, znak, A);
  for (int r = q; r < q + n / 2; r++) {
    complex<double> z = t[r] + t[r + n / 2] * e;
    t[r + n / 2] = t[r] - t[r + n / 2] * e;
    t[r] = z;
    e *= en;
  }
}
void licz(int n, complex<double> *A, complex<double> *B, complex<double> *C) {
  n = pot2(n + 1);
  fft(n, 0, 1, 0, 1, A);
  for (int i = 0; i < n; i++) {
    A[i] = t[i];
  }
  fft(n, 0, 1, 0, 1, B);
  for (int i = 0; i < n; i++) {
    B[i] = t[i];
  }
  for (int i = 0; i < n; i++) {
    C[i] = A[i] * B[i];
  }
  fft(n, 0, 1, 0, -1, C);
  for (int i = 0; i < n; i++) {
    C[i] = t[i];
    C[i] = complex<double>(round(real(C[i]) / n), 0.0);
  }
}
complex<double> bags[N];
complex<double> res[N];
vector<int> to_print;
complex<double> to_fft1[N], to_fft2[N];
;
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  ;
  int n, m;
  cin >> n >> m;
  ;
  for (int i = (0); i <= (2 * m); ++i) {
    bags[i] = 0;
    to_fft1[i] = 0;
    to_fft2[i] = 0;
    res[i] = 0;
  }
  for (int i = (1); i <= (n); ++i) {
    int a;
    cin >> a;
    ;
    bags[a] = 1;
    to_fft1[a] = 1;
    to_fft2[a] = 1;
  }
  licz(2 * m, to_fft1, to_fft2, res);
  for (int i = (1); i <= (m); ++i) {
    int a = round(real(res[i])), b = round(real(bags[i]));
    if (a > 0 && b == 0) {
      cout << "NO\n";
      return 0;
    } else if (a == 0 && b > 0) {
      to_print.push_back(i);
    }
  }
  cout << "YES\n" << ((int)(to_print).size()) << "\n";
  for (int i = 0; i < ((int)(to_print).size()); i++) {
    cout << to_print[i] << " ";
  }
  cout << "\n";
  return 0;
}
