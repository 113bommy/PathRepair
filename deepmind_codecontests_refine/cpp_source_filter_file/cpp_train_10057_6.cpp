#include <bits/stdc++.h>
using namespace std;
void ga(int N, int *A) {
  for (int i(0); i < N; i++) scanf("%d", A + i);
}
long long P[(1 << 17) >> 1] = {2}, L(1), cn[1 + ((1 << 17) >> 6)];
void gen() {
  (cn[0 >> 6] |= 1ULL << ((0 & 63))), (cn[1 >> 6] |= 1ULL << ((1 & 63)));
  int Q(1 + sqrt((1 << 17)));
  for (long long i(4); i < (1 << 17); i += 2)
    (cn[i >> 6] |= 1ULL << ((i & 63)));
  for (int k(3); k <= Q; k += 2)
    if (!((cn[k >> 6] >> (k & 63)) & 1))
      for (long long h(k << 1), j(k * k); j < (1 << 17); j += h)
        (cn[j >> 6] |= 1ULL << ((j & 63)));
  for (int i(3); i < (1 << 17); i += 2)
    if (!((cn[i >> 6] >> (i & 63)) & 1)) P[L++] = i;
}
int fc(int N, int *f, int *c) {
  int L(0);
  for (int i(0), h(0); N >= P[i] * P[i]; ++i, h = 0) {
    while (!(N % P[i])) ++h, N /= P[i];
    if (h) f[L] = P[i], c[L++] = h;
  }
  if (N > 1) f[L] = N, c[L++] = 1;
  return L;
}
void rec(int *f, int *c, int p, int L, vector<int> &o, int S) {
  if (p == L)
    o.push_back(S);
  else
    for (int i(0); i < c[p] + 1; i++) rec(f, c, p + 1, L, o, S), S *= f[p];
}
void dsr(int N, vector<int> &o) {
  o.clear();
  static int f[64], c[64];
  int L(fc(N, f, c));
  rec(f, c, 0, L, o, 1);
}
vector<int> o, O;
long long N, K, X, B, a;
int A[128];
bool go(long long d) {
  if (d < 1) return 0;
  long long S = 0;
  for (int i(0); i < N && S <= K; i++) S += ((A[i] - 1) / d + 1) * d;
  return S <= K;
}
void gt(long long d) {
  long long S = 0, a;
  for (int i(0); i < N && S <= K; i++) S += ((A[i] - 1) / d + 1) * d;
  if (S > K) return;
  a = max(X, d + (K - S) / N);
  X = max(X, d);
  while (go(a)) ++a;
  --a;
  if (go(a)) X = max(X, a);
}
long long R(int b = 62) {
  long long r(0);
  for (int i(0); i < b; i++) r <<= 1, r |= rand() & 1;
  return r;
}
int main(void) {
  srand(time(0));
  scanf("%lld%lld", &N, &K), ga(N, A), gen();
  for (int i(0); i < N; i++) {
    dsr(A[i], o), K += A[i];
    for (auto &h : o) O.push_back(h);
  }
  sort(O.begin(), O.end(), greater<int>()),
      O.resize(unique(O.begin(), O.end()) - O.begin());
  for (auto &h : O) gt(h);
  for (int i(0); i < 1000; i++)
    if (go(a = X + R() % int(1e5) + 1)) X = a;
  for (int i(0); i < 2e6 - 5e5; i++)
    if (go(X + i + 1)) B = X + i + 1;
  while (go(B)) ++B;
  --B;
  printf("%lld\n", max(B, X));
  return 0;
}
