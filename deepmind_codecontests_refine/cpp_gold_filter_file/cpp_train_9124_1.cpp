#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10, M = 1e9, eps = 1e-7, MOD = 1e9 + 7;
struct Trie {
  long long nxt[N][26], dep[N], tot;
  multiset<long long> st[N];
  void init() {
    memset(nxt, 0, sizeof(nxt));
    dep[tot = 1] = 0;
  }
  void add(string s) {
    long long now = 1;
    for (long long i = 0; i < s.size(); i++) {
      if (!nxt[now][s[i] - 'a'])
        dep[nxt[now][s[i] - 'a'] = ++tot] = dep[now] + 1;
      now = nxt[now][s[i] - 'a'];
    }
    st[now].insert(dep[now]);
  }
  void dfs(long long u = 1) {
    long long emp = (u > 1 && st[u].empty());
    for (long long i = 0; i < 26; i++) {
      long long v = nxt[u][i];
      if (!v) continue;
      dfs(v);
      if (st[u].size() < st[v].size()) st[u].swap(st[v]);
      for (long long i : st[v]) st[u].insert(i);
      st[v].clear();
    }
    if (emp) {
      st[u].erase(--st[u].end());
      st[u].insert(dep[u]);
    }
  }
} trie;
int main() {
  long long n;
  cin >> n;
  trie.init();
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    trie.add(s);
  }
  trie.dfs();
  long long res = 0;
  for (long long i : trie.st[1]) res += i;
  cout << res;
}
