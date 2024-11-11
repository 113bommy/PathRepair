#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;
const long long int LINF = (1LL << 63) - 1;
const int NMAX = 300000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;
const int MOD = 1e9 + 9;
struct node {
  long long int sum, b1, b2;
  node() { sum = b1 = b2 = 0; }
};
long long int N, M, L, R;
node AI[4 * NMAX];
long long int V[NMAX];
long long int F[NMAX];
long long int S[NMAX];
void precomputeFibonacci() {
  long long int i;
  F[1] = 1LL;
  F[2] = 1LL;
  for (i = 3; i <= N + 2; i++) F[i] = (F[i - 2] + F[i - 1]) % MOD;
}
long long int term(long long int a1, long long int a2, long long int n) {
  if (n == 0) return 0LL;
  if (n == 1) return a1;
  if (n == 2) return a2;
  return (a1 * F[n - 2] + a2 * F[n - 1]) % MOD;
}
long long int sum(long long int a1, long long int a2, long long int k) {
  return (term(a1, a2, k + 2) - term(a1, a2, 2) + MOD) % MOD;
}
void update(long long int nod, long long int lo, long long int hi,
            long long int b1, long long int b2) {
  if (L <= lo && hi <= R) {
    b1 = (b1 + F[lo - L + 1]) % MOD;
    b2 = (b2 + F[lo - L + 2]) % MOD;
    AI[nod].b1 = (AI[nod].b1 + b1) % MOD;
    AI[nod].b2 = (AI[nod].b2 + b2) % MOD;
    long long int s = sum(b1, b2, hi - lo + 1);
    AI[nod].sum = (AI[nod].sum + s) % MOD;
    return;
  }
  if (hi < L || R < lo) {
    AI[nod].b1 = (AI[nod].b1 + b1) % MOD;
    AI[nod].b2 = (AI[nod].b2 + b2) % MOD;
    long long int s = sum(b1, b2, hi - lo + 1);
    AI[nod].sum = (AI[nod].sum + s) % MOD;
    return;
  }
  long long int mi = (lo + hi) / 2;
  update(2 * nod, lo, mi, b1 + AI[nod].b1, b2 + AI[nod].b2);
  update(2 * nod + 1, mi + 1, hi,
         term(b1 + AI[nod].b1, b2 + AI[nod].b2, mi + 2 - lo),
         term(b1 + AI[nod].b1, b2 + AI[nod].b2, mi + 3 - lo));
  AI[nod].b1 = AI[nod].b2 = 0LL;
  AI[nod].sum = (AI[2 * nod].sum + AI[2 * nod + 1].sum) % MOD;
}
long long int query(long long int nod, long long int lo, long long int hi,
                    long long int b1, long long int b2) {
  if (L <= lo && hi <= R) {
    AI[nod].b1 = (AI[nod].b1 + b1) % MOD;
    AI[nod].b2 = (AI[nod].b2 + b2) % MOD;
    long long int s = sum(b1, b2, hi - lo + 1);
    AI[nod].sum = (AI[nod].sum + s) % MOD;
    return AI[nod].sum;
  }
  if (hi < L || R < lo) {
    AI[nod].b1 = (AI[nod].b1 + b1) % MOD;
    AI[nod].b2 = (AI[nod].b2 + b2) % MOD;
    long long int s = sum(b1, b2, hi - lo + 1);
    AI[nod].sum = (AI[nod].sum + s) % MOD;
    return 0LL;
  }
  long long int mi = (lo + hi) / 2, q1, q2;
  q1 = query(2 * nod, lo, mi, b1 + AI[nod].b1, b2 + AI[nod].b2);
  q2 = query(2 * nod + 1, mi + 1, hi,
             term(b1 + AI[nod].b1, b2 + AI[nod].b2, mi + 2 - lo),
             term(b1 + AI[nod].b1, b2 + AI[nod].b2, mi + 3 - lo));
  AI[nod].b1 = AI[nod].b2 = 0LL;
  AI[nod].sum = (AI[2 * nod].sum + AI[2 * nod + 1].sum) % MOD;
  return (q1 + q2) % MOD;
}
int main() {
  long long int i, x, op;
  scanf("%I64d%I64d", &N, &M);
  for (i = 1; i <= N; i++) {
    scanf("%I64d", &x);
    V[i] = (V[i - 1] + x) % MOD;
  }
  precomputeFibonacci();
  while (M--) {
    scanf("%I64d%I64d%I64d", &op, &L, &R);
    if (op == 1) update(1, 1, N, 0, 0);
    if (op == 2) {
      x = (query(1, 1, N, 0, 0) + V[R] - V[L - 1] + MOD) % MOD;
      printf("%I64d\n", x);
    }
  }
  return 0;
}
