#include <bits/stdc++.h>
using namespace std;
void In() { freopen("in.in", "r", stdin); }
void Out() { freopen("out.out", "w", stdout); }
const int N = 1e5 + 10;
const int M = 3e5 + 10;
const int Mbit = 1e6 + 10;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
char s[N];
int ans[N], g[N], f[N];
int main() {
  int n, tmp;
  while (~scanf("%d", &n)) {
    scanf("%s", s + 1);
    for (int i = 0; i < 26; i++) cin >> f[i];
    g[0] = 0;
    ans[0] = 1;
    tmp = 1;
    for (int i = 1; i <= n; i++) {
      int j = i;
      int lim = inf;
      g[i] = g[i - 1] + 1;
      ans[i] = ans[i - 1];
      while (j > 1) {
        lim = min(lim, f[s[j] - 'a']);
        if (lim == (i - j + 1)) break;
        if (i - j + 2 <= f[s[j - 1] - 'a']) {
          j--;
          (ans[i] += ans[j - 1]) %= mod;
          g[i] = min(g[i], g[j - 1] + 1);
          tmp = max(tmp, i - j + 1);
        } else
          break;
      }
    }
    printf("%d\n", ans[n]);
    printf("%d\n", tmp);
    printf("%d\n", g[n]);
  }
  return 0;
}
