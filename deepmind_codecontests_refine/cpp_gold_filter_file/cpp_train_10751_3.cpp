#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int MAXSIZE = 10000020;
int bufpos;
char buf[MAXSIZE];
void init() {
  buf[fread(buf, 1, MAXSIZE, stdin)] = '\0';
  bufpos = 0;
}
int readint() {
  int val = 0;
  for (; !isdigit(buf[bufpos]); bufpos++)
    ;
  for (; isdigit(buf[bufpos]); bufpos++) val = val * 10 + buf[bufpos] - '0';
  return val;
}
char readchar() {
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  return buf[bufpos++];
}
int readstr(char *s) {
  int cur = 0;
  for (; isspace(buf[bufpos]); bufpos++)
    ;
  for (; !isspace(buf[bufpos]); bufpos++) s[cur++] = buf[bufpos];
  s[cur] = '\0';
  return cur;
}
char bf[1 << 25], st[20], *w = bf;
void flush() {
  fwrite(bf, 1, w - bf, stdout);
  w = bf;
}
inline void pc(register char c) { *w++ = c; }
void print(register int n) {
  register char *t = st;
  do {
    *t++ = n % 10 + 48;
  } while (n /= 10);
  while (t-- > st) pc(*t);
}
int a[50002], b[50002], id[50002], en[50002], dep[50002], nxt[50002], cl;
vector<int> s[50002];
void dfs(int u, int dp) {
  id[u] = ++cl;
  dep[cl] = dp;
  for (const auto &v : s[u]) dfs(v, dp + 1);
  en[u] = cl;
}
int main() {
  init();
  int n = readint(), q = readint();
  for (int i = 1; i <= n; i++) a[i] = readint();
  for (int i = 2; i <= n; i++) s[readint()].push_back(i);
  dfs(1, 0);
  for (int i = 1; i <= n; i++) b[id[i]] = a[i];
  for (int i = 1; i <= q; i++) {
    int u = readint();
    int l = id[u], r = en[u], cnt = 0, sum = 0;
    for (int j = l; j <= r; j++) {
      if (nxt[j] <= i) {
        sum += dep[j];
        cnt++;
        nxt[j] = i + b[j];
      }
    }
    print(sum - cnt * dep[l]);
    pc(' ');
    print(cnt);
    pc('\n');
  }
  flush();
}
