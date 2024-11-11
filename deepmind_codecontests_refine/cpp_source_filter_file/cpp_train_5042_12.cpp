#include <bits/stdc++.h>
using namespace std;
int MOD = 1000000007;
int main() {
  int N;
  scanf("%d", &N);
  int tab[N + 2];
  for (int i = 1; i <= N + 1; i++) scanf("%d", &tab[i]);
  int res = 0;
  int croix[N + 1];
  int porte[N + 1];
  for (int i = 1; i <= N; i++) {
    porte[i] = 0;
    croix[i] = 0;
  }
  porte[N] = 1;
  for (int i = N; i >= 1; i--) {
    croix[i] = 2 * porte[i];
    croix[i] %= MOD;
    porte[i - 1] += 2 * porte[i];
    porte[i - 1] %= MOD;
    porte[tab[i] - 1] -= porte[i];
    porte[tab[i] - 1] = ((porte[tab[i] - 1] % MOD) + MOD) % MOD;
    res += croix[i];
    res %= MOD;
  }
  printf("%d\n", res);
}
