#include <bits/stdc++.h>
using namespace std;
const int maxn = 23;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const long long llINF = 0x3f3f3f3f3f3f3f3f;
long long make_compiler_happy() { return INF ^ 3 ^ maxn ^ mod ^ llINF; }
long long fpow(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return fpow(x, mod - 2); }
mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
int cnt[1 << maxn];
int g[1 << maxn];
string str[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> str[i];
  g[0] = 1;
  for (int i = 0; i < (1 << n); i++) g[i] = mod - g[i & (i - 1)];
  g[0] = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    memset(cnt, 0, sizeof(cnt[0]) * (1 << n));
    for (int i = 0; i < (n); i++)
      for (char t : str[i])
        if (t == c) cnt[1 << i]++;
    for (int s = 0; s < (1 << n); s++) {
      int t = s & -s;
      if (t != s) cnt[s] = min(cnt[t], cnt[s ^ t]);
      g[s] = (long long)g[s] * (cnt[s] + 1) % mod;
    }
  }
  for (int i = 0; i < (n); i++)
    for (int s = 0; s < (1 << n); s++)
      if (s & (1 << i)) g[s] = (g[s] + g[s ^ (1 << i)]) % mod;
  long long ans = 0;
  for (int s = 0; s < (1 << n); s++) {
    long long t = 0, ss = 0;
    for (int i = 0; i < (n); i++) {
      if (s & (1 << i)) {
        ss += i + 1;
        t++;
      }
    }
    ans ^= g[s] * ss * t;
  }
  cout << ans << '\n';
}
