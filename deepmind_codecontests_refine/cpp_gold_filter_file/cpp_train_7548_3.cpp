#include <bits/stdc++.h>
using namespace std;
vector<complex<double> > fft(vector<complex<double> > y, bool invert = false) {
  const int N = y.size();
  assert(N == (N & -N));
  vector<int> rev(N);
  for (int i = 1; i < N; ++i) {
    rev[i] = (rev[i >> 1] >> 1) | (i & 1 ? N >> 1 : 0);
    if (rev[i] < i) swap(y[i], y[rev[i]]);
  }
  vector<complex<double> > rootni(N / 2);
  for (int n = 2; n <= N; n *= 2) {
    const complex<double>::value_type ang =
        (invert ? +1.0 : -1.0) * 4.0 * acos(0.0l) / n;
    const complex<double> rootn(cos(ang), sin(ang));
    rootni[0] = 1.0;
    for (int i = 1; i < n / 2; ++i) rootni[i] = rootni[i - 1] * rootn;
    for (int left = 0; left != N; left += n) {
      const int mid = left + n / 2;
      for (int i = 0; i < n / 2; ++i) {
        const complex<double> temp = rootni[i] * y[mid + i];
        y[mid + i] = y[left + i] - temp;
        y[left + i] += temp;
      }
    }
  }
  if (invert)
    for (auto &v : y) v /= (complex<double>)N;
  return move(y);
}
vector<complex<double> > convolution(vector<complex<double> > a,
                                     vector<complex<double> > b) {
  int n = a.size();
  a.resize(2 * n);
  b.resize(2 * n);
  vector<complex<double> > fa = fft(move(a)), fb = fft(move(b)), &fc = fa;
  for (int i = 0; i < 2 * n; ++i) fc[i] = fc[i] * fb[i];
  vector<complex<double> > c = fft(move(fc), true);
  return move(c);
}
vector<long long> convolution(const vector<int> &a, const vector<int> &b) {
  vector<complex<double> > a2(a.size()), b2(b.size());
  copy(a.begin(), a.end(), a2.begin());
  copy(b.begin(), b.end(), b2.begin());
  vector<complex<double> > res2 = convolution(a2, b2);
  vector<long long> res(res2.size());
  for (int i = 0; i < (int)res.size(); ++i) res[i] = round(res2[i].real());
  return res;
}
vector<int> polymult(const vector<int> &a, const vector<int> &b, int mod) {
  const int n = a.size(), div = 1002, npart = 3;
  vector<int> as[npart], bs[npart];
  for (auto vparts : {make_pair(ref(a), ref(as)), make_pair(ref(b), ref(bs))}) {
    const vector<int> &v = vparts.first;
    vector<int>(&parts)[npart] = vparts.second;
    for (int j = 0; j < npart; ++j) parts[j].resize(n);
    for (int i = 0; i < n; ++i) {
      int value = v[i];
      for (int j = 0; j < npart; ++j) {
        parts[j][i] = value % div;
        value /= div;
      }
    }
  }
  vector<int> result(2 * n);
  for (int i = 0; i < npart; ++i)
    for (int j = 0; j < npart; ++j) {
      int multby = 1;
      for (int k = 0; k < i + j; ++k) multby = (long long)multby * div % mod;
      vector<long long> res = convolution(as[i], bs[j]);
      for (int k = 0; k < 2 * n; ++k)
        result[k] = (result[k] + res[k] % mod * multby) % mod;
    }
  return result;
}
const int maxk = (1 << 15) - 1;
const int mod = 1e9 + 7;
int fact[maxk + 1], invfact[maxk + 1];
int modpow(int x, int y, int mod) {
  int ret = 1 % mod, x2p = x;
  while (y) {
    if (y % 2) ret = (long long)ret * x2p % mod;
    y /= 2;
    x2p = (long long)x2p * x2p % mod;
  }
  return ret;
}
int inv(int a) { return modpow(a, mod - 2, mod); }
int binom(int a, int b) {
  if (!(0 <= b && b <= a)) return 0;
  return (long long)fact[a] * invfact[b] % mod * invfact[a - b] % mod;
}
struct dp_t {
  int n, value[maxk + 1];
};
dp_t combine(dp_t &left, dp_t &right) {
  vector<int> leftpoly(maxk + 1), rightpoly(maxk + 1);
  for (int i = 0; i <= maxk; ++i)
    leftpoly[i] = (long long)invfact[i] * left.value[i] % mod *
                  modpow(2, i * right.n, mod) % mod;
  for (int i = 0; i <= maxk; ++i)
    rightpoly[i] = (long long)invfact[i] * right.value[i] % mod;
  vector<int> pmult = polymult(leftpoly, rightpoly, mod);
  dp_t result;
  result.n = left.n + right.n;
  for (int i = 0; i <= maxk; ++i)
    result.value[i] = (long long)pmult[i] * fact[i] % mod;
  return result;
}
int main() {
  fact[0] = 1;
  for (int k = 1; k <= maxk; ++k) fact[k] = (long long)fact[k - 1] * k % mod;
  invfact[maxk] = inv(fact[maxk]);
  for (int k = maxk - 1; k >= 0; --k)
    invfact[k] = (long long)invfact[k + 1] * (k + 1) % mod;
  long long N;
  int K;
  cin >> N >> K;
  int result;
  if (N > K)
    result = 0;
  else {
    dp_t dp;
    dp.n = 0;
    dp.value[0] = 1;
    fill(dp.value + 1, dp.value + maxk + 1, 0);
    dp_t x2p;
    x2p.n = 1;
    x2p.value[0] = 0;
    fill(x2p.value + 1, x2p.value + maxk + 1, 1);
    for (int p = 0; dp.n != N; ++p) {
      if (N & (1 << p)) dp = combine(dp, x2p);
      if (dp.n != N) x2p = combine(x2p, x2p);
    }
    result = 0;
    for (int k = 0; k <= K; ++k)
      result = (result + (long long)binom(K, k) * dp.value[k]) % mod;
  }
  printf("%d\n", result);
  return 0;
}
