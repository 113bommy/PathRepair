#include <bits/stdc++.h>
using namespace std;
const int MAXBUF = 1 << 23;
char B[MAXBUF], *Si = B, *Ti = B;
inline char getc() {
  if (Si == Ti) Ti = (Si = B) + fread(B, 1, MAXBUF, stdin);
  if (Si == Ti)
    return 0;
  else
    return *Si++;
}
template <class T>
inline void read(T &a) {
  static char c;
  static int fh;
  while (((c = getc()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    fh = -1, a = 0;
  else
    fh = 1, a = c - '0';
  while ((c = getc()) <= '9' && c >= '0') a = (a << 3) + (a << 1) + c - '0';
  if (fh == -1) a = -a;
}
char Buff[MAXBUF], *sti = Buff;
template <class T>
inline void write(T a) {
  if (a == 0) {
    *sti++ = '0';
    return;
  }
  if (a < 0) *sti++ = '-', a = -a;
  static char c[20];
  static int c0;
  c0 = 0;
  while (a) c[c0++] = a % 10 + '0', a /= 10;
  while (c0--) *sti++ = c[c0];
}
struct node {
  int a, b;
} t[100005];
long long a[110005], maxm = 0, res;
int tag[405], pi[405], siz[405];
int que[405][257], q[405], maxa, o = 1;
inline bool cmp(node a, node b) { return a.b < b.b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline void build(int id) {
  int i, lo = (id << 8), hi = ((id + 1) << 8), sz = 0;
  q[++sz] = lo;
  for (i = lo + 1; i < hi; i++) {
    while (sz >= 2 && (a[q[sz]] - a[i]) * (q[sz] - q[sz - 1]) <=
                          (a[q[sz - 1]] - a[q[sz]]) * (i - q[sz]))
      sz--;
    q[++sz] = i;
  }
  siz[id] = sz;
  pi[id] = 1;
  for (i = 1; i <= sz; i++) que[id][i] = q[i];
}
inline void add(int pos) {
  int bl = (pos >> 8), i;
  int l = (bl << 8), r = ((bl + 1) << 8);
  for (i = 0; i < bl; i++) tag[i]++;
  for (i = l; i <= pos; i++) a[i] += i;
  for (i = l; i < r; i++) a[i] += 1ll * tag[bl] * i;
  tag[bl] = 0;
  build(bl);
}
inline long long ask(int id, int o) { return a[o] + 1ll * tag[id] * o; }
inline void ask(int tar) {
  for (int i = 0; i <= tar; i++) {
    while (pi[i] < siz[i] && ask(i, que[i][pi[i]]) < ask(i, que[i][pi[i] + 1]))
      pi[i]++;
    long long qaq = ask(i, que[i][pi[i]]);
    if (qaq > maxm) {
      maxm = qaq;
      o = que[i][pi[i]];
    }
  }
}
int main() {
  int i, j, n, w, pos = 1, maxn = 0;
  read(n);
  read(w);
  for (i = 1; i <= n; i++) {
    read(t[i].a);
    read(t[i].b);
    if (t[i].b > maxn) maxn = t[i].b;
    if (t[i].a > maxa) maxa = t[i].a;
  }
  sort(t + 1, t + n + 1, cmp);
  for (i = 0; i <= (maxa >> 8); i++) build(i);
  for (i = 0; i <= maxn + 1; i++) {
    int tar = -1;
    while (pos <= n && t[pos].b < i) {
      add(t[pos].a);
      tar = max(tar, (t[pos].a >> 8));
      pos++;
    }
    ask(tar);
    res = 1ll * w * i * (n - pos + 1) + maxm;
    write(res);
    *sti++ = ' ';
    write(o);
    *sti++ = '\n';
  }
  fwrite(Buff, 1, sti - Buff, stdout);
  return 0;
}
