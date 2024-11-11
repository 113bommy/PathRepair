#include <bits/stdc++.h>
using namespace std;
clock_t start;
void Time(bool timeIt) {
  if (!timeIt) return;
  clock_t end = clock();
  double elapsed_time = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
  fprintf(stderr, "Time elapsed = %0.4lf\n", elapsed_time);
}
const double pi = acos(-1);
template <class T>
vector<T> operator*(const vector<T> &lhs, const vector<T> &rhs) {
  assert(lhs.size() == rhs.size());
  vector<T> ret(lhs.size());
  for (int i = 0; i < lhs.size(); ++i) ret[i] = lhs[i] * rhs[i];
  return ret;
}
template <class T>
vector<T> operator/(const vector<T> &lhs, const double num) {
  vector<T> ret(lhs.size());
  for (int i = 0; i < lhs.size(); ++i) ret[i] = lhs[i] / num;
  return ret;
}
template <class T>
class Complex {
 public:
  T x, y;
  Complex(const T &x = 0, const T &y = 0) : x(x), y(y) {}
  Complex(const Complex &r) : x(r.x), y(r.y) {}
  Complex operator+(const Complex &r) const {
    return Complex(x + r.x, y + r.y);
  }
  Complex operator-(const Complex &r) const {
    return Complex(x - r.x, y - r.y);
  }
  Complex operator*(const Complex &r) const {
    return Complex(x * r.x - y * r.y, x * r.y + y * r.x);
  }
  Complex operator*=(const Complex &r) {
    T dupX = x, dupY = y;
    this->x = dupX * r.x - dupY * r.y;
    this->y = dupX * r.y + dupY * r.x;
    return *this;
  }
  Complex operator/=(const double &r) {
    x /= r;
    y /= r;
    return *this;
  }
};
Complex<double> roots[2][430010 * 2];
uint32_t reverseBits(uint32_t i) {
  register uint32_t mask = 0x55555555;
  i = ((i & mask) << 1) | ((i >> 1) & mask);
  mask = 0x33333333;
  i = ((i & mask) << 2) | ((i >> 2) & mask);
  mask = 0x0f0f0f0f;
  i = ((i & mask) << 4) | ((i >> 4) & mask);
  mask = 0x00ff00ff;
  i = ((i & mask) << 8) | ((i >> 8) & mask);
  i = (i << 16) | (i >> 16);
  return i;
}
void iterativeFFT(const vector<Complex<double> > &primal,
                  vector<Complex<double> > &dual, const bool inverse) {
  const int N = primal.size();
  int absP;
  for (int i = 31; i >= 0; --i) {
    if (N & (1 << i)) {
      absP = i;
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    dual[i] = primal[reverseBits(i) >> (32 - absP)];
  }
  for (int p = 1; p <= absP; p++) {
    const int unityStep = 0x1 << p;
    const Complex<double> unityRoot = roots[inverse][unityStep];
    for (int offset = 0; offset < N; offset += unityStep) {
      Complex<double> omega(1, 0);
      int halfStep = (unityStep >> 1);
      for (int k = 0; k < halfStep; k++) {
        const Complex<double> u = dual[offset + k];
        const Complex<double> t = omega * dual[offset + k + halfStep];
        omega *= unityRoot;
        dual[offset + k] = u + t;
        dual[offset + k + halfStep] = u - t;
      }
    }
  }
  if (inverse) {
    for (int j = 0; j < N; j++) dual[j] /= N;
  }
}
inline vector<Complex<double> > fft(vector<double> &a) {
  vector<Complex<double> > A(a.size()), ret(a.size());
  for (int i = 0; i < a.size(); ++i) {
    A[i] = Complex<double>(a[i], 0.0);
  }
  iterativeFFT(A, ret, false);
  return ret;
}
void preCalculateRoots() {
  for (int i = 1; i < 430010; ++i) {
    complex<double> r = polar(1.0, 2.0 * pi / (1.0 * i));
    roots[0][i] = Complex<double>(r.real(), r.imag());
    r = polar(1.0, -2.0 * pi / (1.0 * i));
    roots[1][i] = Complex<double>(r.real(), r.imag());
  }
}
inline void multiply_polynomial(vector<double> a, vector<double> b,
                                vector<double> &ret) {
  int max_sz = a.size() + b.size();
  if (__builtin_popcount(max_sz) != 1) {
    for (int i = 30; i >= 0; --i) {
      if ((max_sz >> i) & 1) {
        max_sz = (1 << (i + 1));
        break;
      }
    }
  }
  while (ret.size() < max_sz) {
    ret.push_back(0);
  }
  while (a.size() < max_sz) {
    a.push_back(0);
  }
  while (b.size() < max_sz) {
    b.push_back(0);
  }
  vector<Complex<double> > dft_a = fft(a), dft_b = fft(b);
  vector<Complex<double> > inv(max_sz);
  iterativeFFT(dft_a * dft_b, inv, true);
  for (int i = 0; i < max_sz; ++i) {
    ret[i] = (inv[i].x > 0.5);
  }
}
char s[430010], t[430010];
vector<double> bs[6], bt[6];
vector<int> adj[430010][6];
int vis[6];
void dfs(int v, int idx) {
  vis[v] = 1;
  for (auto t : adj[idx][v]) {
    if (!vis[t]) dfs(t, idx);
  }
}
int main() {
  start = clock();
  preCalculateRoots();
  scanf("%s %s", s, t);
  int l1 = strlen(s), l2 = strlen(t);
  for (int i = 0; i < l1; ++i) {
    int c = s[i] - 'a';
    for (int j = 0; j < 6; ++j) {
      bs[j].push_back(c == j);
    }
  }
  for (int i = 0; i < l2; ++i) {
    int c = t[i] - 'a';
    for (int j = 0; j < 6; ++j) {
      bt[j].push_back(c == j);
    }
  }
  for (int j = 0; j < 6; ++j) reverse(bt[j].begin(), bt[j].end());
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
      if (i == j) continue;
      vector<double> res;
      multiply_polynomial(bs[i], bt[j], res);
      for (int k = l2 - 1; k < l1; ++k) {
        if (res[k] > 0) {
          adj[k][i].push_back(j);
          adj[k][j].push_back(i);
        }
      }
    }
  }
  for (int i = l2 - 1; i < l1; ++i) {
    int ans = 0;
    for (int j = 0; j < 6; ++j) vis[j] = 0;
    for (int j = 0; j < 6; ++j) {
      if (!vis[j]) {
        ++ans;
        dfs(j, i);
      }
    }
    printf("%d ", 6 - ans);
  }
  printf("\n");
  Time(true);
  return 0;
}
