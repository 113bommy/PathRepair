#include <bits/stdc++.h>
using namespace std;
const int K = 10;
inline int getID(char c) { return c - '0'; }
namespace Aho {
struct Vertex {
  int next[K], go[K];
  int leaf = -1;
  int p = -1, sz, match = -1;
  char pch;
  int suff_link = -1;
  int end_link = -1;
  Vertex(int p1 = -1, char ch1 = '$', int sz1 = 0) : p(p1), pch(ch1) {
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
    sz = sz1;
  }
};
vector<Vertex> trie;
void init() {
  trie.clear();
  trie.emplace_back();
}
int add_string(string const& s, int id = 1) {
  int v = 0;
  for (char ch : s) {
    int c = getID(ch);
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back(v, ch, trie[v].sz + 1);
    }
    v = trie[v].next[c];
  }
  trie[v].leaf = id;
  return v;
}
int go(int v, char ch);
int get_suff_link(int v) {
  if (trie[v].suff_link == -1) {
    if (v == 0 || trie[v].p == 0)
      trie[v].suff_link = 0;
    else
      trie[v].suff_link = go(get_suff_link(trie[v].p), trie[v].pch);
  }
  return trie[v].suff_link;
}
int get_end_link(int v) {
  if (trie[v].end_link == -1) {
    if (v == 0 || trie[v].p == 0) {
      trie[v].end_link = 0;
    } else {
      int suff_link = get_suff_link(v);
      if (trie[suff_link].leaf != -1)
        trie[v].end_link = suff_link;
      else
        trie[v].end_link = get_end_link(suff_link);
    }
  }
  return trie[v].end_link;
}
int go(int v, char ch) {
  int c = getID(ch);
  if (trie[v].go[c] == -1) {
    if (trie[v].next[c] != -1)
      trie[v].go[c] = trie[v].next[c];
    else
      trie[v].go[c] = (v == 0) ? 0 : go(get_suff_link(v), ch);
  }
  return trie[v].go[c];
}
};  // namespace Aho
vector<int> v;
int x;
void addString(string& s, int sum = 0) {
  if (sum > x) return;
  if (sum == x) {
    bool ok = true;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int aux = v[j] - ((i > 0) ? v[i - 1] : 0);
        if (aux != x and x % aux == 0) ok = false;
      }
    }
    if (ok) {
      Aho::add_string(s);
    }
  }
  for (int i = 1; i <= 9; i++) {
    s.push_back('0' + i);
    v.push_back(sum + i);
    addString(s, sum + i);
    s.pop_back();
    v.pop_back();
  }
}
string s;
int dp[1010][4860];
int n;
int solve(int i, int state) {
  if (i == n) return 0;
  if (dp[i][state] != -1) return dp[i][state];
  int newState = Aho::go(state, s[i]);
  if (Aho::trie[newState].leaf != -1)
    return dp[i][state] = solve(i + 1, state) + 1;
  else
    return dp[i][state] = min(solve(i + 1, state) + 1, solve(i + 1, newState));
}
int main() {
  memset(dp, -1, sizeof(dp));
  cin >> s;
  cin >> x;
  Aho::init();
  string aux;
  addString(aux, 0);
  n = s.size();
  cout << solve(0, 0) << endl;
  return 0;
}
