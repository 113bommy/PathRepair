#include <bits/stdc++.h>
using namespace std;
const long long maxlog = 20;
const long long maxn = 2 << maxlog;
long long n, m;
bool mark[maxn];
complex<double> a[maxn];
vector<long long> ans;
void fft(complex<double> a[], bool inv = false) {
  for (long long j, i = 0; i < maxn; i++) {
    j = 0;
    for (long long b = 0; b <= maxlog; b++) j |= (i >> b & 1) << (maxlog - b);
    if (i < j) swap(a[i], a[j]);
  }
  for (long long l = 2; l <= maxn; l += l) {
    complex<double> wn(cos(2 * 3.14159265359 / l), sin(2 * 3.14159265359 / l));
    if (inv) wn.imag(wn.imag() * -1);
    for (long long i = 0; i < maxn; i += l) {
      complex<double> w(1.0, 0.0);
      for (long long j = 0; j < l / 2; j++) {
        complex<double> t1 = a[i + j] + w * a[i + j + l / 2];
        complex<double> t2 = a[i + j] - w * a[i + j + l / 2];
        a[i + j] = t1;
        a[i + j + l / 2] = t2;
        w *= wn;
      }
    }
  }
  for (long long i = 0; i < maxn and inv; i++) a[i] /= maxn;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long x, i = 0; i < n; i++) {
    cin >> x;
    mark[x] = true;
    a[x].real(1.0);
  }
  fft(a);
  for (long long i = 0; i < maxn; i++) a[i] *= a[i];
  fft(a, 1);
  for (long long i = 0; i <= m; i++)
    if (!mark[i] and a[i].real() > 0.5) {
      cout << "No" << endl;
      return 0;
    }
  for (long long i = 0; i <= m; i++)
    if (mark[i] and a[i].real() < 0.5) ans.push_back(i);
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for (long long p : ans) cout << p << " ";
  cout << endl;
  return 0;
}
