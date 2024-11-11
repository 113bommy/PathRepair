#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long h[N], e[N], nx[N], idx;
long long k, T, t, n, m, ans, cnt;
long long a[N], pre[10][N];
bool vis[N];
char s[N];
char str[10][10] = {" ", " abc", " acb", " bac", " bca", " cab", " cba"};
priority_queue<long long, vector<long long>, greater<long long> > q;
void init() {
  char x;
  for (long long i = 1; i <= 6; i++) {
    for (long long x = 1, y = 1; x <= n; x++, y++) {
      if (y > 3) y = 1;
      pre[i][x] = pre[i][x - 1] + (s[x] != str[i][y]);
    }
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> s + 1;
  init();
  while (m--) {
    long long l, r, res = 0x3f3f3f3f;
    cin >> l >> r;
    if (l == r)
      cout << 0 << '\n';
    else if (r - l == 1) {
      if (s[l] != s[r])
        cout << 0 << '\n';
      else
        cout << 1 << '\n';
    } else {
      for (long long i = 1; i <= 6; i++)
        res = min(res, pre[i][r] - pre[i][l - 1]);
      cout << res << '\n';
    }
  }
  return 0;
}
