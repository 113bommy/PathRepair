#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
inline long long ab(long long x) { return x < 0 ? -x : x; }
inline long long mm(long long x) {
  return x >= mod ? x - mod : x < 0 ? x + mod : x;
}
struct SAM {
  static const int KN = N << 1;
  static const int KM = 2;
  int fail[KN], net[KN][KM], len[KN], cnt, root, mark[KN];
  int newnode(int _len) {
    memset(net[cnt], -1, sizeof(net[cnt]));
    fail[cnt] = -1;
    len[cnt] = _len;
    return cnt++;
  }
  void init() {
    cnt = 0;
    root = newnode(0);
  }
  int add(int p, int x) {
    int np = newnode(len[p] + 1);
    while (~p && net[p][x] == -1) net[p][x] = np, p = fail[p];
    if (p == -1)
      fail[np] = root;
    else {
      int q = net[p][x];
      if (len[q] == len[p] + 1)
        fail[np] = q;
      else {
        int nq = newnode(len[p] + 1);
        memcpy(net[nq], net[q], sizeof(net[q]));
        fail[nq] = fail[q];
        fail[q] = fail[np] = nq;
        while (~p && net[p][x] == q) net[p][x] = nq, p = fail[p];
      }
    }
    mark[np] = 1;
    return np;
  }
  void debug() {
    for (int now = 0; now < cnt; ++now) {
      puts(".....................");
      printf("now = %d\n", now);
      printf("len = %d, fail = %d\n", len[now], fail[now]);
      for (int i = 0; i < KM; ++i) printf("net[%d] = %d  ", i, net[now][i]);
      puts("");
      puts(".....................");
    }
  }
  void debug(int id) {
    puts(".....................");
    printf("now = %d\n", id);
    printf("len = %d, fail = %d, mark = %d\n", len[id], fail[id], mark[id]);
    for (int i = 0; i < KM; ++i) printf("net[%d] = %d  ", i, net[id][i]);
    puts("");
    puts(".....................");
  }
  void build(char *s, char ch) {
    int now = root;
    for (int i = 0; s[i]; ++i) now = add(now, s[i] - ch);
  }
  int ord[KN], pri[KN], vis[KN];
  void topo() {
    int maxVal = 0;
    memset(pri, 0, sizeof(pri));
    for (int i = 0; i < cnt; ++i) maxVal = max(maxVal, len[i]), ++pri[len[i]];
    for (int i = 1; i <= maxVal; ++i) pri[i] += pri[i - 1];
    for (int i = 0; i < cnt; ++i) ord[--pri[len[i]]] = i;
  }
  void dfs() {
    vis[0] = 0;
    for (int i = cnt - 1; i >= 1; --i)
      mark[fail[ord[i]]] += mark[ord[i]], vis[i] = 0;
  }
  void go(int &x, int _len) {
    while (len[fail[x]] >= _len) x = fail[x];
  }
  void solve(char *s, char ch, int id) {
    int now = root, ret = 0, _len = strlen(s), __len = 0;
    for (int i = 0; i < _len; ++i) {
      while (now != root && net[now][s[i] - ch] == -1) now = fail[now];
      __len = min(__len, len[now]);
      if (net[now][s[i] - ch] != -1) now = net[now][s[i] - ch], __len++;
    }
    for (int i = 0; i < _len; ++i) {
      while (now != root && net[now][s[i] - ch] == -1) now = fail[now];
      __len = min(__len, len[now]);
      if (net[now][s[i] - ch] != -1) now = net[now][s[i] - ch], __len++;
      go(now, _len);
      __len = min(__len, len[now]);
      if (__len >= _len && vis[now] != id) ret += mark[now], vis[now] = id;
    }
    printf("%d\n", ret);
  }
} sam;
char s[N];
int main() {
  scanf("%s", s);
  sam.init();
  sam.build(s, 'a');
  sam.topo();
  sam.dfs();
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%s", s);
    sam.solve(s, 'a', i);
  }
  return 0;
}
