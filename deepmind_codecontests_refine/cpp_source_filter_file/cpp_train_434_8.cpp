#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int M = 1 << 20 << 1;
const int N = 3e6 + 5;
const int maxn = 3e6 + 5;
int a[M], b[M];
struct NTT {
  static const int G = 3, P = 998244353;
  int N, na, nb, w[2][M], rev[M];
  long long kpow(long long a, int b) {
    long long c = 1;
    for (; b; b >>= 1, a = a * a % P)
      if (b & 1) c = c * a % P;
    return c;
  }
  void FFT(int *a, int f) {
    for (int i = (0); i < (N); i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
      for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
        for (int k = 0, l = 0, x, y; k < i; k++, l += t)
          x = (long long)w[f][l] * a[j + k + i] % P, y = a[j + k],
          a[j + k] = (y + x) % P, a[j + k + i] = (y - x + P) % P;
    if (f)
      for (int i = 0, x = kpow(N, P - 2); i < N; i++)
        a[i] = (long long)a[i] * x % P;
  }
  void work() {
    int d = __builtin_ctz(N);
    w[0][0] = w[1][0] = 1;
    for (int i = 1, x = kpow(G, (P - 1) / N), y = kpow(x, P - 2); i < N; i++) {
      rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (d - 1));
      w[0][i] = (long long)x * w[0][i - 1] % P,
      w[1][i] = (long long)y * w[1][i - 1] % P;
    }
  }
  vector<int> doit(vector<int> s, vector<int> s1) {
    int na = (int)s.size(), nb = (int)s1.size();
    for (N = 1; N < na + nb - 1; N <<= 1)
      ;
    for (int i = (na); i < (N); i++) a[i] = 0;
    for (int i = (nb); i < (N); i++) b[i] = 0;
    for (int i = (0); i < (na); i++) a[i] = s[i];
    for (int i = (0); i < (nb); i++) b[i] = s1[i];
    work(), FFT(a, 0), FFT(b, 0);
    for (int i = (0); i < (N); i++) a[i] = (long long)a[i] * b[i] % P;
    FFT(a, 1);
    vector<int> ans;
    while (N > 0 && a[N - 1] == 0) N--;
    for (int i = (0); i < (N); i++) ans.push_back(a[i]);
    return ans;
  }
} ntt;
int f[maxn], c[maxn];
vector<int> solve(int l, int r) {
  if (l == r) {
    vector<int> v;
    for (int i = (0); i < (c[l] + 1); i++) v.push_back(1);
    return v;
  }
  int mid = l + r >> 1;
  vector<int> s = ntt.doit(solve(l, mid), solve(mid + 1, r));
  return s;
}
int main() {
  int n, p, t = 0;
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", &p), f[p]++;
  for (int i = (2); i < (3000001); i++)
    if (f[i]) c[++t] = f[i];
  vector<int> ans = solve(1, t);
  int ss = 0;
  for (int i = (0); i < ((int)ans.size()); i++) ss = max(ans[i], ss);
  printf("%d", ss);
  return 0;
}
