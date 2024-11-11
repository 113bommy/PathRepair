#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200000 + 10;
const long long Mod = 1e9 + 7;
int n, A[Maxn];
long long J[Maxn];
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1ll;
    y = 0ll;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
long long inv(long long a) {
  long long x, y;
  exgcd(a, Mod, x, y);
  return x < Mod ? x + Mod : x;
}
long long C(int n, int m) {
  return J[n] * inv(J[m]) % Mod * inv(J[n - m]) % Mod;
}
void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  if (n == 1) {
    printf("%d\n", A[1]);
    return;
  }
  J[0] = 1ll;
  for (int i = 1; i <= n; i++) J[i] = J[i - 1] * (long long)i;
  if (n & 1) {
    for (int i = 1; i <= n; i++) {
      if (i & 1)
        A[i] = A[i] + A[i + 1];
      else
        A[i] = A[i] - A[i + 1];
    }
    n--;
  }
  long long x = 0ll, y = 0ll;
  for (int i = 1; i <= n / 2; i++) {
    x += (long long)A[i * 2 - 1] * C(n / 2 - 1, i - 1) % Mod;
    if (x >= Mod) x -= Mod;
    y += (long long)A[i * 2] * C(n / 2 - 1, i - 1) % Mod;
    if (y >= Mod) y -= Mod;
  }
  long long ans;
  if (n % 4 == 0)
    ans = x - y;
  else
    ans = x + y;
  ans = ((ans % Mod) + Mod) % Mod;
  printf("%d\n", (int)ans);
}
int main() {
  solve();
  return 0;
}
