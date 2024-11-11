#include <bits/stdc++.h>
using namespace std;
struct Debug {
  int cnt = 0;
  bool on = false;
  char debug[10] = "debug";
  template <class T>
  Debug& operator<<(const T& v) {
    if (on && cnt++ == 0) cerr << "debug: ";
    if (on) cerr << v << ' ';
    return *this;
  }
  Debug& operator<<(ostream& (*pManip)(ostream&)) {
    if (on) cerr << (*pManip);
    cnt = 0;
    return *this;
  }
} debug;
const int MAXN = 1e7 + 10;
int get_reverse_bit(int x) {
  int y = 0;
  for (auto i = (0); i < (25); i++) {
    y = (y << 1) + (x & 1);
    x >>= 1;
  }
  return y;
}
void reorder(vector<complex<double>>& a) {
  static vector<int> reverse_bit;
  static vector<pair<int, complex<double>>> tmp;
  int n = a.size();
  if (tmp.size() != n) tmp.resize(n);
  if (reverse_bit.size() < n) {
    int n0 = reverse_bit.size();
    reverse_bit.resize(n);
    for (auto i = (n0); i < (n); i++) reverse_bit[i] = get_reverse_bit(i);
  }
  for (auto i = (0); i < (n); i++) {
    tmp[i].first = reverse_bit[i];
    tmp[i].second = a[i];
  }
  sort((tmp).begin(), (tmp).end(),
       [](const pair<int, complex<double>>& x,
          const pair<int, complex<double>>& y) { return x.first < y.first; });
  for (auto i = (0); i < (n); i++) a[i] = tmp[i].second;
}
void fft(vector<complex<double>>& a, bool invert = false) {
  int n = a.size();
  reorder(a);
  for (int len = 2; len <= n; len <<= 1) {
    double angle = 4 * asin(1) / len * (invert ? -1 : 1);
    complex<double> rn(cos(angle), sin(angle));
    for (int begin = 0; begin < n; begin += len) {
      complex<double> cur(1);
      int mid = begin + len / 2;
      for (auto i = (0); i < (len / 2); i++) {
        auto tmp1 = a[begin + i] + cur * a[mid + i];
        auto tmp2 = a[begin + i] - cur * a[mid + i];
        a[begin + i] = tmp1;
        a[mid + i] = tmp2;
        cur *= rn;
      }
    }
  }
  if (invert)
    for (auto i = (0); i < (n); i++) a[i] /= n;
}
vector<complex<double>> fft_multiply(vector<complex<double>> a,
                                     vector<complex<double>> b) {
  int na = a.size(), nb = b.size();
  int n = 1;
  while (n < na + nb - 1) n <<= 1;
  a.resize(n);
  b.resize(n);
  fft(a);
  fft(b);
  for (auto i = (0); i < (n); i++) a[i] *= b[i];
  fft(a, true);
  return a;
}
vector<long long> fft_multiply(vector<long long>& a, vector<long long>& b) {
  vector<complex<double>> aa((a).begin(), (a).end()),
      bb((b).begin(), (b).end());
  auto resres = fft_multiply(aa, bb);
  int n = a.size() + b.size() - 1;
  vector<long long> res(n);
  for (auto i = (0); i < (n); i++) res[i] = resres[i].real() + 0.5;
  return res;
}
int n, x;
long long a[MAXN];
int main(int argc, char* argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (argc > 1 && !strcmp(argv[1], debug.debug)) debug.on = true;
  cin >> n >> x;
  for (auto i = (0); i < (n); i++) cin >> a[i];
  int i = -1, j;
  vector<long long> b;
  while (i < n) {
    for (j = i + 1; j < n && a[j] >= x; j++)
      ;
    b.push_back(j - i);
    i = j;
  }
  {
    if (debug.on) {
      for (auto x : b) debug << x;
      debug << endl;
    }
  };
  auto c = b;
  reverse((c).begin(), (c).end());
  auto d = fft_multiply(b, c);
  long long res1 = 0;
  for (auto x : b) res1 += (x - 1) * (x - 2) / 2 + x - 1;
  cout << res1 << ' ';
  int m = b.size();
  for (auto i = (1); i < (m); i++) cout << d[m - 1 - i] << ' ';
  for (auto i = (m); i < (n + 1); i++) cout << 0 << ' ';
  cout << endl;
  return 0;
}
