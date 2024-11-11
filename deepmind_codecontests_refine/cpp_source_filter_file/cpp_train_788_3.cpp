#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int mod = (int)1e9 + 7;
int fastPot(int base, int pot) {
  if (pot == 0) return 1;
  if (pot == 1) return base;
  int half = fastPot(base, pot / 2);
  half = (long long)half * half % mod;
  if (pot & 1) half = (long long)half * base % mod;
  return half;
}
int n;
int A[MAXN], temp[MAXN];
bool zbroj;
void load() {
  scanf("%d", &n);
  if (n % 4 == 2 || n % 4 == 3)
    zbroj = true;
  else
    zbroj = false;
  for (int i = 0; i < n; i++) scanf("%d", A + i);
  if (n & 1) {
    for (int i = 0; i < n; i++) temp[i] = A[i];
    n--;
    for (int i = 0; i < n; i++) {
      if (i & 1)
        A[i] = (temp[i] - temp[i + 1] + mod) % mod;
      else
        A[i] = (temp[i] + temp[i + 1]) % mod;
    }
  }
}
int fact[MAXN], rev[MAXN];
void solve() {
  if (n == 0) {
    printf("%d\n", A[0]);
    return;
  }
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (long long)fact[i - 1] * i % mod;
  rev[n] = fastPot(fact[n], mod - 2);
  for (int i = n - 1; i >= 1; i--)
    rev[i] = (long long)rev[i + 1] * (i + 1) % mod;
  int sol = 0;
  int sol2 = 0;
  for (int i = 0; i < n / 2; i++) {
    int mult =
        (long long)fact[n / 2 - 1] * rev[i] % mod * rev[n / 2 - 1 - i] % mod;
    sol += (long long)mult * A[i * 2] % mod;
    sol2 += (long long)mult * A[i * 2 + 1] % mod;
    sol %= mod;
    sol2 %= mod;
  }
  if (zbroj)
    sol += sol2;
  else
    sol -= sol2;
  while (sol < 0) sol += mod;
  sol %= mod;
  printf("%d\n", sol);
}
int main() {
  load();
  solve();
  return 0;
}
