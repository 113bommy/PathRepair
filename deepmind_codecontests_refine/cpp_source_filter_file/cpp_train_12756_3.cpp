#include <bits/stdc++.h>
using namespace std;
template <class T, class V>
ostream &operator<<(ostream &s, pair<T, V> a) {
  s << a.first << ' ' << a.second;
  return s;
}
struct FFT {
  struct cd {
    double a, b;
    cd(double _a = 0, double _b = 0) : a(_a), b(_b) {}
    cd operator+(cd &o) { return cd(a + o.a, b + o.b); }
    cd operator-(cd &o) { return cd(a - o.a, b - o.b); }
    cd operator*(cd &o) { return cd(a * o.a - b * o.b, a * o.b + b * o.a); }
  };
  vector<cd> w[2];
  vector<int> r;
  int M = 1;
  FFT(int n) {
    int u = 0;
    while (M < n) M <<= 1, u++;
    r.resize(M);
    w[0].resize(M, cd(1));
    w[1].resize(M, cd(1));
    for (int i = 1; i < M; i++) {
      int l = __builtin_ctz(i);
      r[i] = r[i ^ (1 << l)] | (1 << (u - l - 1));
      double d = 2 * (acos(-1)) * i / M;
      w[0][i] = cd(cos(d), sin(d));
      w[1][i] = cd(cos(d), -sin(d));
    }
  }
  void fft(vector<cd> &a, bool inv = false) {
    for (int i = 0; i < M; i++)
      if (i < r[i]) swap(a[i], a[r[i]]);
    for (int len = 2, l2 = 1; len <= M; len <<= 1, l2 <<= 1) {
      for (int i = 0, inc = M / len; i < M; i += len) {
        for (int j = 0, l = 0; j < l2; j++, l += inc) {
          cd u = a[i + j], v = a[i + j + l2] * w[inv][l];
          a[i + j] = u + v;
          a[i + j + l2] = u - v;
        }
      }
    }
    if (inv) {
      for (auto &x : a) x.a /= M;
    }
  }
  vector<long long int> multiply(vector<long long int> &a,
                                 vector<long long int> &b) {
    vector<cd> v1(M), v2(M);
    for (int i = 0; i < a.size(); i++) v1[i] = a[i];
    for (int i = 0; i < b.size(); i++) v2[i] = b[i];
    fft(v1);
    fft(v2);
    for (int i = 0; i < M; i++) v1[i] = v1[i] * v2[i];
    fft(v1, 1);
    vector<long long int> res(M);
    for (int i = 0; i < M; i++) res[i] = round(v1[i].a);
    return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  for (int qq = 1; qq <= T; qq++) {
    int n, k;
    cin >> n >> k;
    vector<long long int> vt(1 << 10);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      vt[x] = 1;
    }
    vector<long long int> ans(1, 1);
    while (k) {
      if (k & 1) {
        FFT ft(vt.size() + ans.size());
        ans = ft.multiply(ans, vt);
        if (ans.size() > (1 << 20)) ans.resize(1 << 20);
      }
      if (k == 1) break;
      FFT ft(vt.size() * 2);
      vt = ft.multiply(vt, vt);
      if (vt.size() > (1 << 20)) vt.resize(1 << 20);
      k >>= 1;
    }
    for (int i = 1; i < ans.size(); i++)
      if (ans[i]) cout << i << ' ';
  }
}
