#include <bits/stdc++.h>
const int N = 200005;
std::string s, t;
int lcp, next[N], occur[N];
void kmp(const std::string &s) {
  for (int i = 1, j = next[0] = -1; i <= s.size(); next[i++] = ++j)
    for (; j >= 0 && s[j] != s[i - 1];) j = next[j];
}
int size[N], idx = 1, lst = 1;
int nxt[N][26], fail[N], max[N];
void append(char ch) {
  int p = lst, np = ++idx;
  max[np] = max[p] + 1, size[np] = 1;
  for (; p && !nxt[p][ch]; p = fail[p]) nxt[p][ch] = np;
  if (!p)
    fail[np] = 1;
  else {
    int q = nxt[p][ch];
    if (max[p] + 1 == max[q])
      fail[np] = q;
    else {
      int nq = ++idx;
      max[nq] = max[p] + 1;
      std::memcpy(nxt[nq], nxt[q], 26 << 2);
      fail[q] = fail[q], fail[q] = fail[np] = nq;
      for (; nxt[p][ch] == q; p = fail[p]) nxt[p][ch] = nq;
    }
  }
}
namespace fail_tree {
int head[N], next[N];
void link(int x, int y) { next[y] = head[x], head[x] = y; }
int dfs(int x) {
  for (int i = head[x]; i; i = next[i]) size[x] += dfs(i);
  return size[x];
}
}  // namespace fail_tree
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> s >> t;
  int n = s.size(), m = t.size();
  for (lcp = 0; lcp < s.size() && lcp < t.size(); ++lcp)
    if (s[lcp] != t[lcp]) break;
  for (char ch : s) append(ch - 'a');
  for (int i = 2; i <= idx; ++i) fail_tree::link(fail[i], i);
  fail_tree::dfs(1), kmp(t);
  int now = 1;
  long long ans = (long long)n * m;
  for (int i = 0; i < t.size(); ++i)
    occur[i] = size[now = nxt[now][t[i] - 'a']];
  for (int i = 0; i < lcp; ++i) --occur[i];
  for (int i = 1; i <= t.size(); ++i)
    if (next[i]) ans -= occur[i - next[i] - 1];
  std::cout << ans << '\n';
  return 0;
}
