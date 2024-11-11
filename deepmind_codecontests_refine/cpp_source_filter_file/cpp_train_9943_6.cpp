#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readin(T &x) {
  x = 0;
  char ch = getchar();
  T fh = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fh = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
  x *= fh;
}
template <typename T>
void wt(T x) {
  if (x > 9) wt(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
void writeln(T x, char ch) {
  wt(x);
  putchar(ch);
}
const int N = 1e5 + 5;
int hd[N], num[N], siz[N], son[N], cnt[N], c[N], st[N], en[N], tot, rec[N];
struct info {
  int to, nex;
} l[N << 1];
void build(int p, int fa) {
  tot++;
  rec[tot] = p;
  st[p] = tot;
  int u;
  for (int e = hd[p]; e; e = l[e].nex) {
    u = l[e].to;
    if (u != fa) {
      build(u, p);
      if (siz[u] > siz[son[p]]) son[p] = u;
      siz[p] += siz[u];
    }
  }
  siz[p]++;
  en[p] = tot;
}
int ans[N];
void dfs(int p, int fa, int opt) {
  int u;
  for (int e = hd[p]; e; e = l[e].nex) {
    u = l[e].to;
    if (u != fa && u != son[p]) dfs(u, p, 0);
  }
  if (son[p]) {
    dfs(son[p], p, 1);
    num[p] = num[son[p]];
    ans[p] = ans[son[p]];
  }
  cnt[c[p]]++;
  if (cnt[c[p]] > num[p]) {
    num[p] = cnt[c[p]];
    ans[p] = c[p];
  } else if (cnt[c[p]] == num[p]) {
    ans[p] += c[p];
  }
  int v;
  for (int e = hd[p]; e; e = l[e].nex) {
    u = l[e].to;
    if (u != fa && u != son[p]) {
      for (int i = st[u]; i <= en[u]; i++) {
        v = rec[i];
        cnt[c[v]]++;
        if (cnt[c[v]] > num[p]) {
          num[p] = cnt[c[v]];
          ans[p] = c[v];
        } else if (cnt[c[v]] == num[p]) {
          ans[p] += c[v];
        }
      }
    }
  }
  if (!opt) {
    for (int i = st[p]; i <= en[p]; i++) {
      cnt[c[rec[i]]]--;
    }
  }
}
int main() {
  int n;
  readin(n);
  for (int i = 1; i <= n; i++) readin(c[i]);
  int u, v;
  for (int i = 1; i < n; i++) {
    readin(u);
    readin(v);
    l[i] = (info){v, hd[u]};
    hd[u] = i;
    l[i + n] = (info){u, hd[v]};
    hd[v] = i + n;
  }
  build(1, 0);
  dfs(1, 0, 1);
  for (int i = 1; i < n; i++) writeln(ans[i], ' ');
  writeln(ans[n], '\n');
  return 0;
}
