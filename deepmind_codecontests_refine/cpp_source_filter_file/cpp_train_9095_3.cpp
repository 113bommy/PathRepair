#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 998244353;
const int N = 1500005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  freopen("filename.in", "r", stdin);
  freopen("filename.out", "w", stdout);
}
long long Pow(long long x, long long k) {
  long long ans = 1;
  for (; k; k >>= 1, x = x * x % _p)
    if (k & 1) (ans *= x) %= _p;
  return ans;
}
template <class V>
struct FT {
  static const int N = 1 << 20;
  V w[2][N * 2 + 5], rev[N * 2 + 5], tmp;
  void Init() {
    V w0 = Pow(3, (_p - 1) / N), m;
    w[0][0] = w[1][0] = 1;
    for (int i = (1); i <= (N - 1); ++i)
      w[0][i] = w[1][N - i] = (long long)w[0][i - 1] * w0 % _p;
    for (m = 0; (1 << m) != N; m++)
      ;
    for (int i = (1); i <= (N - 1); ++i)
      rev[i] = (rev[i >> 1] >> 1) | (i & 1) << m - 1;
  }
  void FFT(V A[], int op) {
    for (int i = (0); i <= (N - 1); ++i)
      if (i < rev[i]) swap(A[i], A[rev[i]]);
    for (int i = 1; i < N; i <<= 1)
      for (int j = 0, t = N / (i << 1); j < N; j += i << 1)
        for (int k = j, l = 0; k < j + i; k++, l += t) {
          V x = A[k], y = (long long)w[op][l] * A[k + i] % _p;
          A[k] = (x + y) % _p, A[k + i] = (x - y + _p) % _p;
        }
    if (op) {
      tmp = Pow(N, _p - 2);
      for (int i = (0); i <= (N - 1); ++i) A[i] = 1ll * A[i] * tmp % _p;
    }
  }
  void Solve(V A[], V B[], V C[], int op = 0) {
    if (op) reverse(B, B + N);
    FFT(A, 0);
    for (int i = (0); i <= (N - 1); ++i) C[i] = (long long)A[i] * B[i] % _p;
    FFT(C, 1);
    if (op) reverse(C, C + N);
  }
};
FT<int> T;
int n, m, a[N], b[N], c[N], ret[N];
vector<int> ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (n); ++i) scanf("%d", &a[i]), c[a[i]] = 1, b[a[i]] = 1;
  T.Init();
  T.Solve(b, b, ret);
  for (int i = (1); i <= (m); ++i)
    if (ret[i] && !c[i]) return 0 * printf("NO\n");
  printf("YES\n");
  for (int i = (1); i <= (n); ++i)
    if (!ret[a[i]]) ans.push_back(a[i]);
  printf("%d\n", ans.size());
  for (auto t : ans) printf("%d ", t);
  printf("\n");
  return 0;
}
