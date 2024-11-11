#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("popcnt,abm,mmx,avx2")
using namespace std;
template <class U, class V>
istream& operator>>(istream& is, pair<U, V>& p) {
  is >> p.first >> p.second;
  return is;
}
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& x : v) {
    is >> x;
  }
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& x : v) {
    os << x << " ";
  }
  return os;
}
template <typename T, typename... Ts>
T min(const T& h1, const T& h2, const Ts&... tail) {
  return min(min(h1, h2), tail...);
}
template <typename T, typename... Ts>
T max(const T& h1, const T& h2, const Ts&... tail) {
  return max(max(h1, h2), tail...);
}
using vi = vector<int>;
void fft(vector<complex<double>>& a) {
  int n = ((int)(a.size())), L = 31 - __builtin_clz(n);
  static vector<complex<long double>> R(2, 1);
  static vector<complex<double>> rt(2, 1);
  for (static int k = 2; k < n; k *= 2) {
    R.resize(n);
    rt.resize(n);
    auto x = polar(1.0L, acos(-1.0L) / k);
    for (int i = k; i < 2 * k; ++i)
      rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
  }
  vi rev(n);
  for (int i = 0; i < n; ++i) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
  for (int i = 0; i < n; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int k = 1; k < n; k *= 2)
    for (int i = 0; i < n; i += 2 * k)
      for (int j = 0; j < k; ++j) {
        auto x = (double*)&rt[j + k], y = (double*)&a[i + j + k];
        complex<double> z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
      }
}
vector<double> conv(const vector<double>& a, const vector<double>& b) {
  if (a.empty() || b.empty()) return {};
  vector<double> res(((int)(a.size())) + ((int)(b.size())) - 1);
  int L = 32 - __builtin_clz(((int)(res.size()))), n = 1 << L;
  vector<complex<double>> in(n), out(n);
  copy(begin(a), end(a), begin(in));
  for (int i = 0; i < ((int)(b.size())); ++i) in[i].imag(b[i]);
  fft(in);
  for (complex<double>& x : in) x *= x;
  for (int i = 0; i < n; ++i) out[i] = in[-i & (n - 1)] - conj(in[i]);
  fft(out);
  for (int i = 0; i < ((int)(res.size())); ++i) res[i] = imag(out[i]) / (4 * n);
  return res;
}
constexpr int A = 'f' - 'a' + 1;
const int N = 1.5e5;
struct DSU {
  static const int N = A;
  int parent[N];
  int size[N];
  void init() {
    for (int i = 0; i < N; ++i) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  DSU() { init(); }
  int getRoot(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getRoot(parent[x]);
  }
  void join(int x, int y) {
    x = getRoot(x);
    y = getRoot(y);
    if (x != y) {
      size[y] += size[x];
      parent[x] = y;
    }
  }
} dsu[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string a, b;
  cin >> a >> b;
  array<vector<double>, A> pos_a, pos_b;
  for (char x = 'a'; x <= 'f'; ++x) {
    pos_a[x - 'a'].assign(((int)(a.size())), 0);
    for (int i = 0; i < ((int)(a.size())); ++i) {
      pos_a[x - 'a'][i] = (a[i] == x);
    }
    pos_b[x - 'a'].assign(((int)(b.size())), 0);
    for (int i = 0; i < ((int)(b.size())); ++i) {
      pos_b[x - 'a'][((int)(b.size())) - 1 - i] = (b[i] == x);
    }
  }
  for (char x = 'a'; x <= 'f'; ++x) {
    for (char y = 'a'; y <= 'f'; ++y) {
      if (x == y) continue;
      vector<double> product = conv(pos_a[x - 'a'], pos_b[y - 'a']);
      for (int i = ((int)(b.size())) - 1; i < ((int)(product.size())); ++i) {
        if (product[i] == 1) {
          dsu[i - (((int)(b.size())) - 1)].join(x - 'a', y - 'a');
        }
      }
    }
  }
  for (int i = 0; i < ((int)(a.size())) - ((int)(b.size())) + 1; ++i) {
    int res = 0;
    for (int j = 0; j < A; ++j) {
      if (dsu[i].parent[j] == j) {
        res += dsu[i].size[j] - 1;
      }
    }
    cout << res << " ";
  }
  cout << '\n';
  return 0;
}
