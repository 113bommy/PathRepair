#include <bits/stdc++.h>
using namespace std;
void ga(int N, long long* A) {
  for (int i(0); i < N; i++) scanf("%lld", A + i);
}
struct MEX {
  int p[(1024) << 1], C[(1024)];
  void CLR() { (memset(C, 0, sizeof(C))), (memset(p, 0, sizeof(p))); }
  int st(int b, int v, int u, int B, int E) {
    if (B > b || E < b) return p[u];
    if (B == E) return p[u] += v;
    return p[u] = st(b, v, u << 1, B, (B + E) >> 1) +
                  st(b, v, u << 1 | 1, (B + E) / 2 + 1, E);
  }
  int get() { return gt(1, 0, (1024) - 1); }
  int gt(int u, int B, int E) {
    if (B == E) return B;
    if (p[u << 1] == (B + E) / 2 - B + 1)
      return gt(u << 1 | 1, (B + E) / 2 + 1, E);
    return gt(u << 1, B, (B + E) >> 1);
  }
  void add(int I) {
    if (!C[I]++) st(I, 1, 1, 0, (1024) - 1);
  }
  void del(int I) {
    if (!--C[I]) st(I, -1, 1, 0, (1024) - 1);
  }
} T;
int G[(1000006)] = {0, 0}, O[(1000006)], I, J, N, a, X;
long long A[(1000006)], U, V;
int main(void) {
  T.CLR();
  for (int k(2); k < (1000006); k++) {
    while (J * J <= k) T.add(G[J++]);
    while (I * I * I * I < k) T.del(G[I++]);
    G[k] = T.get();
  }
  scanf("%d", &N), ga(N, A), sort(A, A + N), T.CLR();
  for (int i(0); i < N; i++) {
    if (A[i] < 2) {
      X ^= G[A[i]];
      continue;
    }
    while (V * V <= A[i]) T.add(G[V++]);
    while (U * U * U * U < A[i]) T.del(G[U++]);
    X ^= T.get();
  }
  puts(!X ? "Rublo" : "Furlo");
  return 0;
}
