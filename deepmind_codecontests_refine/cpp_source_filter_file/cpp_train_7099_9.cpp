#include <bits/stdc++.h>
using std::greater;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::swap;
using std::unique;
using std::vector;
template <class T>
inline T read() {
  T x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch - 48);
    ch = getchar();
  }
  return f * x;
}
const int N = 2e5 + 100;
vector<int> G[N];
int T, n, s[N], top, dfn[N], low[N], siz[N], tot, idx[N], cnt;
bool ins[N];
inline void tarjan(int cur) {
  s[++top] = cur;
  dfn[cur] = low[cur] = ++cnt;
  ins[cur] = true;
  for (int k : G[cur]) {
    if (!dfn[k]) {
      tarjan(k);
      low[cur] = min(low[cur], low[k]);
    } else if (ins[k])
      low[cur] = min(low[cur], dfn[k]);
  }
  if (low[cur] == dfn[cur]) {
    ++tot;
    while (s[top + 1] != cur) {
      idx[s[top]] = tot;
      ++siz[tot];
      ins[s[top--]] = false;
    }
  }
  return;
}
signed main(int argc, char* argv[]) {
  T = read<int>();
  while (T--) {
    n = read<int>();
    cnt = 0;
    tot = 0;
    top = 0;
    for (int i = (1); i <= (n); ++i) {
      G[i].clear();
      s[i] = dfn[i] = low[i] = siz[i] = idx[i] = ins[i] = 0;
    }
    for (int i = (1); i <= (n); ++i) {
      int x = read<int>();
      G[i].push_back(x);
    }
    for (int i = (1); i <= (n); ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = (1); i <= (n - 1); ++i) printf("%lld ", siz[idx[i]]);
    printf("%lld\n", siz[idx[n]]);
  }
  return 0;
}
