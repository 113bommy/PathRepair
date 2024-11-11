#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  };
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  };
  return x * f;
}
long long n, m, len[1000001];
char ss[1000001];
namespace sam {
long long cnt, last, Vis[500001], fg[500001], las[500001], pa[500001],
    c[500001], len[500001];
long long g[500001][26];
inline void INIT() { cnt = last = 1; }
inline void insert(long long s, long long tr) {
  long long pos = last;
  last = ++cnt;
  long long newp = cnt;
  len[newp] = len[pos] + 1;
  for (; pos && !g[pos][s]; pos = pa[pos]) g[pos][s] = newp;
  if (!pos)
    pa[newp] = 1;
  else {
    long long posx = g[pos][s];
    if (len[posx] == len[pos] + 1)
      pa[newp] = posx;
    else {
      long long q = ++cnt;
      len[q] = len[pos] + 1;
      for (long long i = 0; i < 26; i++) g[q][i] = g[posx][i];
      pa[q] = pa[posx];
      pa[posx] = pa[newp] = q;
      for (; pos && g[pos][s] == posx; pos = pa[pos]) g[pos][s] = q;
    }
  }
}
inline void update(long long x, long long y) {
  for (; x && las[x] != y; x = pa[x]) fg[x]++, las[x] = y;
}
void dfs(long long u) {
  if (u == 1 || Vis[u]) return;
  Vis[u] = 1;
  dfs(pa[u]);
  c[u] += c[pa[u]];
}
inline void doit() {
  for (long long i = 1; i <= cnt; i++) {
    c[i] = len[i] - len[pa[i]];
    if (fg[i] < m) c[i] = 0;
  }
  for (long long i = 1; i <= cnt; i++) {
    dfs(i);
  }
}
}  // namespace sam
vector<char> S[100021];
inline char getch() {
  char ch = getchar();
  while (!isalpha(ch)) ch = getchar();
  return ch;
}
signed main() {
  n = read(), m = read();
  long long tot = 0, tt = 0;
  sam::INIT();
  for (long long i = 1; i <= n; i++) {
    scanf("%s", ss + 1);
    sam::last = 1;
    long long L = strlen(ss + 1);
    len[i] = L;
    for (long long j = 1; j <= L; j++) {
      S[i].push_back(ss[j]);
      sam::insert(ss[j] - 'a', i);
    }
  }
  long long pos = 1;
  for (long long i = 1; i <= n; i++) {
    pos = 1;
    for (long long j = 1; j <= len[i]; j++) {
      long long x = S[i][j - 1] - 'a';
      pos = sam::g[pos][x];
      sam::update(pos, i);
    }
  }
  sam::doit();
  for (long long i = 1; i <= n; i++) {
    pos = 1;
    long long ans = 0;
    for (long long j = 1; j <= len[i]; j++) {
      long long x = S[i][j - 1] - 'a';
      pos = sam::g[pos][x];
      ans += sam::c[pos];
    }
    printf("%d ", ans);
  }
  return 0;
}
