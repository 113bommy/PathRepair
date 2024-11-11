#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e5;
const int MOD = 1e9 + 7;
long long ans = 0, pot2 = 1, sm = 0;
int N, A[MAXN];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < (int)N; i++) scanf("%d", &A[i]);
  sort(A, A + N);
  for (int i = 0; i < (int)N; i++) {
    sm = ((sm + A[N - i - 1]) % MOD - A[i]) % MOD;
    ans = (ans + ((pot2 * sm) % MOD)) % MOD;
    pot2 = (pot2 * 2) % MOD;
  }
  printf("%lld\n", ans);
}
