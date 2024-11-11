#include <bits/stdc++.h>
using namespace std;
const int SIGMA = 26;
struct Node {
  vector<int> next;
  vector<int> go;
  int p = -1;
  int ch = -1;
  int link = -1;
  int cnt = 0;
  Node() : next(vector<int>(SIGMA, -1)), go(vector<int>(SIGMA, -1)) {}
  Node(int p, int ch)
      : next(vector<int>(SIGMA, -1)),
        go(vector<int>(SIGMA, -1)),
        p(p),
        ch(ch) {}
};
struct AhoCorasick {
  vector<Node> trie;
  vector<bool> vis;
  void add(const string& s) {
    int u = 0;
    for (char ch : s) {
      int v = ch - 'a';
      if (trie[u].next[v] == -1) {
        trie[u].next[v] = int(trie.size());
        trie.push_back(Node(u, ch));
        vis.push_back(false);
      }
      u = trie[u].next[v];
    }
    trie[u].cnt++;
  }
  int getLink(int u) {
    if (trie[u].link == -1)
      return trie[u].link = (u == 0 or trie[u].p == 0)
                                ? 0
                                : go(getLink(trie[u].p), trie[u].ch);
    return trie[u].link;
  }
  int go(int u, char ch) {
    int v = ch - 'a';
    if (trie[u].go[v] == -1) {
      if (trie[u].next[v] != -1) return trie[u].go[v] = trie[u].next[v];
      return trie[u].go[v] = (u == 0) ? 0 : go(getLink(u), ch);
    }
    return trie[u].go[v];
  }
  int get(int u) {
    if (u == 0) return 0;
    if (vis[u]) return trie[u].cnt;
    vis[u] = true;
    trie[u].cnt += get(getLink(u));
    return trie[u].cnt;
  }
  AhoCorasick(const vector<string>& arr)
      : trie(vector<Node>(1)), vis(vector<bool>(1, false)) {
    for (const string& s : arr) add(s);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string t;
  cin >> t;
  int n;
  cin >> n;
  vector<string> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<int> a(int(t.size()), 0);
  {
    AhoCorasick ac(arr);
    int u = 0;
    for (int i = 0; i < int(t.size()); i++) {
      u = ac.go(u, t[i]);
      a[i] = ac.get(u);
    }
  }
  vector<int> b(int(t.size()), 0);
  {
    for (int i = 0; i < n; i++) reverse(begin(arr[i]), end(arr[i]));
    AhoCorasick ac(arr);
    int u = 0;
    for (int i = int(t.size()) - 1; i >= 0; i--) {
      u = ac.go(u, t[i]);
      b[i] = ac.get(u);
    }
  }
  long long ans = 0;
  for (int i = 0; i + 1 < int(t.size()); i++) ans += 1LL * a[i] * b[i + 1];
  cout << ans << '\n';
  return (0);
}
