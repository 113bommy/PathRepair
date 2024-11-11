#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 125010;
const int mod = 998244353;
struct dsu {
  int father[10];
  void init() {
    for (int i(0); i <= (7); ++i) father[i] = i;
  }
  int getfather(int x) {
    return father[x] == x ? x : father[x] = getfather(father[x]);
  }
} c[N];
char s[N], t[N];
int a[N << 1], b[N << 1];
int n, m;
int ans[N];
int rev[N << 1];
int w[N << 2];
int x1[N << 2], x2[N << 2];
int add(int a, int b) { return (a += b) >= mod ? a - mod : a; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int ksm(int base, int n) {
  n += (n < 0) * (mod - 1);
  int ans = 1;
  while (n) {
    if (n & 1) ans = mul(ans, base);
    base = mul(base, base);
    n >>= 1;
  }
  return ans;
}
void ntt(int *a, int n, int op) {
  for (int i = 0; n > i; i++) {
    if (rev[i] > i) swap(a[i], a[rev[i]]);
  }
  for (int i = (w[0] = 1); n > i; i <<= 1) {
    int wn = ksm(3, op * (mod - 1) / (i << 1));
    for (int k = i - 2; k >= 0; k -= 2) {
      w[k + 1] = mul(w[k] = w[k >> 1], wn);
    }
    for (int j = 0, p = i << 1; n > j; j += p) {
      for (int k = 0; i > k; k++) {
        int x = a[j + k], y = mul(w[k], a[j + k + i]);
        a[j + k] = add(x, y), a[j + k + i] = sub(x, y);
      }
    }
  }
  if (op == -1) {
    int r = ksm(n, mod - 2);
    for (int i = 0; n > i; i++) {
      a[i] = mul(a[i], r);
    }
  }
}
void mul(int p[], int dp, int q[], int dq) {
  int len = 1;
  while (len <= dp + dq) len <<= 1;
  for (int i(0); i <= (dp); ++i) x1[i] = p[i];
  for (int i(dp + 1); i <= (len - 1); ++i) x1[i] = 0;
  for (int i(0); i <= (dq); ++i) x2[i] = q[i];
  for (int i(dq + 1); i <= (len - 1); ++i) x2[i] = 0;
  ntt(x1, len, 1);
  ntt(x2, len, 1);
  for (int i(0); i <= (len - 1); ++i) x1[i] = mul(x1[i], x2[i]);
  ntt(x1, len, -1);
  for (int i(0); i <= (dp + dq); ++i) p[i] = x1[i];
  for (int i(0); i <= (dp + dq); ++i)
    if (p[i] > 0) p[i] = 1;
  dp += dq;
}
void work(int pos, int x, int y) {
  int fx = c[pos].getfather(x), fy = c[pos].getfather(y);
  if (fx == fy) return;
  assert(pos >= 1 && pos <= n - m + 1);
  ++ans[pos];
  c[pos].father[fx] = fy;
}
int main() {
  scanf("%s%s", s, t);
  n = strlen(s), m = strlen(t);
  for (int i(1); i <= (n - m + 1); ++i) c[i].init();
  int len = 1, cnt = 0;
  while (len <= n + m) len <<= 1, cnt++;
  for (int i = 0; len > i; i++) {
    rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1)));
  }
  for (int i(0); i <= (5); ++i) {
    for (int j(0); j <= (5); ++j) {
      if (i == j) continue;
      memset(a, 0, sizeof a);
      memset(b, 0, sizeof b);
      for (int k(0); k <= (n - 1); ++k) a[k] = (s[k] - 'a' == i);
      for (int k(0); k <= (m - 1); ++k) b[k] = (t[k] - 'a' == j);
      reverse(b, b + m);
      mul(a, n, b, m);
      for (int k = m - 1, cnt = 1; cnt <= n - m + 1; ++k, ++cnt) {
        if (a[k]) {
          work(cnt, i + 1, j + 1);
        }
      }
    }
  }
  for (int i(1); i <= (n - m + 1); ++i) printf("%d\n", ans[i]);
  return 0;
}
