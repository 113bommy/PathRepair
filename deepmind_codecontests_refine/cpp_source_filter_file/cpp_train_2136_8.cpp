#include <bits/stdc++.h>
const long long MOD1 = 1000000007, MOD2 = 1234321237, BAS1 = 23333, BAS2 = 2333;
int N;
char a[1000002], b[1000002];
long long A1[1000002], A2[1000002], B1[1000002], B2[1000002], P1[1000002],
    P2[1000002];
int main() {
  scanf("%d%s%s", &N, a + 1, b + 1);
  for (int i = 1; i <= N; i++)
    b[i] = b[i] == 'W' ? 'E' : (b[i] == 'E' ? 'W' : (b[i] == 'N' ? 'S' : 'N'));
  std::reverse(b + 1, b + N + 1);
  P1[0] = P2[0] = 1;
  for (int i = 1; i <= N; i++) {
    A1[i] = (A1[i - 1] * BAS1 + a[i]) % MOD1;
    A2[i] = (A2[i - 1] * BAS2 + a[i]) % MOD2;
    B1[i] = (B1[i - 1] * BAS1 + b[i]) % MOD1;
    B2[i] = (B2[i - 1] * BAS2 + b[i]) % MOD2;
    P1[i] = P1[i - 1] * BAS1 % MOD1;
    P2[i] = P2[i - 1] * BAS2 % MOD2;
  }
  for (int i = 1; i <= N; i++) {
    if ((A1[N] - A1[N - i] * P1[i] % MOD1 + MOD1) % MOD1 == B1[i] &&
        (A2[N] - A2[N - i] * P2[i] % MOD2 + MOD2) % MOD2 == B2[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}
