#include <bits/stdc++.h>
using namespace std;
const int maxn = 100086;
const int inf = 1.0e9;
const long long INF = 999999999999999;
const double eps = 1e-6;
long long a, b, c, ab, ac, bc, abc;
int n;
long long x;
char s[500];
bool vis[500];
int main() {
  a = b = c = ab = ac = bc = abc = inf;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &x);
    scanf("%s", s);
    int l = strlen(s);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < l; i++) {
      vis[s[i] - 'A'] = true;
    }
    if (vis[0] && !vis[1] && !vis[2]) {
      a = min(a, x);
    } else if (!vis[0] && vis[1] && !vis[2]) {
      b = min(b, x);
    } else if (!vis[0] && !vis[1] && vis[2]) {
      c = min(c, x);
    } else if (vis[0] && vis[1] && !vis[2]) {
      ab = min(ab, x);
    } else if (!vis[0] && vis[1] && vis[2]) {
      bc = min(bc, x);
    } else if (vis[0] && !vis[1] && vis[2]) {
      ac = min(ac, x);
    } else if (vis[0] && vis[1] && vis[2]) {
      abc = min(abc, x);
    }
  }
  long long ans = inf;
  ans = min(a + b + c, ans);
  ans = min(ab + c, ans);
  ans = min(ac + b, ans);
  ans = min(bc + a, ans);
  ans = min(abc, ans);
  ans = min(ab + ac, ans);
  ans = min(ab + bc, ans);
  ans = min(ac + bc, ans);
  if (ans == inf) {
    ans = -1;
  }
  printf("%lld\n", ans);
  return 0;
}
