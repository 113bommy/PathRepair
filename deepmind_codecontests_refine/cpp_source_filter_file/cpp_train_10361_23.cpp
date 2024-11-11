#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
long double V[(1 << 18)], X[(1 << 18)], W[(1 << 18)];
long long B[(1 << 18)], E[(1 << 18)], L[(1 << 18)], R[(1 << 18)], N, O, ZA, ZB;
long double o1(long double a, long double b) { return min(a, b); }
long double o2(long double a, long double b) { return max(a, b); }
void bt(int n, long double za, long double zb) {
  ZA = za, ZB = zb;
  for (int i(0); i < (1 << 18); i++) W[i] = X[i] = V[i] = 0;
  for (int K(N), l(N >> 1), p(0); l; K += l, l >>= 1, O = K)
    for (int k(K); k < K + l; k++)
      B[k] = B[p], E[k] = E[p + 1], X[k] = V[k] = 0, L[k] = p, R[k] = p + 1,
      p += 2;
  --O;
  if (!~O) O = 0;
}
void stR(int n, long long *a, long double za = 0, long double zb = 0) {
  N = 1 << (int)(ceil(log2(n)) + 0.1);
  a[n] = a[n - 1] + 1;
  for (int i(0); i < n; i++) B[i] = a[i], E[i] = a[i + 1] - 1;
  for (int k(n); k < N; k++) B[k] = E[k] = a[n - 1] + 1;
  bt(n - 1, za, zb);
}
long double mn(int u) { return V[u] + W[u]; }
long double mx(int u) { return X[u] + W[u]; }
void ud(long long b, long long e, long double v, int u = O) {
  if (e < B[u] || b > E[u]) return;
  if (u < N) {
    V[u] = X[u] += v;
    return;
  }
  if (b <= B[u] && e >= E[u]) {
    W[u] += v;
    return;
  };
  if (W[u]) ud(B[u], E[u], W[u], L[u]), ud(B[u], E[u], W[u], R[u]), W[u] = 0;
  ud(b, e, v, L[u]), ud(b, e, v, R[u]), W[u] = 0;
  V[u] = o1(mn(R[u]), mn(L[u]));
  X[u] = o2(mx(R[u]), mx(L[u]));
}
pair<long double, long double> g1(long long b, long long e, int u = O) {
  if (b <= B[u] && e >= E[u]) return {mn(u), mx(u)};
  if (e < B[u] || b > E[u]) return {ZA, ZB};
  if (W[u])
    ud(B[u], E[u], W[u], L[u]), ud(B[u], E[u], W[u], R[u]),
        W[u] = 0, V[u] = o1(mn(R[u]), mn(L[u])), X[u] = o2(mx(R[u]), mx(L[u]));
  pair<long double, long double> A(g1(b, e, L[u])), H(g1(b, e, R[u]));
  return {o1((0 ? A.second : A.first), (0 ? H.second : H.first)),
          o2((1 ? A.second : A.first), (1 ? H.second : H.first))};
}
int rr[(1 << 18)], hh[(1 << 18)];
long double vv[(1 << 18)];
long long second[(1 << 18)] = {0};
void uq(long long *G, int &g) {
  sort(G, G + g);
  int r(0), u(0);
  while (u < g) {
    while (u < g && u && G[u] == G[u - 1]) ++u;
    if (u < g) G[r++] = G[u++];
  }
  g = r;
}
int main(void) {
  int N;
  scanf("%d", &N);
  int r, h, L(1);
  for (int i(0); i < N; i++)
    scanf("%d%d", &r, &h),
        rr[i] = r, hh[i] = h,
        vv[i] =
            ((long double)3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647) *
            r * r * h,
        second[L++] = r * 1ll * r * h;
  sort(second, second + L);
  uq(second, L);
  stR(L, second);
  long double a, b, B(0);
  for (int i(0); i < N; i++) {
    a = vv[i];
    b = g1(0, rr[i] * 1ll * rr[i] * hh[i] - 1).second;
    b += a;
    B = max(B, b);
    ud(rr[i] * 1ll * rr[i] * hh[i], rr[i] * 1ll * rr[i] * hh[i], b);
  }
  cout << fixed << setprecision(30) << B << endl;
  return 0;
}
