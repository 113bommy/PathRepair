#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int f[55][100000][2], ch[100010][10], tot, tag[1000010], q[1000010],
    fail[1000010], a[10000];
char s[10000], x[100000], y[10000];
int read() {
  int x = 0, flag = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * flag;
}
void Insert(int l, int r) {
  int now = 0;
  for (int i = l; i <= r; i++) {
    int c = s[i] - '0';
    if (!ch[now][c]) ch[now][c] = ++tot;
    now = ch[now][c];
  }
  tag[now] = 1;
}
void build() {
  int h = 1, t = 0;
  for (int i = 0; i < 10; i++)
    if (ch[0][i]) q[++t] = ch[0][i];
  while (h <= t) {
    int u = q[h++];
    for (int i = 0; i < 10; i++) {
      if (ch[u][i])
        fail[ch[u][i]] = ch[fail[u]][i], q[++t] = ch[u][i];
      else
        ch[u][i] = ch[fail[u]][i];
    }
  }
}
int dfs(int pos, int u, int lim, int sta) {
  if (pos == 0) return sta;
  if (~f[pos][u][sta] && !lim) return f[pos][u][sta];
  int num = lim ? a[pos] : 9, ans = 0;
  for (int i = 0; i <= num; i++) {
    int ss = sta | tag[ch[u][i]];
    ans = (ans + dfs(pos - 1, ch[u][i], lim && i == num, ss)) % mod;
  }
  if (!lim) f[pos][u][sta] = ans;
  return ans;
}
int main() {
  memset(f, -1, sizeof(f));
  scanf("%s%s%s", s + 1, x + 1, y + 1);
  int n = strlen(s + 1), d = strlen(x + 1);
  reverse(x + 1, x + d + 1);
  reverse(y + 1, y + d + 1);
  for (int i = 1; i + d / 2 - 1 <= n; i++) Insert(i, i + d / 2 - 1);
  build();
  for (int i = 1; i <= d; i++) a[i] = x[i] - '0';
  long long ss = dfs(d, 0, 1, 0);
  for (int i = 1; i <= d; i++) a[i] = y[i] - '0';
  long long tt = dfs(d, 0, 1, 0);
  int now = 0;
  for (int i = d; i >= 1; i--) {
    int c = x[i] - '0';
    now = ch[now][c];
    if (tag[now]) {
      ss--;
      break;
    }
  }
  cout << (tt - ss + mod) % mod;
  return 0;
}
