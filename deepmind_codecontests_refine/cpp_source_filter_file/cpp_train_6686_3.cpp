#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int eps = 1e-6;
long long qpow(long long a, long long b, long long c) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = (res * a) % c;
    a = (a * a) % c;
    b >>= 1;
  }
  return res % c;
}
long long qmul(long long a, long long b, long long c) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % c;
    a = (a + a) % c;
    b >>= 1;
  }
  return res % c;
}
template <typename T>
bool MAX(T &A, T B) {
  return A < B ? A = B : 0;
}
template <typename T>
bool MIN(T &A, T B) {
  return A > B ? A = B : 0;
}
template <typename T>
void Adm(T &A, T B) {
  A = (A + B) % mod;
}
template <typename T>
void Sub(T &A, T B) {
  A = (A - B + 1ll * mod) % mod;
}
template <typename T>
void Mul(T &A, T B) {
  A = (A * B) % mod;
}
struct Bit {
  inline int lowbit(int x) { return x & (-x); }
  long long Bit[maxn];
  int N;
  bool rev = 0;
  void init(int x) {
    N = x;
    fill(Bit, Bit + N + 5, 0);
  }
  void addBitMax(int x, long long v) {
    if (rev) x = N - x + 1;
    while (x <= N) Bit[x] = max(Bit[x], v), x += lowbit(x);
  }
  void addBitSum(int x, long long v) {
    if (rev) x = N - x + 1;
    while (x <= N) Bit[x] = (Bit[x] + v) % mod, x += lowbit(x);
  }
  long long qBitMax(int x) {
    if (rev) x = N - x + 1;
    long long res = -linf;
    while (x) res = max(res, Bit[x]), x -= lowbit(x);
    return res;
  }
  long long qBitSum(int x) {
    if (rev) x = N - x + 1;
    long long res = 0;
    while (x) res = (res + Bit[x] % mod), x -= lowbit(x);
    return res;
  }
};
void p_bit(long long x) { cout << bitset<32>(x) << ':' << x << endl; }
long long sum[60][maxn];
long long d[60][maxn], pre[60][maxn], rpre[60][maxn];
int a[60][maxn];
deque<long long> q1, q2;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]), sum[i][j] = sum[i][j - 1] + a[i][j];
    }
  }
  for (int i = 2; i <= n + 1; i++) {
    while (!q1.empty()) q1.pop_back();
    while (!q2.empty()) q2.pop_back();
    for (int j = k; j <= m; j++) {
      long long s =
          sum[i][j] + sum[i - 1][j] - sum[i][j - k] - sum[i - 1][j - k];
      d[i][j] = max(pre[i - 1][j - k], rpre[i - 1][j + k]) + s;
      while (!q1.empty() && d[i - 1][j] - sum[i - 1][j] >
                                d[i - 1][q1.back()] - sum[i - 1][q1.back()])
        q1.pop_back();
      q1.push_back(j);
      while (!q1.empty() && q1.front() < j - k + 1) q1.pop_front();
      if (!q1.empty()) {
        int x = q1.front();
        d[i][j] =
            max(d[i][j], d[i - 1][x] - sum[i - 1][x] + s + sum[i - 1][j - k]);
      }
    }
    for (int j = m; j >= k; j--) {
      long long s =
          sum[i][j] + sum[i - 1][j] - sum[i][j - k] - sum[i - 1][j - k];
      while (!q2.empty() && d[i - 1][j] - sum[i - 1][j - k] >
                                d[i - 1][q2.back()] - sum[i - 1][q2.back() - k])
        q2.pop_back();
      q2.push_back(j);
      while (!q2.empty() && q2.front() > j + k - 1) q2.pop_front();
      if (!q2.empty()) {
        int x = q2.front();
        d[i][j] =
            max(d[i][j], d[i - 1][x] + sum[i - 1][x - k] + s - sum[i - 1][j]);
      }
    }
    for (int j = 1; j <= m; j++) pre[i][j] = max(pre[i][j - 1], d[i][j]);
    for (int j = m; j >= 1; j--) rpre[i][j] = max(rpre[i][j + 1], d[i][j]);
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) ans = max(ans, d[n + 1][i]);
  cout << ans << endl;
  return 0;
}
