#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, i, j;
int dp[1000005], pre[1000005];
string s, t, st;
int cnt, fa[1000005], ch[1000005][26], len[1000005], lst;
int dif[1000005], tp[1000005];
int pos[1000005];
void init() {
  cnt = 2;
  fa[1] = fa[2] = 1;
  len[1] = -1;
  lst = 2;
}
int fnd(int x, int p) {
  while (st[p] != st[p - len[x] - 1]) x = fa[x];
  return x;
}
void ins(int i) {
  int x = fnd(lst, i);
  if (ch[x][st[i] - 'a']) {
    lst = ch[x][st[i] - 'a'];
    return;
  }
  ++cnt;
  len[cnt] = len[x] + 2;
  int t = fnd(fa[x], i);
  if (ch[t][st[i] - 'a'])
    fa[cnt] = ch[t][st[i] - 'a'];
  else
    fa[cnt] = 2;
  ch[x][st[i] - 'a'] = cnt;
  dif[cnt] = len[cnt] - len[fa[cnt]];
  if (dif[cnt] == dif[fa[cnt]])
    tp[cnt] = tp[fa[cnt]];
  else
    tp[cnt] = fa[cnt];
  lst = cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> s >> t;
  st = " ";
  for (((i)) = (0); ((i)) <= (((int)(s.size())) - 1); ((i))++) {
    st.push_back(s[i]);
    st.push_back(t[i]);
  }
  init();
  n = s.size() * 2;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    dp[i] = 0x3f3f3f3f;
    ins(i);
    if (i % 2 == 0 && st[i] == st[i - 1] && dp[i] > dp[i - 2]) {
      dp[i] = dp[i - 2];
      pre[i] = i - 2;
    }
    int x = lst;
    while (x > 2) {
      pos[x] = i - len[tp[x]] - dif[x];
      if (dif[x] == dif[fa[x]] && dp[pos[x]] > dp[pos[fa[x]]])
        pos[x] = pos[fa[x]];
      if (i % 2 == 0 && dp[i] > dp[pos[x]] + 1) {
        dp[i] = dp[pos[x]] + 1;
        pre[i] = pos[x];
      }
      x = tp[x];
    }
  }
  if (dp[n] >= 0x3f3f3f3f)
    puts("-1");
  else {
    printf("%d\n", dp[n]);
    int x = n;
    while (x) {
      if (pre[x] != x - 2) printf("%d %d\n", pre[x] / 2 + 1, x / 2);
      x = pre[x];
    }
  }
  return 0;
}
