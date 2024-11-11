#include <bits/stdc++.h>
using namespace std;
double getTime() { return clock() / (double)CLOCKS_PER_SEC; };
const int mod = 1e9 + 7;
const long long INF = 3e18;
const int N = 2e5 + 5;
const int P0 = 437;
const int P1 = 343;
const int d = 400;
const double PI = acos(-1);
int BitRev(int a, int Lg) {
  int an = 0;
  for (int i = 0; i < (Lg); i++) {
    if (a & (1 << i)) an |= (1 << (Lg - i - 1));
  }
  return an;
}
void FFT(vector<complex<double> >& a, int inv) {
  int n = ((int)(a).size());
  int Lg = 0;
  while ((1 << Lg) < n) Lg++;
  for (int i = 0; i < (n); i++) {
    int rev = BitRev(i, Lg);
    if (i < rev) swap(a[i], a[rev]);
  }
  for (int len = 2; len <= n; len *= 2) {
    double alf = 2 * PI / len * inv;
    complex<double> wm(cos(alf), sin(alf));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int pos = i; pos < i + len / 2; pos++) {
        complex<double> x = a[pos], y = a[pos + len / 2] * w;
        a[pos] = x + y;
        a[pos + len / 2] = x - y;
        w *= wm;
      }
    }
  }
}
void GLINA(vector<int>& a, vector<int>& b, vector<int>& an) {
  int st = 1;
  while (st < max(((int)(a).size()), ((int)(b).size()))) st *= 2;
  st *= 2;
  vector<complex<double> > a1(st), b1(st);
  for (int i = 0; i < (st); i++) {
    if (i >= ((int)(a).size()))
      a1[i] = 0;
    else
      a1[i] = a[i];
    if (i >= ((int)(b).size()))
      b1[i] = 0;
    else
      b1[i] = b[i];
  }
  FFT(a1, 1), FFT(b1, 1);
  for (int i = 0; i < (st); i++) a1[i] *= b1[i];
  FFT(a1, -1);
  an.resize(st);
  for (int i = 0; i < (st); i++) an[i] = a1[i].real() / st + 0.5;
}
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  n++;
  vector<int> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  vector<int> ha(N + 1), hb(N + 1);
  for (int i = 0; i < (n); i++) {
    ha[a[i]] = 1;
    hb[N - a[i]] = 1;
  }
  vector<int> has;
  GLINA(ha, hb, has);
  for (int i = 0; i < (N); i++) has[i] = has[i + N];
  vector<int> an(1000001, -1);
  for (int i = 2; i <= x; i++) {
    if (has[i]) {
      int len = i * 2 + y * 2;
      for (int j = len; j <= 1000000; j += len) an[j] = max(an[j], len);
    }
  }
  int q;
  cin >> q;
  for (int h = 0; h < (q); h++) {
    int len;
    cin >> len;
    cout << an[len] << ' ';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int qq = 1;
  while (qq--) solve();
}
