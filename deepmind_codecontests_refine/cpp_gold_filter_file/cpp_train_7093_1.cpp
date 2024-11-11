#include <bits/stdc++.h>
using namespace std;
const int N = 10009, inf = 10001;
inline long long read() {
  register long long x = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48, c = getchar();
  }
  return x * f;
}
char str[N];
int n, a, b, s[N];
long long f[N];
int ch[N][29], st[N], len[N] = {inf}, lk[N], tot = 1, rem, now = 1, sz;
int newn(int s, int l) { return len[++tot] = l, st[tot] = s, lk[tot] = 1, tot; }
void extend(int x) {
  rem++, sz++;
  int last = 1;
  while (rem) {
    while (rem > len[ch[now][s[sz - rem + 1]]])
      rem -= len[now = ch[now][s[sz - rem + 1]]];
    int &v = ch[now][s[sz - rem + 1]], c = s[st[v] + rem - 1];
    if (x == c || !v) {
      lk[last] = now, last = now;
      if (!v)
        v = newn(sz - rem + 1, inf);
      else
        break;
    } else {
      int u = newn(st[v], rem - 1);
      ch[u][x] = newn(sz, inf), ch[u][c] = v;
      st[v] += rem - 1, len[v] -= rem - 1;
      lk[last] = v = u, last = u;
    }
    (now == 1 ? rem-- : now = lk[now]);
  }
}
int qwq, rm;
bool run(int x) {
  if (rm == len[qwq] || qwq == 1) {
    if (ch[qwq][x])
      return qwq = ch[qwq][x], rm = 1, 1;
    else
      return 0;
  } else {
    if (st[qwq] + rm <= sz && s[st[qwq] + rm] == x)
      return rm++, 1;
    else
      return 0;
  }
}
int main() {
  n = read(), a = read(), b = read();
  memset(f, 0x3f, sizeof(f));
  scanf("%s", str + 1);
  for (register int i = (1); i <= (n); i++) s[i] = str[i] - 'a' + 1;
  f[1] = a;
  for (register int i = (1); i <= (n); i++) {
    extend(s[i]);
    qwq = 1, rm = 0;
    f[i + 1] = min(f[i + 1], f[i] + a);
    for (register int j = (i + 1); j <= (n); j++) {
      if (!run(s[j])) break;
      f[j] = min(f[j], f[i] + b);
    }
  }
  printf("%lld\n", f[n]);
  return 0;
}
