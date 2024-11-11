#include <bits/stdc++.h>
using namespace std;
void rwFile() {}
const double PI = acos(-1);
const long long MOD = 1009;
const int maxN = 2e5 + 5;
void fft(vector<complex<long double>> &a, bool invert) {
  int n = a.size();
  if (n == 1) return;
  vector<complex<long double>> a0(n / 2), a1(n / 2);
  for (int i = 0; 2 * i < n; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }
  fft(a0, invert);
  fft(a1, invert);
  double ang = 2 * PI / n * (invert ? -1 : 1);
  complex<long double> w(1), wn(cos(ang), sin(ang));
  for (int i = 0; 2 * i < n; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    if (invert) {
      a[i] /= 2;
      a[i + n / 2] /= 2;
    }
    w *= wn;
  }
}
vector<long long> multiply(vector<long long> const &a,
                           vector<long long> const &b) {
  if (b.size() == 1) return a;
  if (a.size() == 1) return b;
  vector<complex<long double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<long long> result(n);
  for (int i = 0; i < n; i++) result[i] = (long long)round(fa[i].real()) % MOD;
  return result;
}
void POLYMUL() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; ++i) cin >> a[i];
    for (int i = 0; i <= n; ++i) cin >> b[i];
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<long long> res = multiply(a, b);
    int len = res.size() - 1;
    while (len >= 0 && res[len] == 0) len--;
    if (len < 0) {
      cout << 0;
      return;
    }
    for (int i = len; i >= 0; --i) cout << res[i] << ' ';
    cout << '\n';
  }
}
vector<long long> Arr[maxN];
vector<long long> mergeSolve(int l, int r) {
  if (l == r) return Arr[l];
  int mid = (l + r) / 2;
  vector<long long> left = mergeSolve(l, mid);
  vector<long long> right = mergeSolve(mid + 1, r);
  vector<long long> res = multiply(left, right);
  return res;
}
namespace Fft {
void fft(vector<complex<double>> &a, bool inv) {
  int n = a.size(), j = 0;
  vector<complex<double>> roots(n / 2);
  for (int i = 1; i < n; i++) {
    int bit = (n >> 1);
    while (j >= bit) {
      j -= bit;
      bit >>= 1;
    }
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
  for (int i = 0; i < n / 2; i++) {
    roots[i] = complex<double>(cos(ang * i), sin(ang * i));
  }
  for (int i = 2; i <= n; i <<= 1) {
    int step = n / i;
    for (int j = 0; j < n; j += i) {
      for (int k = 0; k < i / 2; k++) {
        complex<double> u = a[j + k], v = a[j + k + i / 2] * roots[step * k];
        a[j + k] = u + v;
        a[j + k + i / 2] = u - v;
      }
    }
  }
  if (inv)
    for (int i = 0; i < n; i++) a[i] /= n;
}
vector<long long> multiply(vector<long long> &v, vector<long long> &w) {
  vector<complex<double>> fv(v.begin(), v.end()), fw(w.begin(), w.end());
  int n = 2;
  while (n < v.size() + w.size()) n <<= 1;
  fv.resize(n);
  fw.resize(n);
  fft(fv, 0);
  fft(fw, 0);
  for (int i = 0; i < n; i++) fv[i] *= fw[i];
  fft(fv, 1);
  vector<long long> ret(n);
  for (int i = 0; i < n; i++) ret[i] = (long long)round(fv[i].real()) % MOD;
  return ret;
}
};  // namespace Fft
void LightsabersHard() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= m; ++i) Arr[i].push_back(1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    Arr[x].push_back(1);
  }
  vector<long long> res = Arr[1];
  set<pair<int, int>> S;
  for (int i = 1; i <= m; ++i) S.insert({Arr[i].size(), i});
  while (S.size() > 1) {
    int pos1 = S.begin()->second;
    S.erase(S.begin());
    int pos2 = S.begin()->second;
    S.erase(S.begin());
    Arr[pos1] = Fft::multiply(Arr[pos1], Arr[pos2]);
    S.insert({Arr[pos1].size(), pos1});
  }
  int pos = S.begin()->second;
  cout << Arr[pos][k] % MOD;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  rwFile();
  LightsabersHard();
};
