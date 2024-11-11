#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
inline int lgput(int x, int p) {
  int ans = 1, aux = x;
  for (int i = 1; i <= p; i = i << 1) {
    if (i & p) ans = (1LL * ans * aux) % MOD;
    aux = (1LL * aux * aux) % MOD;
  }
  return ans;
}
struct usu {
  long double d;
  int i, j;
  bool wh[2];
  bool operator<(const usu &aux) const { return d < aux.d; }
};
int n, I;
int x[100005], v[100005], p[100005];
int Arb[100005][2][2], Lim[100005][2][2];
vector<usu> L;
void combine(int a[2][2], int b[2][2], int c[2][2], int Lim[2][2]) {
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) a[i][j] = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      for (int k = 0; k < 2; ++k)
        for (int t = 0; t < 2; ++t)
          if (!Lim[k][t]) a[i][j] = (a[i][j] + 1LL * b[i][k] * c[t][j]) % MOD;
}
void build(int st = 1, int dr = n, int nod = 1) {
  if (st == dr) {
    Arb[nod][0][0] = (1 - 1LL * I * p[st] % MOD + MOD) % MOD;
    Arb[nod][1][1] = (1LL * I * p[st]) % MOD;
    return;
  }
  int mij = (st + dr) / 2;
  build(st, mij, nod * 2);
  build(mij + 1, dr, nod * 2 + 1);
  combine(Arb[nod], Arb[nod * 2], Arb[nod * 2 + 1], Lim[nod]);
}
void update(int x, int y, bool wh[2], int st = 1, int dr = n, int nod = 1) {
  if (x == dr || y == st) return;
  int mij = (st + dr) / 2;
  if (x <= mij) update(x, y, wh, st, mij, nod * 2);
  if (mij + 1 <= y) update(x, y, wh, mij + 1, dr, nod * 2 + 1);
  if (mij == x && mij + 1 == y) Lim[nod][wh[0]][wh[1]] = 1;
  combine(Arb[nod], Arb[nod * 2], Arb[nod * 2 + 1], Lim[nod]);
}
inline int query() {
  int Sum = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j) Sum = (Sum + Arb[1][i][j]) % MOD;
  return Sum;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d%d", &x[i], &v[i], &p[i]);
  for (int i = 1; i < n; ++i) {
    long double d =
        (long double)(x[i + 1] - x[i]) / (long double)(v[i + 1] + v[i]);
    L.push_back({d, i, i + 1, {1, 0}});
    if (v[i] > v[i + 1]) {
      long double d =
          (long double)(x[i + 1] - x[i]) / (long double)(v[i] - v[i + 1]);
      L.push_back({d, i, i + 1, {1, 1}});
    }
    if (v[i] < v[i + 1]) {
      long double d =
          (long double)(x[i + 1] - x[i]) / (long double)(v[i + 1] - v[i]);
      L.push_back({d, i, i + 1, {0, 0}});
    }
  }
  sort(L.begin(), L.end());
  I = lgput(100, MOD - 2);
  build();
  int A, B;
  int Sol = 0;
  for (auto it : L) {
    A = query();
    update(it.i, it.j, it.wh);
    B = query();
    int nr = 0, i = it.i;
    if (it.wh[0] == 1 && it.wh[1] == 0) nr = v[i + 1] + v[i];
    if (it.wh[0] == 1 && it.wh[1] == 1) nr = v[i] - v[i + 1];
    if (it.wh[0] == 0 && it.wh[1] == 0) nr = v[i + 1] - v[i];
    int d = 1LL * (x[i + 1] - x[i]) * lgput(nr, MOD - 2) % MOD;
    Sol = (Sol + 1LL * (A - B + MOD) % MOD * d) % MOD;
  }
  printf("%d", Sol);
  return 0;
}
