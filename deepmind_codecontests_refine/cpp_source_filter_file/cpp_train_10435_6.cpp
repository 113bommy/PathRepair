#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& a) {
  for (T& ai : a) is >> ai;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> const& a) {
  os << "[ ";
  for (const T& ai : a) os << ai << " ";
  return os << "]";
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& a) {
  return is >> a.first >> a.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> const& a) {
  return os << "(" << a.first << ", " << a.second << ")";
}
const double PI = 3.14159265358979323846;
void fft(vector<complex<double> >& a, int d) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int k = n >> 1;
    while (!((j ^= k) & k)) k >>= 1;
    if (i < j) swap(a[i], a[j]);
  }
  vector<complex<double> > s;
  for (int m = n >> 1; m; m >>= 1) {
    s.push_back(polar<double>(1, d * PI / (double)m));
  }
  for (int k = 1; k < n; k <<= 1) {
    complex<double> t = s.back();
    s.pop_back();
    for (int i = 0; i < n; i += k << 1) {
      complex<double> w = 1;
      for (int j = 0; j < k; ++j) {
        complex<double> x = a[i + j], y = a[i + j + k] * w;
        a[i + j] = x + y;
        a[i + j + k] = x - y;
        w *= t;
      }
    }
  }
}
void poly_mul(vector<complex<double> >& p, vector<complex<double> >& q) {
  int m = p.size() + q.size() - 1;
  int n = 1 << (32 - __builtin_clz(m - 1));
  p.resize(n);
  fft(p, 1);
  q.resize(n);
  fft(q, 1);
  for (int i = 0; i < n; ++i) p[i] *= q[i];
  q.clear();
  fft(p, -1);
  p.resize(m);
  for (complex<double>& pi : p) pi /= (double)n;
}
struct Solution {
  static const int K = 26;
  vector<int> p, pci, pco, pcl;
  string s, t, r;
  int n, m, l;
  void parse() {
    p.resize(K);
    cin >> p >> s >> t;
    n = s.size();
    m = t.size();
    l = 1 + m - n;
  }
  void solve() {
    r.resize(l, '1');
    compute_p();
    filter_ci();
    filter_co();
    cout << r << "\n";
  }
  void compute_p() {
    pci.resize(K, -1);
    pco.resize(K, -1);
    for (int i = 0; i < K; ++i) {
      if (pci[i] >= 0) continue;
      int u = i, s = 0;
      while (pci[u] < 0) {
        pci[u] = pcl.size();
        pco[u] = s++;
        u = p[u] - 1;
      }
      pcl.push_back(s);
    }
  }
  void filter_ci() {
    string ss(s), tt(t);
    for (char& si : ss) si = 'a' + pci[si - 'a'];
    for (char& ti : tt) ti = 'a' + pci[ti - 'a'];
    vector<int> a(n + 1);
    a[0] = -1;
    int j = 0;
    for (int i = 1; i < n; ++i, ++j) {
      if (ss[i] == ss[j]) {
        a[i] = a[j];
        continue;
      }
      a[i] = j;
      while (j >= 0 && ss[i] != ss[j]) j = a[j];
    }
    a[n] = j;
    j = 0;
    for (int i = 0; i < m; ++i) {
      while (j >= 0 && tt[i] != ss[j]) j = a[j];
      if (++j == n)
        j = a[j];
      else if (i >= n - 1)
        r[1 + i - n] = '0';
    }
  }
  void filter_co() {
    vector<complex<double> > a(n), b(m);
    complex<double> z = 0;
    for (int i = 0; i < n; ++i) {
      int x = pci[s[i] - 'a'], y = pco[s[i] - 'a'];
      if (pcl[x] <= 2) continue;
      a[i] = polar<double>(1, 2 * y * PI / pcl[x]);
      z += polar<double>(1, PI / pcl[x]);
    }
    for (int i = 0; i < m; ++i) {
      int x = pci[t[i] - 'a'], y = pco[t[i] - 'a'];
      if (pcl[x] <= 2) continue;
      b[i] = polar<double>(1, (1 - 2 * y) * PI / pcl[x]);
    }
    reverse((a).begin(), (a).end());
    poly_mul(a, b);
    for (int i = 0; i < l; ++i) {
      if (r[i] == '0') continue;
      if (abs(a[i + n - 1].real() - z.real()) > 1e-6) r[i] = '0';
    }
  }
};
string f(int k = 26) {
  vector<int> p(k);
  cin >> p;
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int l = 1 + m - n;
  vector<int> kmp(n + 1);
  vector<int> c(l);
  string r(l, '0');
  for (int i = 0; i < l; ++i)
    if (c[i] == n) r[i] = '1';
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Solution soln;
  soln.parse();
  soln.solve();
  return 0;
}
