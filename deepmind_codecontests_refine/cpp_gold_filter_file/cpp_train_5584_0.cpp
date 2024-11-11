#include <bits/stdc++.h>
using namespace std;
const int N = 600005;
using ll = long long;
ll P, g, w[2][N], ww[2][N];
inline ll mul(ll a, ll b) { return (a * b - ll(a * 1.0L * b / P) * P + P) % P; }
ll qpow(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ret;
}
int n, m;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void getp() {
  m = 1;
  while (m <= n * 2) m <<= 1;
  ll lcm = n * 1ll * m / gcd(n, m);
  P = lcm + 1;
  while (P < 100000) P += lcm;
  while (1) {
    int fl = 1;
    for (int i = 2; i * 1ll * i <= P; i++)
      if (P % i == 0) {
        fl = 0;
        break;
      }
    if (fl) break;
    P += lcm;
  }
  g = 2;
  while (1) {
    int fl = 1;
    for (int i = 2; i * 1ll * i <= P; i++)
      if ((P - 1) % i == 0)
        if (qpow(g, i) == 1 || qpow(g, (P - 1) / i) == 1) {
          fl = 0;
          break;
        }
    if (fl) break;
    ++g;
  }
}
void getwn() {
  ll w0 = qpow(g, (P - 1) / m);
  w[0][0] = w[1][0] = 1;
  for (int i = 1; i < m; i++) w[0][i] = mul(w[0][i - 1], w0);
  for (int i = 1; i < m; i++) w[1][i] = w[0][m - i];
  w0 = qpow(g, (P - 1) / n);
  ww[0][0] = ww[1][0] = 1;
  for (int i = 1; i < n; i++) ww[0][i] = mul(ww[0][i - 1], w0);
  for (int i = 1; i < n; i++) ww[1][i] = ww[0][n - i];
}
void NTT(ll a[], int n, int fl) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i > j) swap(a[i], a[j]);
    int kk = n >> 1;
    while ((j ^= kk) < kk) kk >>= 1;
  }
  for (int s = 1; s < n; s <<= 1)
    for (int i = 0; i < n; i += s << 1)
      for (int j = 0, l = 0; j < s; j++, l += n / (s << 1)) {
        ll x = a[i + j], y = mul(a[i + s + j], w[fl][l]);
        a[i + j] = (x + y) % P;
        a[i + s + j] = (x - y + P) % P;
      }
  if (fl) {
    ll inv = qpow(n, P - 2);
    for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
  }
}
ll yy[N];
void pre(int f) {
  for (int i = 0; i < n * 2; i++)
    yy[n * 2 - i - 1] = ww[f][i * (i - 1ll) / 2 % n];
  for (int i = n * 2; i < m; i++) yy[i] = 0;
  NTT(yy, m, 0);
}
void Bluestein(ll a[], int fl) {
  static ll xx[N];
  for (int i = 0; i < n; i++)
    xx[i] = mul(a[i], ww[fl][(n - i * (i - 1ll) / 2 % n) % n]);
  for (int i = n; i < m; i++) xx[i] = 0;
  NTT(xx, m, 0);
  for (int i = 0; i < m; i++) xx[i] = mul(xx[i], yy[i]);
  NTT(xx, m, 1);
  for (int i = 0; i < n; i++)
    a[i] = mul(xx[n * 2 - i - 1], ww[fl][(n - i * (i - 1ll) / 2 % n) % n]);
  if (fl) {
    ll inv = qpow(n, P - 2);
    for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
  }
}
int b[N], c[N];
ll revb[N], dc[N], da[N], a[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  getp();
  getwn();
  for (int i = 0; i < n; i++) revb[i] = b[i];
  reverse(revb + 1, revb + n);
  ll inv2 = qpow(P - 2, P - 2);
  for (int i = 0; i < n; i++)
    dc[i] = mul((c[(i + 1) % n] - c[i] + P) % P, inv2);
  pre(0);
  Bluestein(revb, 0);
  Bluestein(dc, 0);
  for (int i = 0; i < n; i++) da[i] = mul(dc[i], qpow(revb[i], P - 2));
  pre(1);
  Bluestein(da, 1);
  for (int i = 0; i < n; i++) {
    ll vv = (da[i] < P - da[i]) ? da[i] : da[i] - P;
    if (abs(vv) > 20000) {
      cout << 0 << endl;
      return 0;
    }
    a[i] = vv;
  }
  ll cc = -c[0], aa = 0, bb = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    ++aa;
    bb += 2 * (sum - b[i]);
    cc += (sum - b[i]) * (sum - b[i]);
    sum += a[i];
  }
  if (sum) {
    cout << 0 << endl;
    return 0;
  }
  set<ll> ans;
  if (bb * bb - 4 * aa * cc >= 0) {
    ll s = ll(sqrt(bb * bb - 4 * aa * cc) + 0.5);
    if (s * s != bb * bb - 4 * aa * cc) {
      cout << 0 << endl;
      return 0;
    }
    if ((-bb + s) % (aa * 2) == 0) ans.insert((-bb + s) / (aa * 2));
    if ((-bb - s) % (aa * 2) == 0) ans.insert((-bb - s) / (aa * 2));
  }
  cout << ans.size() << endl;
  for (auto i : ans) {
    for (int j = 0; j < n; j++) cout << i << ' ', i += a[j];
    cout << endl;
  }
  return 0;
}
