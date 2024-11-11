#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void chkmin(T1 &x, T2 y) {
  if (y < x) x = y;
}
template <class T1, class T2>
inline void chkmax(T1 &x, T2 y) {
  if (y > x) x = y;
}
const int BUF_SIZE = 1 << 20;
char buf[BUF_SIZE], *P1 = buf, *P2 = buf, obuf[BUF_SIZE], *PO = obuf;
inline char getc() {
  if (P1 == P2) P2 = (P1 = buf) + fread(buf, 1, BUF_SIZE, stdin);
  return P1 == P2 ? EOF : *P1++;
}
inline void read(int &x) {
  register char ch = getc();
  x = 0;
  while (!isdigit(ch)) ch = getc();
  while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getc();
}
inline void flushO() {
  fwrite(obuf, PO - obuf, 1, stdout);
  PO = obuf;
}
inline void putc(char ch) {
  if (PO == obuf + (BUF_SIZE)) flushO();
  *PO++ = ch;
}
inline void prints(char s[]) {
  for (char *ss = s; *ss != '\0'; ss++) putc(*ss);
}
inline void write(long long x) {
  if (x > 9) write(x / 10);
  putc(x % 10 ^ 48);
}
const int N = 305, Q = 2000005, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int a[N][N], n, m, q, x, y, z, ep[Q], c1[Q], c2[Q], id[N][N];
int bcj[N * N], cnt, tcnt;
struct node {
  int x, y, t;
};
vector<node> v1[Q], v2[Q];
inline bool inmap(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }
int ask(int x) { return bcj[x] ? bcj[x] = ask(bcj[x]) : x; }
inline void merge(int x, int y) {
  if (bcj[y] < 0) return;
  x = ask(x);
  y = ask(y);
  if (x != y) bcj[y] = x, cnt++;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= (n); i++)
    for (int j = 1; j <= (m); j++) id[i][j] = (i - 1) * m + j;
  for (int i = 1; i <= (n * m); i++) bcj[i] = -1;
  for (int i = 1; i <= (q); i++) {
    scanf("%d%d%d", &x, &y, &z);
    if (a[x][y] != z) {
      v2[a[x][y]].push_back({x, y, i - 1});
      v1[z].push_back({x, y, i});
      a[x][y] = z;
      ep[z] = i;
    }
  }
  for (int i = 1; i <= (n); i++)
    for (int j = 1; j <= (m); j++) v2[a[i][j]].push_back({i, j, q});
  for (int i = 0; i <= (2000000); i++) {
    tcnt = 0;
    for (node px : v1[i]) {
      z = id[px.x][px.y];
      bcj[z] = cnt = 0;
      for (int j = 0; j <= (3); j++)
        if (inmap(x = px.x + dx[j], y = px.y + dy[j])) merge(z, id[x][y]);
      c1[px.t] += 1 - cnt;
      tcnt += 1 - cnt;
    }
    c1[ep[i] + 1] -= tcnt;
    for (node px : v1[i]) bcj[id[px.x][px.y]] = -1;
    tcnt = 0;
    for (int j = (int)v2[i].size() - 1; j >= (0); j--) {
      node px = v2[i][j];
      z = id[px.x][px.y];
      bcj[z] = cnt = 0;
      for (int j = 0; j <= (3); j++)
        if (inmap(x = px.x + dx[j], y = px.y + dy[j])) merge(z, id[x][y]);
      c2[px.t] += 1 - cnt;
      tcnt += 1 - cnt;
    }
    c2[ep[i]] -= tcnt;
    for (node px : v2[i]) bcj[id[px.x][px.y]] = -1;
  }
  for (int i = 1; i <= (q); i++) c1[i] += c1[i - 1];
  for (int i = q; i >= (1); i--) c2[i] += c2[i + 1];
  for (int i = 1; i <= (q); i++) printf("%d\n", c1[i] + c2[i]);
}
