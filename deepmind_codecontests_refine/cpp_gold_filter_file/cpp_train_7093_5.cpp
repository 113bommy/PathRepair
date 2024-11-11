#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11000;
const int MAXS = 26;
struct SAM {
  struct Node {
    int nxt[MAXS], par;
    int len, maxr;
  } st[MAXN];
  int n, m, root, lst;
  int newNode(int l) {
    int x = ++m;
    memset(st[x].nxt, 0, sizeof st[x].nxt);
    st[x].par = 0;
    st[x].len = l;
    st[x].maxr = 0;
    return x;
  }
  void extend(int d, char c) {
    int x = c - 'a';
    int p = lst, np = newNode(st[p].len + 1);
    lst = np;
    st[np].maxr = d;
    while (p && !st[p].nxt[x]) st[p].nxt[x] = np, p = st[p].par;
    if (!p) {
      st[np].par = root;
      return;
    }
    int q = st[p].nxt[x];
    if (st[q].len == st[p].len + 1) {
      st[np].par = q;
      return;
    }
    int nq = newNode(st[p].len + 1);
    memcpy(st[nq].nxt, st[q].nxt, sizeof st[q].nxt);
    st[nq].par = st[q].par;
    st[np].par = st[q].par = nq;
    while (p && st[p].nxt[x] == q) st[p].nxt[x] = nq, p = st[p].par;
  }
  void build(char* s, int l) {
    static int c[MAXN], d[MAXN];
    n = l;
    m = 0;
    lst = root = newNode(0);
    for (int i = 1; i <= n; i++) extend(i, s[i]);
  }
  void get_maxr() {
    static int c[MAXN], d[MAXN];
    for (int i = 0; i <= n; i++) c[i] = 0;
    for (int i = 1; i <= m; i++) c[st[i].len]++;
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= m; i++) d[c[st[i].len]--] = i;
    for (int i = m; i >= 2; i--)
      st[st[d[i]].par].maxr = max(st[st[d[i]].par].maxr, st[d[i]].maxr);
  }
} sam;
char s[MAXN];
int f[MAXN];
int main() {
  int n, a, b;
  scanf("%d%d%d%s", &n, &a, &b, s + 1);
  reverse(s + 1, s + n + 1);
  sam.build(s, n);
  sam.get_maxr();
  for (int i = n; i >= 1; i--) {
    f[i] = f[i + 1] + a;
    int p = sam.root;
    for (int j = i; j <= n; j++) {
      p = sam.st[p].nxt[s[j] - 'a'];
      if (sam.st[p].maxr - j + i <= j) break;
      f[i] = min(f[i], f[j + 1] + b);
    }
  }
  printf("%d\n", f[1]);
  return 0;
}
