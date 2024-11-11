#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const long long mm = 1e9 + 7;
int ch[maxn][27], fail[maxn];
long long cnt[maxn];
long long s[maxn], len[maxn];
int slink[maxn];
int dif[maxn];
char sp[maxn];
long long g[maxn];
int last, sz, n;
int newnode(int x) {
  for (int i = 0; i < 26; ++i) {
    ch[sz][i] = 0;
  }
  cnt[sz] = 0;
  len[sz] = x;
  return sz++;
}
void init() {
  sz = 0;
  newnode(0);
  newnode(-1);
  last = 0, n = 0;
  fail[0] = 1;
  fail[1] = 0;
  s[0] = -1;
}
int getfail(int u) {
  while (s[n - len[u] - 1] != s[n]) u = fail[u];
  return u;
}
int pos[maxn];
void add(int c) {
  s[++n] = c;
  int u = getfail(last);
  if (!ch[u][c]) {
    int np = newnode(len[u] + 2);
    fail[np] = ch[getfail(fail[u])][c];
    ch[u][c] = np;
    dif[np] = len[np] - len[fail[np]];
    if (dif[np] == dif[fail[np]]) {
      slink[np] = slink[fail[np]];
    } else
      slink[np] = fail[np];
  }
  last = ch[u][c];
  pos[last] = n;
  cnt[last]++;
}
void count() {
  for (int i = sz - 1; i >= 0; --i) {
    cnt[fail[i]] += cnt[i];
  }
}
long long dp[maxn];
char dsp[maxn];
int main() {
  init();
  dsp[0] = 'a';
  scanf("%s", dsp + 1);
  int le = strlen(dsp + 1);
  int j = 0;
  for (int i = 1; i <= le; ++i) {
    sp[++j] = dsp[i];
    sp[++j] = dsp[le - i + 1];
  }
  dp[0] = 1;
  for (int i = 1; i <= le; ++i) {
    add(sp[i] - 'a');
    for (int j = last; j >= 2; j = slink[j]) {
      g[j] = dp[i - len[slink[j]] - dif[j]];
      if (dif[j] == dif[fail[j]]) g[j] = (g[j] % mm + g[fail[j]] % mm) % mm;
      if (i % 2 == 0) dp[i] = (dp[i] % mm + g[j] % mm) % mm;
    }
  }
  cout << dp[n] << endl;
  return 0;
}
