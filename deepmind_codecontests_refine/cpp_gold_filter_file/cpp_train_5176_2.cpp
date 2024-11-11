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
inline void writes(string s) { puts(s.c_str()); }
inline void writeln() { writes(""); }
inline void writei(int x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline void writell(long long x) {
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
int n, m, i, j, s[10000005], ans[10000005], a[100005], md[10000005],
    p[10000005], pc, fa[100005][19], mod = 1e9 + 7, inv[10000005], pk[100005],
                                     dep[100005];
vector<int> e[100005];
vector<pair<int, int> > seq[100005];
int pw(int x, int y) {
  int z = 1;
  while (y) {
    if (y & 1) {
      z = 1ll * z * x % mod;
    }
    x = 1ll * x * x % mod;
    y /= 2;
  }
  return z;
}
void dfs1(int x, int p) {
  fa[x][0] = p;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++) {
    if (*it == p) continue;
    dep[*it] = dep[x] + 1;
    dfs1(*it, x);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int t = dep[x] - dep[y], i;
  for ((i) = (18); (i) >= (0); (i)--) {
    if ((t >> i) & 1) {
      x = fa[x][i];
    }
  }
  if (x == y) return x;
  for ((i) = (18); (i) >= (0); (i)--) {
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  }
  return fa[x][0];
}
void inc(int x) {
  while (x != 1) {
    int t = md[x], j = 1;
    while (x % t == 0) {
      j = j * t;
      s[j] = 1ll * s[j] * t % mod;
      x /= t;
    }
  }
}
void dec(int x) {
  while (x != 1) {
    int t = md[x], j = 1;
    while (x % t == 0) {
      j = j * t;
      s[j] = 1ll * s[j] * inv[t] % mod;
      x /= t;
    }
  }
}
void qry(int x, int id, int op) {
  while (x != 1) {
    int t = md[x], j = 1;
    while (x % t == 0) {
      j = j * t;
      ans[id] = 1ll * ans[id] * (op ? s[j] : pw(s[j], mod - 2)) % mod;
      x /= t;
    }
  }
}
void dfs2(int x, int p) {
  inc(a[x]);
  for (__typeof((seq[x]).begin()) it = (seq[x]).begin(); it != (seq[x]).end();
       it++) {
    qry(pk[it->first], it->first, it->second);
  }
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++) {
    if (*it != p) dfs2(*it, x);
  }
  dec(a[x]);
}
int main() {
  inv[1] = 1;
  md[1] = 1;
  s[1] = 1;
  for (i = 2; i <= 10000000; i++) {
    s[i] = 1;
    inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    if (!md[i]) {
      md[i] = i;
      p[++pc] = i;
    }
    for (j = 1; j <= pc; j++) {
      if (i * p[j] > 10000000) {
        break;
      }
      md[i * p[j]] = p[j];
      if (i % p[j] == 0) {
        break;
      }
    }
  }
  read(n);
  for (((i)) = (1); ((i)) <= ((n - 1)); ((i))++) {
    int x, y;
    read(x);
    read(y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    read(a[i]);
  }
  dfs1(1, 0);
  for (((j)) = (1); ((j)) <= ((18)); ((j))++) {
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
  }
  read(m);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    int x, y, z;
    read(x);
    read(y);
    read(pk[i]);
    ans[i] = 1;
    z = lca(x, y);
    seq[x].push_back(make_pair(i, 1));
    seq[y].push_back(make_pair(i, 1));
    seq[z].push_back(make_pair(i, 0));
    seq[fa[z][0]].push_back(make_pair(i, 0));
  }
  dfs2(1, 0);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
