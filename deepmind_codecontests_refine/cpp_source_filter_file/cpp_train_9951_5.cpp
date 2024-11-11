#include <bits/stdc++.h>
using namespace std;
const int Maxn = 400000 + 10;
const long long Mod = 1e9 + 7;
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
  return x < 0 ? x + Mod : x;
}
int n;
char ch[Maxn];
long long J[Maxn];
long long C(long long n, long long m) {
  return J[m] * inv(J[n]) % Mod * inv(J[m - n]) % Mod;
}
void solve() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  J[0] = 1ll;
  for (int i = 1; i <= n * 2; i++) J[i] = (long long)i * J[i - 1];
  long long x = 0, y = 0, ans = 0ll;
  for (int i = 1; i <= n; i++)
    if (ch[i] == ')') y++;
  for (int i = 1; i <= n; i++) {
    if (ch[i] == ')') {
      y--;
      continue;
    }
    x++;
    ans += C(x, x + y - 1);
    ans %= Mod;
  }
  printf("%I64d\n", ans);
}
int main() {
  solve();
  return 0;
}
