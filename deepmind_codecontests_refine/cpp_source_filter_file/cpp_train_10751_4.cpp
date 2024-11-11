#include <bits/stdc++.h>
template <class T>
void read(T &);
template <class T>
void write(const T &);
typedef const long long &cll;
typedef const int &ci;
const int iinf = 2147483647;
const long long llinf = 9223372036854775807ll;
using std::abs;
using std::max;
using std::min;
const int N = 50005;
const int M = 50005;
void add(int u, int v);
void dfs(int u);
int hed[N], nxt[M], to[M], id;
int dep[N];
int dfn[N], tot, qwq[N];
int l[N], r[N];
int a[N];
int sum[N];
int dsum[N];
int tim[N];
int n, q;
int main() {
  read(n), read(q);
  for (int i = 1; i <= n; ++i) {
    read(a[i]);
    if (a[i] == 1) {
      sum[i] = 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    int fa;
    read(fa);
    add(fa, i);
  }
  dfs(1);
  for (register int i = 1; i <= q; ++i) {
    int u;
    read(u);
    int ans1 = sum[u];
    int ans2 = dsum[u];
    for (register int j = l[u]; j <= r[u]; ++j) {
      int v = qwq[j];
      if (i >= a[v]) {
        ++ans1;
        ans2 += dep[v];
        tim[v] = i + a[v];
      }
    }
    ans2 -= ans1 * dep[u];
    write(ans2), putchar(' '), write(ans1), putchar('\n');
  }
  return 0;
}
template <class T>
inline void read(T &Re) {
  T k = 0;
  char ch = getchar();
  int flag = 1;
  while (!(ch >= '0' && ch <= '9')) {
    if (ch == '-') {
      flag = -1;
    }
    ch = getchar();
  }
  while ((ch >= '0' && ch <= '9')) {
    k = (k << 1) + (k << 3) + ch - '0';
    ch = getchar();
  }
  Re = flag * k;
}
template <class T>
inline void write(const T &Wr) {
  if (Wr < 0) {
    putchar('-');
    write(-Wr);
  } else {
    if (Wr < 10) {
      putchar(Wr + '0');
    } else {
      write(Wr / 10);
      putchar((Wr % 10) + '0');
    }
  }
}
void add(int u, int v) {
  nxt[++id] = hed[u];
  hed[u] = id;
  to[id] = v;
}
void dfs(int u) {
  l[u] = tot + 1;
  if (sum[u] == 1) {
    dsum[u] = dep[u];
  } else {
    dfn[u] = ++tot;
    qwq[tot] = u;
  }
  for (int i = hed[u]; i; i = nxt[i]) {
    int v = to[i];
    dep[v] = dep[u] + 1;
    dfs(v);
    sum[u] += sum[v];
    dsum[u] += dsum[v];
  }
  r[u] = tot;
}
