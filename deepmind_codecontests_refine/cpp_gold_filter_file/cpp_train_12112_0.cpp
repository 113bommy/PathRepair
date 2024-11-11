#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 51123987;
const int maxn = 2e6 + 11;
const int sz = 26;
struct link_list {
  int tot, head[maxn], nxt[maxn], ver[maxn], edge[maxn];
  void _clear() {
    memset(head, 0, sizeof(head));
    tot = 0;
  }
  void _clear(int x) { head[x] = 0; }
  int _find(int x, int y) {
    for (int i = head[x]; i; i = nxt[i]) {
      if (ver[i] == y) return edge[i];
    }
    return 0;
  }
  void _ins(int x, int y, int z) {
    ver[++tot] = y;
    edge[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
  }
};
struct node {
  link_list nxt;
  int fail[maxn];
  int cnt[maxn];
  int num[maxn];
  int len[maxn];
  int S[maxn];
  int last;
  int n;
  int p;
  int newnode(int l) {
    nxt._clear(p);
    cnt[p] = 0;
    num[p] = 0;
    len[p] = l;
    return p++;
  }
  void init() {
    nxt._clear();
    p = 0;
    newnode(0);
    newnode(-1);
    last = 0;
    n = 0;
    S[n] = -1;
    fail[0] = 1;
  }
  int get_fail(int x) {
    while (S[n - len[x] - 1] != S[n]) x = fail[x];
    return x;
  }
  int add(int c) {
    c -= 'a';
    S[++n] = c;
    int cur = get_fail(last);
    if (!nxt._find(cur, c)) {
      int now = newnode(len[cur] + 2);
      fail[now] = nxt._find(get_fail(fail[cur]), c);
      nxt._ins(cur, c, now);
      num[now] = num[fail[now]] + 1;
    }
    last = nxt._find(cur, c);
    cnt[last]++;
    return num[last];
  }
  int count() {
    int ans = 0;
    for (int i = p - 1; i >= 2; i--) {
      cnt[fail[i]] = (cnt[fail[i]] + cnt[i]) % mod;
      ans = (ans + cnt[i]) % mod;
    }
    return ans;
  }
} pt;
char str[maxn];
int suf[maxn];
int n;
int main() {
  while (~scanf("%d%s", &n, str)) {
    int ans = 0;
    pt.init();
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--)
      suf[i] = (suf[i + 1] + pt.add(str[i])) % mod;
    pt.init();
    for (int i = 0; i < n; i++)
      ans = (ans + (long long)pt.add(str[i]) * (suf[i + 1])) % mod;
    int tot = pt.count();
    tot = ((long long)tot * (tot - 1) / 2) % mod;
    printf("%d\n", ((tot - ans) % mod + mod) % mod);
  }
  return 0;
}
