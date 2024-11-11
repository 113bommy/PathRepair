#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
const long long mod = 1e9 + 7;
const double PI = acos(-1);
struct Trie {
  static const int kN = N;
  static const int chN = 26;
  int next[kN][chN], fail[kN], tot = 0, root[20], mark[kN], mark1[kN], cnt = 0,
                               si[20];
  void build(int x) {
    queue<int> que;
    que.push(x);
    int pos, u, v;
    while (!que.empty()) {
      pos = que.front();
      que.pop();
      for (int i = 0; i < chN; ++i) {
        if (!next[pos][i]) continue;
        u = fail[pos], v = next[pos][i];
        while (u && !next[u][i]) u = fail[u];
        fail[v] = u ? next[u][i] : x;
        que.push(v);
        mark1[v] = mark1[fail[v]] + mark[v];
      }
    }
  }
  void add(char s[], char ch) {
    root[++cnt] = ++tot, si[cnt] = 1;
    int pos = root[cnt];
    for (int i = 0; s[i]; ++i) {
      if (!next[pos][s[i] - ch]) next[pos][s[i] - ch] = ++tot;
      pos = next[pos][s[i] - ch];
    }
    mark[pos]++;
    while (si[cnt] == si[cnt - 1]) {
      unite(root[cnt - 1], root[cnt]);
      si[--cnt] <<= 1;
    }
    build(root[cnt]);
  }
  int query(char s[], char ch) {
    int pos, ret = 0;
    for (int id = 1; id <= cnt; ++id) {
      pos = root[id];
      for (int i = 0; s[i]; ++i) {
        while (pos && !next[pos][s[i] - ch]) pos = fail[pos];
        pos = pos ? next[pos][s[i] - ch] : root[id];
        ret += mark1[pos];
      }
    }
    return ret;
  }
  void unite(int u, int v) {
    mark[u] += mark[v];
    for (int i = 0; i < chN; ++i) {
      if (!next[u][i] || !next[v][i])
        next[u][i] += next[v][i];
      else
        unite(next[u][i], next[v][i]);
    }
  }
} ac[2];
char s[N];
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%s", &k, s);
    if (k <= 2)
      ac[k - 1].add(s, 'a');
    else {
      printf("%d\n", ac[0].query(s, 'a') - ac[1].query(s, 'a'));
      fflush(stdout);
    }
  }
  return 0;
}
