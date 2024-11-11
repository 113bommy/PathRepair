#include <bits/stdc++.h>
using namespace std;
const int N = 30 * 30 * 70;
const int inf = 0x1f3f3f3f;
int son[N][26];
char strin[70], curs[70];
bool b[N], over[N];
char dict[50][70];
int f[N], g[N], cnt[N];
int rt, n, tot = 1, curv, cnode = 1;
struct Tnode {
  char s[70];
} node[N];
struct cmp {
  bool operator()(const Tnode &a, const Tnode &b) {
    return strcmp(a.s, b.s) < 0;
  }
};
int find(char *s) {
  int l = 1, r = tot;
  while (l <= r) {
    int mid = l + r >> 1;
    int ncmp = strcmp(node[mid].s, s);
    if (ncmp == 0) return mid;
    if (ncmp < 0)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return 0;
}
template <class T>
inline void checkmax(T &a, const T &b) {
  if (b > a) a = b;
}
bool isprefix(char *a, char *b) {
  for (int i = 0; a[i]; ++i)
    if (a[i] != b[i]) return false;
  return true;
}
bool occur(char *a, char *b) {
  for (int j = 0; b[j]; ++j)
    if (isprefix(a, b + j)) return true;
  return false;
}
int calc(int x) {
  if (x == 1) return 0;
  int tm = 0, ret = 0;
  for (int i = 0; curs[i]; ++i) checkmax(tm, curs[i] - 'a' + 1);
  for (int i = 0; curs[i]; ++i) ret += tm * (curs[i] - 'a' + 1);
  for (int i = 0; i < n; ++i)
    if (occur(curs, dict[i])) ++ret;
  return ret;
}
bool isbetter(int u, int x) {
  if (!b[u] && !b[x]) return true;
  if ((b[u] ^ b[x]) && g[u] > f[x]) return true;
  if ((b[u] ^ b[x]) && g[u] == f[x] && f[u] + curv < g[x]) return true;
  return false;
}
void dp(int x, int depth) {
  if (over[x]) return;
  over[x] = true;
  bool tem = true;
  for (int s = 0; s < 26; ++s) {
    curs[depth] = 'a' + s;
    curs[depth + 1] = 0;
    int u = find(curs);
    if (u != 0) {
      dp(u, depth + 1);
      tem = false;
    }
  }
  char bcur[70];
  for (int s = 0; s < 26; ++s) {
    memcpy(bcur, curs, depth * sizeof(char));
    memmove(curs + 1, curs, depth * sizeof(char));
    curs[0] = 'a' + s;
    curs[depth + 1] = 0;
    int u = find(curs);
    if (u != 0) {
      dp(u, depth + 1);
      tem = false;
    }
    memcpy(curs, bcur, depth * sizeof(char));
  }
  curs[depth] = 0;
  if (tem) {
    b[x] = false;
    f[x] = 0;
    g[x] = calc(x);
  } else {
    b[x] = false;
    f[x] = -1;
    g[x] = 0x3f3f3f3f;
    curv = calc(x);
    for (int s = 0; s < 26; ++s) {
      curs[depth] = 'a' + s;
      curs[depth + 1] = 0;
      int u = find(curs);
      if (u != 0 && isbetter(u, x)) {
        b[x] = !b[u];
        f[x] = g[u];
        g[x] = f[u] + curv;
      }
    }
    for (int s = 0; s < 26; ++s) {
      memcpy(bcur, curs, depth * sizeof(char));
      memmove(curs + 1, curs, depth * sizeof(char));
      curs[0] = 'a' + s;
      curs[depth + 1] = 0;
      int u = find(curs);
      if (u != 0 && isbetter(u, x)) {
        b[x] = !b[u];
        f[x] = g[u];
        g[x] = f[u] + curv;
      }
      memcpy(curs, bcur, depth * sizeof(char));
    }
  }
}
void addstr(char *strin) {
  int t = 1;
  for (int i = 0; strin[i]; ++i) {
    int s = strin[i] - 'a';
    if (son[t][s] == 0) son[t][s] = ++cnode;
    t = son[t][s];
    ++cnt[t];
  }
}
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; ++i) {
    memset(strin, 0, sizeof(strin));
    gets(strin);
    strcpy(dict[i], strin);
    for (int j = 0; strin[j]; ++j) addstr(strin + j);
    for (int j = 0; strin[j]; ++j)
      for (int k = j + 1; strin[k - 1]; ++k) {
        ++tot;
        for (int l = 0; j + l < k; ++l) node[tot].s[l] = strin[j + l];
      }
  }
  sort(node + 1, node + tot + 1, cmp());
  int tn = n;
  n = tot;
  tot = 0;
  for (int i = 1; i <= n; ++i)
    if (tot == 0 || strcmp(node[i].s, node[tot].s) != 0) node[++tot] = node[i];
  n = tn;
  dp(1, 0);
  if (b[1]) {
    printf("First\n");
    printf("%d %d\n", f[1], g[1]);
  } else {
    printf("Second\n");
    printf("%d %d\n", f[1], g[1]);
  }
}
