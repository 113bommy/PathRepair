#include <bits/stdc++.h>
using namespace std;
inline void read(long long &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(long long x) {
  static const int maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void write(int x) {
  static const int maxlen = 100;
  static char s[maxlen];
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (!x) {
    putchar('0');
    return;
  }
  int len = 0;
  for (; x; x /= 10) s[len++] = x % 10 + '0';
  for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}
const int MAXN = 1000010;
int n, lim;
char s[MAXN], a[MAXN], b[MAXN];
bool vis[30];
int use[30];
int tmp[30];
void out() {
  puts("YES");
  int now = 0;
  for (int i = 0; i < lim; i++)
    if (use[i] == -1) {
      while (vis[now]) now++;
      use[i] = now;
      vis[now] = 1;
    }
  for (int i = 0; i < lim; i++) printf("%c", use[i] + 'a');
  puts("");
  return;
}
bool solve(int pos, bool l_op, bool r_op) {
  if (l_op && r_op) return 1;
  if (pos == n) return 1;
  int cur = s[pos], l = a[pos], r = b[pos];
  if (use[cur] != -1) {
    if ((use[cur] >= l || l_op) && (use[cur] <= r || r_op))
      return solve(pos + 1, (use[cur] > l || l_op), use[cur] < r || r_op);
  } else {
    for (int i = (l_op ? 0 : l); i <= (r_op ? lim : r); i++)
      if (!vis[i]) {
        vis[i] = 1;
        use[cur] = i;
        if (solve(pos + 1, (use[cur] > l || l_op), use[cur] < r || r_op))
          return 1;
        vis[i] = 0;
        use[cur] = -1;
      }
  }
  return 0;
}
void doit() {
  read(lim);
  scanf("%s%s%s", s, a, b);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    s[i] = s[i] - 'a';
    a[i] = a[i] - 'a';
    b[i] = b[i] - 'a';
  }
  memset(vis, 0, sizeof(vis));
  memset(use, -1, sizeof(use));
  if (solve(0, 0, 0))
    out();
  else
    puts("NO");
}
int main() {
  int T;
  read(T);
  for (int i = 1; i <= T; i++) doit();
  return 0;
}
