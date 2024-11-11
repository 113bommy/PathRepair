#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const int modd1 = 1e9 + 7, modd2 = 998244353, maxn = 1e5 + 6, K = 26;
const double pi = acos(-1);
struct vertex {
  int next[K], go[K];
  int leaf = -1, leaflink = -1;
  int p = -1, link = -1;
  char pch;
  vertex(int p = -1, char ch = '$') : p(p), pch(ch) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};
vector<vertex> trie(1);
void add_string(string const &s, int idx) {
  int v = 0;
  for (char ch : s) {
    int c = ch - 'a';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back(v, ch);
    }
    v = trie[v].next[c];
  }
  trie[v].leaf = idx;
}
int go(int v, char ch);
int get_link(int v) {
  if (trie[v].link == -1) {
    if (v == 0 || trie[v].p == 0) {
      trie[v].link = 0;
    } else {
      trie[v].link = go(get_link(trie[v].p), trie[v].pch);
    }
  }
  return trie[v].link;
}
int go(int v, char ch) {
  int c = ch - 'a';
  if (trie[v].go[c] == -1) {
    if (trie[v].next[c] != -1) {
      trie[v].go[c] = trie[v].next[c];
    } else {
      trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
  }
  return trie[v].go[c];
}
int get_leaf(int i) {
  if (trie[i].leaflink != -1) {
    return trie[i].leaflink;
  }
  int nxt = get_link(i);
  if (nxt > 0) {
    if (trie[nxt].leaf != -1) {
      trie[i].leaflink = nxt;
    } else {
      trie[i].leaflink = get_leaf(nxt);
    }
    return trie[i].leaflink;
  }
  return 0;
}
string s;
int k[maxn], n;
string m[maxn];
vector<int> results[maxn];
void solve() {
  cin >> s >> n;
  int i, j, l, r;
  for (i = 0; i < n; ++i) {
    cin >> k[i] >> m[i];
    add_string(m[i], i);
  }
  int v = 0;
  for (i = 0; i < s.length(); ++i) {
    v = go(v, s[i]);
    int curr = v;
    while (get_leaf(curr) > 0) {
      curr = get_leaf(curr);
      results[trie[curr].leaf].push_back(i);
    }
    if (trie[v].leaf != -1) {
      results[trie[v].leaf].push_back(i);
    }
  }
  for (i = 0; i < n; ++i) {
    int mn = LLONG_MAX;
    for (j = k[i]; j <= results[i].size(); ++j) {
      mn = min(mn, results[i][j - 1] - results[i][j - k[i]]);
    }
    if (mn == LLONG_MAX) {
      cout << -1 << '\n';
    } else {
      cout << mn + m[i].length() << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
