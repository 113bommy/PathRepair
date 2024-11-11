#include <bits/stdc++.h>
using namespace std;
struct SuffixTree {
  const int INF = 1e9;
  vector<map<int, int> > to;
  vector<int> fpos;
  vector<int> link;
  vector<int> len;
  string s;
  int node;
  int pos;
  int sz;
  int n;
  SuffixTree(string s) : s(s), node(0), pos(0), sz(1), n(0) {
    int maxn = s.size() * 2 + 10;
    to.resize(maxn);
    len.resize(maxn);
    len[0] = INF;
    fpos.resize(maxn);
    link.resize(maxn);
    for (auto c : s) {
      addLetter(c);
    }
    for (int i = 1; i < sz; ++i) {
      len[i] = min(len[i], n - fpos[i]);
    }
  }
  int makeNode(int _pos, int _len) {
    fpos[sz] = _pos;
    len[sz] = _len;
    return sz++;
  }
  void goEdge() {
    while (pos > len[to[node][s[n - pos]]]) {
      node = to[node][s[n - pos]];
      pos -= len[node];
    }
  }
  void addLetter(int c) {
    n++;
    pos++;
    int last = 0;
    while (pos > 0) {
      goEdge();
      int edge = s[n - pos];
      int &v = to[node][edge];
      int t = s[fpos[v] + pos - 1];
      if (v == 0) {
        v = makeNode(n - pos, INF);
        link[last] = node;
        last = 0;
      } else if (t == c) {
        link[last] = node;
        return;
      } else {
        int u = makeNode(fpos[v], pos - 1);
        to[u][c] = makeNode(n - 1, INF);
        to[u][t] = v;
        fpos[v] += pos - 1;
        len[v] -= pos - 1;
        v = u;
        link[last] = u;
        last = u;
      }
      if (node == 0) {
        pos--;
      } else {
        node = link[node];
      }
    }
  }
  void printTree() {
    for (int i = 0; i < sz; ++i) {
      for (auto it : to[i]) {
        int v = it.second;
        cout << i << " " << v << " " << s.substr(fpos[v], len[v]) << endl;
      }
    }
  }
};
long long ans = 0;
int dfs(int u, SuffixTree *st) {
  bool isLeaf = true;
  int ret = 0;
  for (auto cv : st->to[u]) {
    ret += dfs(cv.second, st);
    isLeaf = false;
  }
  ret += isLeaf;
  if (u != 0) {
    int len = st->len[u] - isLeaf;
    int cnt = ret;
    ans += cnt * cnt * len;
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    ans = 0;
    SuffixTree suffixTree(s + '$');
    dfs(0, &suffixTree);
    cout << ans << endl;
  }
}
