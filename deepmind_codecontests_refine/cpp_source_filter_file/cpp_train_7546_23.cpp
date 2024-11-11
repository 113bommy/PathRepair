#include <bits/stdc++.h>
using namespace std;
long long const Mod = 1e9 + 7;
long long n, Fact[100100];
long long FastPower(long long a, long long b) {
  if (!b) return 1LL;
  long long Res = FastPower(a, b >> 1);
  Res = (Res * Res) % Mod;
  if (b & 1) Res *= a;
  return Res % Mod;
}
long long C(long long N, long long R) {
  if (R > N) return 1LL;
  return (Fact[N] % Mod *
          FastPower((Fact[R] % Mod * Fact[N - R] % Mod) % Mod, Mod - 2)) %
         Mod;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Fact[0] = 1;
  for (long long i = 1; i <= 100000; i++)
    Fact[i] = (i % Mod * Fact[i - 1] % Mod) % Mod;
  cin >> n;
  long long Ans = C(2 * n - 1, n - 1) % Mod;
  cout << (2 * Ans - n + Mod) % Mod << '\n';
  return 0;
}
