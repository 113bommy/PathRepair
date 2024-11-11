#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 1 << 20;
int ksm(long long a, int b, int c = 1) {
  for (; b; b /= 2, a = a * a % mod)
    if (b & 1) c = c * a % mod;
  return c;
}
namespace FFT {
const double PI = acos(-1);
struct C {
  double x, y;
  inline C(double x = 0, double y = 0) : x(x), y(y) {}
  C operator-(const C& a) const { return C(x - a.x, y - a.y); }
  C operator+(const C& a) const { return C(x + a.x, y + a.y); }
  C operator*(const double& a) const { return C(x * a, y * a); }
  C operator/(const double& a) const { return C(x / a, y / a); }
  C operator*(const C& a) const {
    return C(x * a.x - y * a.y, x * a.y + y * a.x);
  }
  C conj() const { return C(x, -y); }
} s1[N], omg_[N], s2[N];
int n_, lgn_;
int rev_[N];
void FFT_init(int n) {
  lgn_ = 32 - __builtin_clz(n);
  n_ = 1 << lgn_;
  rev_[0] = 0;
  omg_[0] = C(1, 0);
  for (int i = 1; i < n_; i <<= 1)
    omg_[i] = C(cos(2. * i * PI / n_), sin(2. * i * PI / n_));
  for (int i = 1; i < n_; i++) {
    omg_[i] = omg_[i ^ (i & -i)] * omg_[i & -i];
    rev_[i] = rev_[i / 2] >> 1 | (i & 1) << (lgn_ - 1);
  }
}
C ww[N];
void FFT(C* a) {
  for (int i = 0; i < n_; i++)
    if (rev_[i] < i) swap(a[i], a[rev_[i]]);
  register int t;
  for (int i = 0; i < lgn_; i++) {
    t = 1 << i;
    for (register int j = 0; j < t; ++j) ww[j] = omg_[j << (lgn_ - i - 1)];
    for (register int j = 0; j < n_; j += t << 1) {
      register C *at = a + j, *bt = a + j + t;
      for (register int k = 0; k < t; ++k) {
        C s = bt[k] * ww[k];
        bt[k] = at[k] - s;
        at[k] = at[k] + s;
      }
    }
  }
}
C s3[N], s4[N];
int tmp[N];
void mul(int* a, int* b, int n, int m) {
  if (n + m <= 10) {
    for (int i = 0; i < n + m; i++) tmp[i] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        tmp[i + j] = (tmp[i + j] + (long long)a[i] * b[j]) % mod;
    for (int i = 0; i < n + m; i++) a[i] = tmp[i];
    return;
  }
  FFT_init(n + m - 2);
  for (int i = 0; i < n; i++) s1[i] = C(a[i] & 32767, a[i] >> 15);
  for (int i = 0; i < m; i++) s2[i] = C(b[i] & 32767, b[i] >> 15);
  FFT(s1);
  FFT(s2);
  for (int i = 0; i < n_; i++) {
    int j = (n_ - 1) & (n_ - i);
    C da, db, dc, dd;
    da = (s1[i] + s1[j].conj()) * C(0.5, 0);
    db = (s1[i] - s1[j].conj()) * C(0, -0.5);
    dc = (s2[i] + s2[j].conj()) * C(0.5, 0);
    dd = (s2[i] - s2[j].conj()) * C(0, -0.5);
    s3[j] = da * dc + da * dd * C(0, 1);
    s4[j] = db * dc + db * dd * C(0, 1);
  }
  FFT(s3);
  FFT(s4);
  for (int i = 0; i < n_; i++) {
    int da = (long long)(s3[i].x / n_ + 0.5) % mod;
    int db = (long long)(s3[i].y / n_ + 0.5) % mod;
    int dc = (long long)(s4[i].x / n_ + 0.5) % mod;
    int dd = (long long)(s4[i].y / n_ + 0.5) % mod;
    a[i] = (da + ((long long)(db + dc) << 15) + ((long long)dd << 30)) % mod;
    (a[i] += mod) %= mod;
  }
}
}  // namespace FFT
int a[N], b[N], c[N], pw[N], jc[N], jc2[N];
void init(int n) {
  if (n < 0) return;
  pw[0] = 1;
  jc[0] = 1;
  for (int i = 1; i <= n; i++)
    pw[i] = pw[i - 1] * 2 % mod, jc[i] = (long long)jc[i - 1] * i % mod;
  jc2[n] = ksm(jc[n], mod - 2);
  for (int i = n; i; i--) jc2[i - 1] = (long long)jc2[i] * i % mod;
  for (int i = 0; i <= n; i++) a[i] = (long long)pw[i] * jc[n - i] % mod;
  for (int i = 0; i <= n; i++) b[i] = jc2[i];
  FFT::mul(a, b, n + 1, n + 1);
  c[0] = c[1] = 0;
  for (int i = 0; i <= n; i++) c[i + 2] = (long long)a[i] * jc2[n - i] % mod;
  for (int i = 1; i <= n + 2; i++) c[i] = (c[i] + c[i - 1]) % mod;
}
int pr[N], vis[N], la[N], cnt;
void init2() {
  for (int i = 2; i < N; i++) {
    if (!vis[i]) {
      pr[++cnt] = i;
      la[i] = cnt;
    }
    for (int j = 1; j <= la[i] && pr[j] * i < N; j++) {
      int v = pr[j] * i;
      vis[v] = 1;
      la[v] = la[i];
    }
  }
}
int A[100000][20], n, ans;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  init(n - 2);
  init2();
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int lst = 0, ret = 0;
    while (x > 1) {
      int u = la[x];
      if (u == lst)
        ret++;
      else {
        A[lst][ret]++;
        lst = u;
        ret = 1;
      }
      x /= pr[u];
    }
    A[lst][ret]++;
  }
  for (int i = 1; i <= cnt; i++) {
    for (int j = 17; ~j; j--) A[i][j] += A[i][j + 1];
    A[i][0] = n;
    for (int j = 0; j <= 18; j++) {
      int l = A[i][j], r = A[i][j + 1];
      ans = (ans - (long long)(c[l] - c[r]) * j) % mod;
      ans = (ans + (long long)(c[n - r] - c[n - l]) * j) % mod;
    }
  }
  ans = (ans + mod) % mod;
  cout << ans << endl;
  return 0;
}
