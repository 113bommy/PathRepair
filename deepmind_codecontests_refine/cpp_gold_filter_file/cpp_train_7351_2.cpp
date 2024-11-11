#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int F, B, a[505], c[505], r[505];
int ans[505], tmp[505], t[505];
int A[505], Ans[505], mx, p[505];
long long NN;
inline int read() {
  int s = 0, f = 0;
  char ch = getchar();
  while (ch < 48 || ch > 57) f = (ch == '-'), ch = getchar();
  while (ch > 47 && ch < 58)
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return f ? -s : s;
}
int Mod(int x) { return (x < mod) ? x : x - mod; }
void Add(int &x, int y) { x = Mod(x + y); }
void Mul(int *f, int *g, int *ans) {
  for (int i = 0; i < 2 * mx; ++i) r[i] = 0;
  for (int i = 0; i < mx; ++i)
    for (int j = 0; j < mx; ++j) Add(r[i + j], 1ll * f[i] * g[j] % mod);
  for (int i = 2 * mx - 2; i >= mx; --i)
    for (int j = mx - 1; ~j; --j)
      Add(r[i + j - mx], mod - 1ll * r[i] * c[j] % mod);
  for (int i = 0; i < mx; ++i) ans[i] = r[i];
}
signed main() {
  cin >> F >> B >> NN;
  for (int i = 1; i <= F; ++i) cin >> a[i];
  for (int i = 1, x; i <= B; ++i) cin >> x, mx = max(mx, x), ++t[x];
  for (int i = 0; i < mx; ++i) c[i] = mod - t[mx - i];
  c[mx] = 1;
  for (int i = 1; i <= F; ++i) {
    for (int j = 0; j < mx; ++j) ans[j] = tmp[j] = 0;
    (mx > 1) ? (tmp[1] = 1) : (tmp[0] = mod - c[0]);
    for (ans[0] = 1; a[i]; a[i] >>= 1, Mul(tmp, tmp, tmp))
      if (a[i] & 1) Mul(ans, tmp, ans);
    for (int j = 0; j < mx; ++j) Add(A[j], ans[j]);
  }
  for (Ans[0] = p[0] = 1; NN; NN >>= 1, Mul(A, A, A))
    if (NN & 1) Mul(Ans, A, Ans);
  for (int i = 0; i < mx; ++i)
    for (int j = 0; j <= i; ++j) Add(p[i], 1ll * t[j] * p[i - j] % mod);
  int answer = 0;
  for (int i = 0; i < mx; ++i) Add(answer, 1ll * Ans[i] * p[i] % mod);
  cout << answer;
  return 0;
}
