#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, X = 2, mod = 1e9 + 7;
int zrb(int a, int b) { return (1LL * a * b % mod); }
int jm(int a, int b) {
  int tmp = (a + b) % mod;
  while (tmp < 0) tmp += mod;
  return (tmp);
}
struct MX {
  int D[X][X], n, m, md;
  int zrb(int a, int b, int md) { return (1LL * a * b % md); }
  int jm(int a, int b, int md) {
    int tmp = (a + b) % md;
    while (tmp < 0) tmp += md;
    return (tmp);
  }
  void Clear() { memset(D, 0, sizeof(D)); }
  inline MX(int nn = 2, int mm = 2, int mmd = mod) {
    n = nn;
    m = mm;
    md = mmd;
    Clear();
  }
  void I(int t = 1) {
    Clear();
    for (int i = 0; i < n; i++) D[i][i] = t;
  }
  void print() {
    for (int i = 0; i < n; i++, puts(""))
      for (int j = 0; j < m; j++) printf("%d ", D[i][j]);
  }
  void fill(int x) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) D[i][j] = x;
  }
  MX operator*(const MX &a) {
    MX rt = MX(n, a.m, md);
    rt.Clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < a.m; j++)
        for (int k = 0; k < m; k++) {
          rt.D[i][j] = jm(rt.D[i][j], zrb(D[i][k], a.D[k][j], md), md);
        }
    return (rt);
  }
  MX operator*=(const MX &a) {
    MX rt = MX(n, a.m, md);
    rt.Clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < a.m; j++)
        for (int k = 0; k < m; k++) {
          rt.D[i][j] = jm(rt.D[i][j], zrb(D[i][k], a.D[k][j], md), md);
        }
    *this = rt;
  }
  MX operator+(const MX &a) {
    MX rt = MX(n, m, md);
    rt.Clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) rt.D[i][j] = jm(D[i][j], a.D[i][j], md);
    return (rt);
  }
  MX operator+=(const MX &a) {
    MX rt = MX(n, m, md);
    rt.Clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) rt.D[i][j] = jm(D[i][j], a.D[i][j], md);
    *this = rt;
  }
  MX operator^(int b) {
    MX rt = MX(n, m, md);
    rt.I();
    MX tv = MX(n, m, md);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) tv.D[i][j] = D[i][j];
    while (b) {
      if (b & 1) rt = rt * tv;
      b >>= 1;
      tv = tv * tv;
    }
    return (rt);
  }
  MX operator^=(int b) {
    MX rt = MX(n, m, md);
    rt.I();
    MX tv = MX(n, m, md);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) tv.D[i][j] = D[i][j];
    while (b) {
      if (b & 1) rt = rt * tv;
      b >>= 1;
      tv = tv * tv;
    }
    *this = rt;
  }
  int *operator[](int ind) { return (D[ind]); }
} LZ[N << 2], SG[N << 2], I, bs;
int n, q, A[N];
void build(int id = 1, int l = 0, int r = n) {
  if (r - l < 2) {
    SG[id] = bs ^ (A[l] - 1);
    LZ[id] = I;
    return;
  }
  int mid = ((l + r) >> 1);
  build((id << 1), l, mid);
  build((id << 1 | 1), mid, r);
  SG[id] = SG[(id << 1)] + SG[(id << 1 | 1)];
  LZ[id] = I;
}
void shift(int id, int l, int r) {
  LZ[(id << 1)] = LZ[(id << 1)] * LZ[id];
  LZ[(id << 1 | 1)] = LZ[(id << 1 | 1)] * LZ[id];
  SG[(id << 1)] = SG[(id << 1)] * LZ[id];
  SG[(id << 1 | 1)] = SG[(id << 1 | 1)] * LZ[id];
  LZ[id] = I;
}
void add(int s, int e, MX k, int id = 1, int l = 0, int r = n) {
  if (l >= e || r <= s) return;
  if (l >= s && r <= e) {
    SG[id] = SG[id] * k;
    LZ[id] = LZ[id] * k;
    return;
  }
  shift(id, l, r);
  int mid = ((l + r) >> 1);
  add(s, e, k, (id << 1), l, mid);
  add(s, e, k, (id << 1 | 1), mid, r);
  SG[id] = SG[(id << 1)] + SG[(id << 1 | 1)];
}
int get(int s, int e, int id = 1, int l = 0, int r = n) {
  if (l >= e || r <= s) return (0);
  if (l >= s && r <= e) return (SG[id][0][0]);
  shift(id, l, r);
  int mid = ((l + r) >> 1);
  return (jm(get(s, e, (id << 1), l, mid), get(s, e, (id << 1 | 1), mid, r)));
}
int main() {
  I.I();
  bs.fill(1);
  bs[1][1] = 0;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  build();
  for (int Q = 0; Q < q; Q++) {
    int tp, l, r, x;
    scanf("%d", &tp);
    if (tp == 1) {
      scanf("%d %d %d", &l, &r, &x);
      l--;
      MX tmp = bs ^ x;
      add(l, r, tmp);
      continue;
    }
    scanf("%d %d", &l, &r);
    l--;
    printf("%d\n", get(l, r));
  }
}
