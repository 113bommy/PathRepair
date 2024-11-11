#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, t;
int c[111];
inline int calc(int now, bitset<120> s) {
  if (now > (m - 1) >> 1) return 1;
  int ans = calc(now + 1, s);
  if (c[now] and !s[now]) {
    ans += (long long)calc(
               now + 1, s | s << now | s >> now | s << m - now | s >> m - now) *
           c[now] % mod;
    if (ans >= mod) ans -= mod;
  }
  return ans;
}
int main() {
  cin >> n >> m >> t;
  while (t--) {
    int u;
    cin >> u;
    u %= m;
    c[min(u, m - u)]++;
  }
  cout << calc(1, bitset<120>(1)) << endl;
  return 0;
}
