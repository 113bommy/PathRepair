#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long nega = 1;
  while (!isdigit(ch)) {
    if (ch == '-') nega = -1;
    ch = getchar();
  }
  long long ans = 0;
  while (isdigit(ch)) {
    ans = ans * 10 + ch - 48;
    ch = getchar();
  }
  if (nega == -1) return -ans;
  return ans;
}
inline long long add(long long x, long long y) {
  return x + y >= 31525197391593473LL ? x + y - 31525197391593473LL : x + y;
}
inline long long add(long long x, long long y, long long z) {
  return add(add(x, y), z);
}
inline long long sub(long long x, long long y) {
  return x - y < 0 ? x - y + 31525197391593473LL : x - y;
}
inline long long mul(long long x, long long y) {
  return (x * y -
          (long long)((long double)x / 31525197391593473LL * y) *
              31525197391593473LL +
          31525197391593473LL) %
         31525197391593473LL;
}
inline long long mul(long long x, long long y, long long z) {
  return mul(mul(x, y), z);
}
long long qpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) ans = mul(ans, x);
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
long long getInv(long long x) { return qpow(x, 31525197391593473LL - 2); }
namespace Poly {
vector<long long> rev, rt, one(1, 1);
long long __inv[2000005];
const long long G = 3;
void Init_Inv() {
  __inv[0] = __inv[1] = 1;
  for (long long i = 2; i <= 2000000; i++)
    __inv[i] = mul(31525197391593473LL - 31525197391593473LL / i,
                   __inv[31525197391593473LL % i]);
}
vector<long long> operator+(vector<long long> a, vector<long long> b) {
  long long n = max(a.size(), b.size());
  a.resize(n), b.resize(n);
  for (long long i = 0; i < n; i++) a[i] = add(a[i], b[i]);
  return a;
}
vector<long long> operator-(vector<long long> a, vector<long long> b) {
  long long n = max(a.size(), b.size());
  a.resize(n), b.resize(n);
  for (long long i = 0; i < n; i++) a[i] = sub(a[i], b[i]);
  return a;
}
void init(long long B) {
  long long n = 1 << B;
  rev.resize(n), rt.resize(n);
  for (long long i = 1; i < n; i++)
    rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (B - 1));
  for (long long mid = 1; mid < n; mid <<= 1) {
    long long w = qpow(G, (31525197391593473LL - 1) / (mid << 1));
    rt[mid] = 1;
    for (long long i = 1; i < mid; i++) rt[mid + i] = mul(rt[mid + i - 1], w);
  }
}
void NTT(vector<long long> &a, long long B) {
  long long n = 1 << B;
  for (long long i = 0; i < n; i++)
    if (rev[i] > i) swap(a[i], a[rev[i]]);
  for (long long mid = 1; mid < n; mid <<= 1) {
    for (long long i = 0; i < n; i += (mid << 1)) {
      for (long long j = 0; j < mid; j++) {
        long long x = a[i + j], y = mul(a[i + j + mid], rt[j + mid]);
        a[i + j] = add(x, y), a[i + j + mid] = sub(x, y);
      }
    }
  }
}
vector<long long> operator*(vector<long long> a, vector<long long> b) {
  long long B = 0, n = a.size() + b.size() - 1;
  while ((1 << B) < n) B++;
  a.resize(1 << B), b.resize(1 << B);
  init(B);
  NTT(a, B), NTT(b, B);
  for (long long i = 0; i < (1 << B); i++) a[i] = mul(a[i], b[i]);
  reverse(a.begin() + 1, a.end());
  NTT(a, B);
  a.resize(n);
  long long In = getInv(1 << B);
  for (long long i = 0; i < n; i++) a[i] = mul(a[i], In);
  return a;
}
};  // namespace Poly
using namespace Poly;
long long n, m, Q, a[100005], b[100005], x[100005], ans[100005];
void solve(long long opt) {
  vector<long long> A(100005), B(100005), C(100005), D(100005);
  for (long long i = 1; i <= n; i++) A[a[i]]++;
  for (long long i = 1; i <= m; i++) B[b[i]]++;
  for (long long i = 1; i < n; i++) C[min(a[i], a[i + 1])]++;
  for (long long i = 1; i < m; i++) D[min(b[i], b[i + 1])]++;
  vector<long long> n = A * B, m1 = A * D, m2 = B * C, f = C * D;
  for (long long i = n.size() - 1; i >= 0; i--) n[i] += n[i + 1];
  for (long long i = m1.size() - 1; i >= 0; i--) m1[i] += m1[i + 1];
  for (long long i = m2.size() - 1; i >= 0; i--) m2[i] += m2[i + 1];
  for (long long i = f.size() - 1; i >= 0; i--) f[i] += f[i + 1];
  for (long long i = 1; i <= Q; i++)
    ans[i] += opt * (n[x[i]] - m1[x[i]] - m2[x[i]] + f[x[i]]);
}
signed main() {
  Init_Inv();
  cin >> n >> m >> Q;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) b[i] = read();
  for (long long i = 1; i <= Q; i++) x[i] = read();
  solve(1);
  for (long long i = 1; i <= n; i++) a[i] = 100001 - a[i];
  for (long long i = 1; i <= m; i++) b[i] = 100001 - b[i];
  for (long long i = 1; i <= Q; i++) x[i] = 200003 - a[i];
  solve(-1);
  for (long long i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
  return 0;
}
