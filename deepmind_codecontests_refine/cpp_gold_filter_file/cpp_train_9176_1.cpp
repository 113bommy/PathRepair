#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  bool f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(48 + x % 10);
}
inline void writeln(int x) {
  write(x);
  putchar('\n');
}
inline void writebl(int x) {
  write(x);
  putchar(' ');
}
const int maxn = 5e5 + 5;
struct node {
  int id, v;
  bool operator<(const node &a) const { return a.v == v ? id < a.id : v > a.v; }
} st[maxn];
int n, s[maxn], res[maxn];
int p[maxn];
signed main() {
  int t = read(), err = 0, top = 1;
  while (t--) {
    n = read();
    err = 0;
    s[top = 1] = n + 1;
    for (register int i = 1; i <= n; ++i) {
      p[i] = read();
      while (s[top] <= i) top--;
      if (!err && p[i] > s[top]) err = 1;
      s[++top] = p[i];
      while (s[top] <= i) top--;
      st[i] = (node){i, p[i]};
    }
    if (err) {
      puts("-1");
      continue;
    }
    for (register int i = 1; i <= n; ++i)
      if (p[i] != -1 && p[p[i]] == -1) st[p[i]].v = p[i] + 1;
    sort(st + 1, st + n + 1);
    for (register int i = 1; i <= n; ++i) res[st[i].id] = n - i + 1;
    for (register int i = 1; i <= n; ++i) writebl(res[i]);
    puts("");
  }
}
