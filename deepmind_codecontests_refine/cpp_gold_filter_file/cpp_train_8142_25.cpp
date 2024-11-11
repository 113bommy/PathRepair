#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e5 + 10;
int t[N], S[N], n, MOD;
int pos[N], len[N];
int le[N], ri[N];
int p0[N], p1[N];
int hsh0[N], hsh1[N];
char s[N];
int ql(int x) { return (ri[x] - x + 1) & 1; }
int qr(int x) { return (x - le[x] + 1) & 1; }
pair<int, int> qhash(int l, int r) {
  l++, r++;
  int v0 = (hsh0[r] - 1ll * p0[r - l + 1] * hsh0[l - 1] % MOD + MOD) % MOD;
  int v1 = (hsh1[r] - 1ll * p1[r - l + 1] * hsh1[l - 1] % MOD + MOD) % MOD;
  return {v0, v1};
}
bool isprime(long long x) {
  for (int i = 2; 1ll * i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(0));
  MOD = 1e9 + 7 + rand();
  while (!isprime(MOD)) ++MOD;
  cin >> n >> (s + 1);
  le[0] = 1, ri[n + 1] = n;
  for (int i = 1; i <= n; i++) S[i] = S[i - 1] + (s[i] == '0');
  for (int i = 1; i <= n; i++) le[i] = (s[i] == '0' ? i + 1 : le[i - 1]);
  for (int i = n; i >= 1; i--) ri[i] = (s[i] == '0' ? i - 1 : ri[i + 1]);
  for (int i = 1; i <= n; i++)
    if (s[i] == '1') len[S[i] + 1] ^= 1;
  p0[0] = p1[0] = 1;
  for (int i = 1; i <= n + 1; i++) p0[i] = 233ll * p0[i - 1] % MOD;
  for (int i = 1; i <= n + 1; i++) p1[i] = 237ll * p1[i - 1] % MOD;
  for (int i = 1; i <= n + 1; i++)
    hsh0[i] = (hsh0[i - 1] * 233ll + len[i]) % MOD;
  for (int i = 1; i <= n + 1; i++)
    hsh1[i] = (hsh1[i - 1] * 237ll + len[i]) % MOD;
  int _;
  cin >> _;
  while (_--) {
    int l, r, len;
    cin >> l >> r >> len;
    int s1 = S[r + len - 1] - S[r - 1];
    int s2 = S[l + len - 1] - S[l - 1];
    if (s1 != s2)
      puts("NO");
    else if (!s1 || s1 == len)
      puts("YES");
    else if (ql(l) != ql(r))
      puts("NO");
    else if (qr(l + len - 1) != qr(r + len - 1))
      puts("NO");
    else {
      int p1 = S[l - 1] + 1, p2 = S[l + len - 1] - 1;
      int p3 = S[r - 1] + 1, p4 = S[r + len - 1] - 1;
      puts(qhash(p1, p2) == qhash(p3, p4) ? "YES" : "NO");
    }
  }
  return 0;
}
