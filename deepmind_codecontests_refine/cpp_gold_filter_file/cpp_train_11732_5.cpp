#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(1)
#pragma GCC optimize(2)
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 4e5 + 10;
const int maxn = 1e9;
int T, n, m;
int vis[N];
int k, x, y, z, v, h, l, rsum, ans, cnt;
string str;
struct ss {
  char s;
  int u;
} sss[N];
bool cmp(ss a, ss b) {
  if (a.s == b.s) return a.u < b.u;
  return a.s < b.s;
}
void cf() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> sss[i].s;
    sss[i].u = i;
    str += sss[i].s;
  }
  memset(vis, 0, sizeof(vis));
  ;
  sort(sss + 1, sss + 1 + n, cmp);
  for (int i = 1; i <= m; i++) {
    vis[sss[i].u] = 1;
  }
  for (int i = 0; i < str.length(); i++) {
    if (vis[i + 1] == 0) {
      cout << str[i];
    }
  }
  cout << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) {
    cf();
  }
  return 0;
}
