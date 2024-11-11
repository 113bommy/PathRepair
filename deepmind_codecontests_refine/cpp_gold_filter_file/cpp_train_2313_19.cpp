#include <bits/stdc++.h>
using namespace std;
const unsigned MAXN = 6e5 + 5;
const unsigned long long P = 1e18;
map<unsigned, unsigned> mp;
unsigned long long tot, ans2;
pair<unsigned long long, unsigned long long> ans;
unsigned st[MAXN], top, col[MAXN];
unsigned mn[20][MAXN], lg[MAXN], s[MAXN];
unsigned n, fa[26][MAXN], nxt[MAXN], val[MAXN];
inline unsigned read() {
  unsigned x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline unsigned readin() {
  char ch = getchar();
  while (!isalpha(ch)) ch = getchar();
  return ch - 'a';
}
inline pair<unsigned long long, unsigned long long> operator+(
    const pair<unsigned long long, unsigned long long> &x,
    unsigned long long y) {
  return make_pair((x.first + y) % P, (x.first + y) / P + x.second);
}
inline unsigned long long operator%(
    const pair<unsigned long long, unsigned long long> &x,
    unsigned long long p) {
  return (x.first % p + (x.second % p) * (P % p) % p) % p;
}
inline void print(const pair<unsigned long long, unsigned long long> &x) {
  if (x.second)
    printf("%llu%018llu\n", x.second, x.first);
  else
    printf("%llu\n", x.first);
}
inline void get_lg() {
  for (unsigned i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
}
inline void add(unsigned pos) {
  mn[0][pos] = val[pos];
  for (unsigned i = 1; (1u << i) <= pos; i++)
    mn[i][pos] = min(mn[i - 1][pos], mn[i - 1][pos - (1 << (i - 1))]);
}
inline unsigned ask(unsigned l, unsigned r) {
  unsigned len = lg[r - l + 1];
  return min(mn[len][r], mn[len][l + (1 << len) - 1]);
}
inline void modify(signed x, signed val) { mp[x] += val, tot += 1ll * x * val; }
inline unsigned query(unsigned cur) {
  unsigned siz = 0;
  for (auto it = mp.upper_bound(cur); it != mp.end(); ++it) {
    auto x = *it;
    st[++top] = x.first, tot -= 1ll * x.first * x.second, siz += x.second;
  }
  while (top) mp.erase(st[top--]);
  return siz;
}
inline void update(unsigned col, unsigned x, unsigned pos) {
  while (x) modify(ask(pos - x + 1, pos), -1), x = fa[col][x];
}
signed main() {
  n = read();
  get_lg();
  for (unsigned l = 1; l <= n; l++) {
    auto ch = readin();
    val[l] = read();
    (ch += ans % 26) %= 26, val[l] ^= (ans % (1 << 30));
    add(l), s[l] = ch, ans = ans + ask(1, l);
    if (l == 1) {
      print(ans);
      continue;
    }
    unsigned cur = nxt[l - 1];
    while (cur && s[cur + 1] != s[l]) cur = nxt[cur];
    if (s[cur + 1] == s[l]) nxt[l] = cur + 1;
    col[l - 1] = ch;
    for (unsigned i = 0; i < 26; i++) fa[i][l] = fa[i][nxt[l]];
    fa[col[nxt[l]]][l] = nxt[l];
    if (s[1] == s[l]) modify(val[l], 1);
    for (unsigned i = 0; i < 26; i++)
      if (i != ch) update(i, fa[i][l - 1], l - 1);
    modify(val[l], query(val[l]));
    ans = ans + tot, print(ans);
  }
  return 0;
}
