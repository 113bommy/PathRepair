#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int w[MAXN];
map<int, int> f;
long long Calc(long long Res, long long Mod) {
  if (Res > Mod) return Res % Mod + Mod;
  return Res;
}
long long power(long long a, long long n, long long Mod) {
  long long Res = 1;
  while (n) {
    if (n & 1) Res = Calc(Res * a, Mod);
    a = Calc(a * a, Mod);
    n >>= 1;
  }
  return Res;
}
int phi(int n) {
  int result = 1;
  if (f.count(n)) return f[n];
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        result *= i;
      }
      result /= i;
      result *= (i - 1);
    }
  }
  if (n != 1) result *= (n - 1);
  f[n] = result;
  return f[n];
}
long long Solve(int l, int r, int Mod) {
  if (l == r || Mod == 1) return Calc(w[l], Mod);
  return power(w[l], Solve(l + 1, r, phi(Mod)), Mod);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, n, Mod;
  cin >> n >> Mod;
  for (int i = 1; i <= n; ++i) cin >> w[i];
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    long long ans = Solve(l, r, Mod);
    cout << ans % Mod << endl;
  }
  return 0;
}
