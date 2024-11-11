#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const long long MOD = 1e9 + 7;
int n, m, A, B;
long long Vans;
long long Efac[N + 3], Einv[N + 3];
long long ADD(long long A, long long B) { return (A + B) % MOD; }
long long MNU(long long A, long long B) { return (A - B + MOD) % MOD; }
long long TIM(long long A, long long B) { return A * B % MOD; }
long long fC(int A, int B) {
  return Efac[B] * Einv[A] % MOD * Einv[B - A] % MOD;
}
long long fA(int A, int B) { return Efac[B] * Einv[B - A] % MOD; }
long long QPow(long long A, long long B) {
  if (B == -1) return QPow(A, MOD - 2);
  long long Rr = 1;
  while (B > 0) {
    if (B & 1) Rr = TIM(Rr, A);
    A = TIM(A, A);
    B >>= 1;
  }
  return Rr;
}
void Process() {
  Efac[0] = 1;
  for (int i = 1; i <= N; i++) Efac[i] = TIM(Efac[i - 1], i);
  Einv[N] = QPow(Efac[N], MOD - 2);
  for (int i = N - 1; i >= 0; i--) Einv[i] = TIM(Einv[i + 1], i + 1);
}
int main() {
  Process();
  scanf("%d%d%*d%*d", &n, &m);
  for (int Vbet = 1; Vbet < n && !Vbet <= m; Vbet++) {
    long long Vct = 1;
    Vct = TIM(Vct, TIM(fA(Vbet - 1, n - 2), fC(Vbet - 1, m - 1)));
    Vct = TIM(Vct, TIM(Vbet + 1, QPow(n, n - Vbet - 2)));
    Vct = TIM(Vct, QPow(m, n - 1 - Vbet));
    Vans = ADD(Vans, Vct);
  }
  printf("%lld\n", Vans);
  return 0;
}
