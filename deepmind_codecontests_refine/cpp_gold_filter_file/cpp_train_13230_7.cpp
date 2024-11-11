#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int S = (1 << 6);
const int INF = 0x3f3f3f3f;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
char s[MAXN];
int n, m, cnt[10], lim[MAXN], sub[MAXN][S];
int sum[S], id[S], ans[MAXN];
void init() {
  for (int i = 0; i < 6; ++i) {
    id[1 << i] = i;
  }
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    ++cnt[s[i] - 'a'];
    lim[i] = S - 1;
  }
  read(m);
  for (int i = 1; i <= m; ++i) {
    int x;
    read(x);
    lim[x] = 0;
    scanf("%s", s + 1);
    int k = strlen(s + 1);
    for (int j = 1; j <= k; ++j) {
      lim[x] |= (1 << (s[j] - 'a'));
    }
  }
}
void solve() {
  for (int i = n; i >= 1; --i) {
    for (int j = 1; j < S; ++j) {
      sub[i][j] = sub[i + 1][j] + ((lim[i] & j) == lim[i]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] = -1;
    for (int j = 0; j < 6; ++j) {
      if (!((lim[i] >> j) & 1)) continue;
      if (!cnt[j]) continue;
      --cnt[j];
      bool ok = 1;
      for (int s = 1; s < S && ok; ++s) {
        int t = (s & (-s));
        sum[s] = sum[s ^ t] + cnt[id[t]];
        if (sum[s] < sub[i + 1][s]) ok = 0;
      }
      if (ok) {
        ans[i] = j;
        break;
      }
      ++cnt[j];
    }
    if (ans[i] == -1) {
      puts("Impossible");
      return;
    }
  }
  for (int i = 1; i <= n; ++i) {
    putchar(ans[i] + 'a');
  }
  puts("");
}
int main() {
  init();
  solve();
  return 0;
}
