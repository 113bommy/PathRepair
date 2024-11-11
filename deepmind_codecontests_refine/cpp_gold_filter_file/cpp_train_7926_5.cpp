#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int Maxn = 2005;
int n, s, t;
char str[1005];
int fath[Maxn], dis[Maxn];
int power(int a, int n, int p) {
  int ans = 1;
  a %= p;
  while (n) {
    if (n & 1) ans = 1ll * ans * a % p;
    a = 1ll * a * a % p;
    n >>= 1;
  }
  return ans;
}
int Find(int x) {
  if (fath[x] == x) return x;
  int rt = Find(fath[x]);
  dis[x] ^= dis[fath[x]];
  return fath[x] = rt;
}
bool Merge(int a, int b, int c) {
  int x = Find(a), y = Find(b);
  if (x == y) return dis[a] ^ dis[b] ^ c ^ 1;
  fath[x] = y;
  dis[x] = dis[a] ^ dis[b] ^ c;
  return true;
}
int solve(int la) {
  for (int i = 1; i <= t; ++i) {
    fath[i] = i;
    dis[i] = 0;
  }
  for (int i = 1; i <= n / 2; ++i) Merge(i, n - i + 1, 0);
  for (int i = 1; i <= la / 2; ++i) Merge(n + i, n + la - i + 1, 0);
  for (int i = la + 1; i <= n; ++i) Merge(n + i, t, 0);
  Merge(1, s, 0);
  Merge(n + 1, s, 0);
  for (int i = 1; i <= n; ++i) {
    if (str[n - i + 1] == '?') continue;
    if (!Merge(n + i, i, str[n - i + 1] - 48)) return 0;
  }
  int cnt = 0;
  for (int i = 1; i <= t; ++i) cnt += fath[i] == i;
  return power(2, cnt - 1, mod);
}
int main() {
  scanf("%s", str + 1);
  n = strlen(str + 1);
  s = n + n + 1;
  t = s + 1;
  int ans = 0;
  for (int i = 1; i < n; ++i) ans = (ans + solve(i)) % mod;
  printf("%d\n", ans);
  return 0;
}
