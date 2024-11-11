#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const int LOG = 20, maxN = (1 << LOG);
complex<double> a[maxN];
bool visited[maxN];
void FFT(complex<double>* a, bool rev) {
  for (int i = 0; i < maxN; i++) {
    int j = 0;
    for (int k = 0; k < LOG; k++)
      if (i & (1 << k)) j += (1 << (LOG - k - 1));
    if (j > i) swap(a[i], a[j]);
  }
  for (int len = 2; len <= maxN; len *= 2) {
    complex<double> wn(cos(2.0 * PI / len), sin(2.0 * PI / len));
    if (rev) wn.imag(wn.imag() * -1.0);
    for (int i = 0; i < maxN; i += len) {
      complex<double> w(1.0, 0.0);
      for (int j = 0; j < len / 2; j++) {
        complex<double> t1 = a[i + j] + w * a[i + j + len / 2];
        complex<double> t2 = a[i + j] - w * a[i + j + len / 2];
        a[i + j] = t1;
        a[i + j + len / 2] = t2;
        w *= wn;
      }
    }
  }
  if (rev)
    for (int i = 0; i < maxN; i++) a[i] /= maxN;
  return;
}
long long ebs(long double x) {
  long long res = (long long)x;
  if (x - res < 0.5)
    return res;
  else
    return res + 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x].real(1);
    visited[x] = true;
  }
  FFT(a, 0);
  for (int i = 0; i < maxN; i++) a[i] = a[i] * a[i];
  FFT(a, 1);
  vector<int> ans;
  for (int i = 0; i <= m; i++) {
    long double t = a[i].real();
    long long res = ebs(t);
    if (!visited[i] && res) return cout << "NO\n" << endl, 0;
    if (res == 0 && visited[i]) ans.push_back(i);
  }
  cout << "YES\n" << ans.size() << endl;
  for (auto x : ans) cout << x << ' ';
  cout << endl;
  return 0;
}
