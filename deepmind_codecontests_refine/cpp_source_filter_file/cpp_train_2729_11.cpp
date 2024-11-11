#include <bits/stdc++.h>
using namespace std;
const int maxS = 1 << 15;
const int mod = 1e9 + 7;
int n;
int a[65];
int d[65];
int s[15], tots;
int t[65], tott;
int in[65], cnt[maxS + 5];
int f[maxS + 5][65];
int ans, st;
namespace usual {
int C[65][65];
int add(int ta, int tb) { return ta + tb >= mod ? ta + tb - mod : ta + tb; }
int sub(int ta, int tb) { return ta < tb ? ta - tb + mod : ta - tb; }
void make_C() {
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= n; j++) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
  }
}
}  // namespace usual
using namespace usual;
namespace funi {
int fn[65];
void make_fn() {
  for (int i = 1; i <= n; i++) fn[i] = i;
}
int find(int x) { return fn[x] == x ? x : fn[x] = find(fn[x]); }
void uni(int u, int v) {
  int fu = find(u), fv = find(v);
  if (u == v) return;
  fn[fu] = fv;
}
}  // namespace funi
using namespace funi;
bool issub(int ta, int tb) { return (ta & tb) == ta; }
bool isint(int ta, int tb) { return (ta & tb) > 0; }
void clean() {
  tots = tott = 0;
  memset(in, 0, sizeof in);
  memset(cnt, 0, sizeof cnt);
  memset(f, 0, sizeof f);
}
int dp(int fir) {
  clean();
  for (int i = 1; i <= n; i++) {
    if (find(i) != fir) continue;
    if (d[i] == 0)
      s[++tots] = i;
    else
      t[++tott] = i;
  }
  if (tott <= 1) return 1;
  for (int i = 1; i <= tott; i++)
    for (int j = 1; j <= tots; j++)
      if (a[t[i]] % a[s[j]] == 0) in[i] |= (1 << (j - 1));
  for (int i = 0; i < (1 << (tots + 1 - 1)); i++)
    for (int j = 1; j <= tott; j++)
      if (issub(in[j], i)) cnt[i]++;
  for (int i = 1; i <= tott; i++) f[in[i]][1]++;
  for (int S = 0; S < (1 << (tots + 1 - 1)); S++)
    for (int k = 1; k < tott; k++) {
      if (f[S][k] == 0) continue;
      for (int i = 1; i <= tott; i++)
        if (!issub(in[i], S) && isint(in[i], S))
          f[S | in[i]][k + 1] = add(f[S | in[i]][k + 1], f[S][k]);
      f[S][k + 1] = add(f[S][k + 1], 1ll * f[S][k] * (cnt[S] - k) % mod);
    }
  return f[(1 << (tots + 1 - 1)) - 1][tott - 1];
}
int main() {
  scanf("%d", &n);
  make_C();
  make_fn();
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (a[i] % a[j] == 0 && i != j) {
        uni(i, j);
        d[i]++;
      }
  ans = 1;
  for (int i = 1; i <= n; i++)
    if (find(i) == i) {
      ans = 1ll * ans * dp(i) % mod;
      if (tott == 0) continue;
      ans = 1ll * ans * C[st + tott - 1][tott - 1] % mod;
      st += tott - 1;
    }
  printf("%d\n", ans);
  return 0;
}
