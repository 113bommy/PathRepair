#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void Read(T &x) {
  int f = 1;
  char t = getchar();
  while (t < '0' || t > '9') {
    if (t == '-') f = -1;
    t = getchar();
  }
  x = 0;
  while (t >= '0' && t <= '9') {
    x = x * 10 + t - '0';
    t = getchar();
  }
  x *= f;
}
template <class T>
inline void chkmin(T &x, T y) {
  if (x > y) x = y;
}
template <class T>
inline void chkmax(T &x, T y) {
  if (x < y) x = y;
}
const int sigma = 27;
const int maxn = 1004;
const int maxm = 2000006;
int l;
int n;
int m;
int type[sigma];
int str[maxn];
int ans[maxn];
vector<int> c[2];
int fst[maxn];
int v[maxm];
int nxt[maxm];
int e_cn;
vector<int> e[maxn];
int nex[sigma][2];
void addedge(int x, int y) {
  e_cn++, v[e_cn] = y;
  nxt[e_cn] = fst[x], fst[x] = e_cn;
}
void input() {
  static char type[maxn];
  scanf("%s", type);
  l = strlen(type);
  for (int i = 0; i < l; i++) {
    if (type[i] == 'V')
      c[0].push_back(i);
    else
      c[1].push_back(i);
    ::type[i] = (type[i] == 'V') ? 0 : 1;
  }
  Read(n);
  Read(m);
}
void prepare() {
  static char str[maxn];
  int p1, p2;
  int t1, t2;
  char s1[2], s2[2];
  for (int i = 1; i <= m; i++) {
    Read(p1);
    scanf("%s", s1);
    Read(p2);
    scanf("%s", s2);
    t1 = s1[0] == 'V' ? 0 : 1;
    t2 = s2[0] == 'V' ? 0 : 1;
    p1--, p2--;
    e[(p1 << 1) + t1].push_back((p2 << 1) + t2);
    e[(p2 << 1) + (t2 ^ 1)].push_back((p1 << 1) + (t1 ^ 1));
  }
  for (int i = 0; i < 2 * n; i++) {
    sort(e[i].begin(), e[i].end());
    e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
    for (int j = 0; j < (int)e[i].size(); j++) {
      addedge(i, e[i][j]);
    }
  }
  scanf("%s", str);
  for (int i = 0; i < n; i++) ::str[i] = str[i] - 'a';
  for (int i = 0, x; i < l; i++) {
    for (int j = 0; j < 2; j++) {
      x = upper_bound(c[j].begin(), c[j].end(), i) - c[j].begin();
      if (x == (int)c[j].size())
        nex[i][j] = -1;
      else
        nex[i][j] = c[j][x];
    }
  }
}
int limit;
int line[maxn];
int top;
bool mark[maxn];
bool go(int cn) {
  if (mark[cn ^ 1]) return false;
  if (mark[cn]) return true;
  if ((cn >> 1) < limit) {
    if (type[str[cn >> 1]] != (cn & 1)) return false;
  } else if ((cn >> 1) == limit) {
    if (nex[str[limit]][cn & 1] == -1) return false;
  } else {
    if (c[cn & 1].size() == 0) return false;
  }
  mark[cn] = true;
  line[++top] = cn;
  for (int i = fst[cn]; i; i = nxt[i]) {
    if (!go(v[i])) {
      return false;
    }
  }
  return true;
}
bool check(int pos) {
  limit = pos;
  memset(mark, 0, sizeof(mark));
  if (str[limit] == l - 1) return false;
  for (int i = 0; i < n; i++) {
    if (i < limit) {
      if (!go((i << 1) + type[str[i]])) return false;
    } else if (i == limit) {
      top = 0;
      if (!go((i << 1) + type[str[i] + 1])) {
        while (top > 0) mark[line[top--]] = false;
        top = 0;
        if (!go((i << 1) + (type[str[i] + 1] ^ 1))) {
          while (top > 0) mark[line[top--]] = false;
          return false;
        }
      }
    } else {
      top = 0;
      if (!go((i << 1) + type[0])) {
        while (top > 0) mark[line[top--]] = false;
        top = 0;
        if (!go((i << 1) + (type[0] ^ 1))) {
          while (top > 0) mark[line[top--]] = false;
          return false;
        }
      }
    }
  }
  return true;
}
void solve() {
  str[n] = -1;
  for (int i = n; i >= 0; i--) {
    if (check(i)) {
      for (int j = 0; j < n; j++) {
        if (j < i)
          putchar('a' + str[j]);
        else if (j == i) {
          if (mark[j << 1])
            putchar('a' + nex[str[i]][0]);
          else
            putchar('a' + nex[str[i]][1]);
        } else {
          if (mark[j << 1])
            putchar('a' + c[0][0]);
          else
            putchar('a' + c[1][0]);
        }
      }
      putchar('\n');
      return;
    }
  }
  printf("-1\n");
}
int main() {
  input();
  prepare();
  solve();
  return 0;
}
