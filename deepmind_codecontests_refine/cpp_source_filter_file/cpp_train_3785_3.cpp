#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, m, t;
int c[111];
int now = 1;
inline int calc(bitset<120> s) {
  if (now > m - 1 >> 1) return 1;
  now++;
  int ans = calc(s), add;
  now--;
  if (c[now] and !s[now]) {
    s |= s << now | s >> now | s << m - now | s >> m - now;
    now++;
    add = calc(s);
    now--;
    ans += (long long)add * c[now] % mod;
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
  cout << calc(bitset<120>(1)) << endl;
  return 0;
}
