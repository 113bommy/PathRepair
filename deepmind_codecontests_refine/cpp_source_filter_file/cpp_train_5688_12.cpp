#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 5050;
int n, k, p[2][N], deg = 0;
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += MOD;
}
int expomod(long long a, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) res = res * a % MOD;
    e /= 2;
    a = a * a % MOD;
  }
  return res;
}
int subs(int a, int b) {
  int ans = a - b;
  if (ans < 0) ans += MOD;
  return ans;
}
int main() {
  cin >> n >> k;
  p[0][0] = 1;
  auto act = p[0], nxt = p[1];
  long long prod = 1;
  for (int i = 0; i < int(n); i++) {
    int c;
    cin >> c;
    prod = prod * c % MOD;
    fill_n(nxt, deg + 2, 0);
    for (int i = 0; i < int(deg + 1); i++) {
      add(nxt[i], (long long)act[i] * c % MOD);
      sub(nxt[i + 1], act[i]);
    }
    deg++;
    swap(act, nxt);
  }
  long long ans = 0, coef = expomod(n, k), invn = expomod(n, MOD - 2);
  long long den = expomod(coef, MOD - 2);
  for (int i = 0; i < int(min(k + 1, deg + 1)); i++) {
    ans += coef * act[i];
    coef = coef * invn % MOD;
    coef = coef * (k - i) % MOD;
  }
  ans %= MOD;
  ans = ans * den % MOD;
  cout << subs(prod, ans) << endl;
  return 0;
}
