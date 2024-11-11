#include <bits/stdc++.h>
using namespace std;
string s[1123456];
string q;
int trie[1123456][26];
int suffixLink[1123456];
int suffixTerminalLink[1123456];
int node_cnt = 0;
multiset<int> nodeSuspecionValues[1123456];
int suspecionValue[1123456];
int par[1123456];
int node_ch[1123456];
bool isTerminal[1123456];
int node_id[1123456];
int n;
inline void addStringToTrie(int id) {
  int node = 0;
  for (long long int i = 0; i < s[id].length(); ++i) {
    int ch = s[id][i] - 'a';
    if (trie[node][ch] == 0) {
      node_cnt++;
      trie[node][ch] = node_cnt;
      par[node_cnt] = node;
      node_ch[node_cnt] = ch;
    }
    node = trie[node][ch];
  }
  nodeSuspecionValues[node].insert(suspecionValue[id]);
  isTerminal[node] = true;
  node_id[id] = node;
}
inline void buildSuffixLinks() {
  queue<int> bfs_queue;
  bfs_queue.push(0);
  while (!bfs_queue.empty()) {
    int node = bfs_queue.front();
    bfs_queue.pop();
    for (long long int ch = 0; ch < 26; ++ch) {
      if (trie[node][ch] > 0) bfs_queue.push(trie[node][ch]);
    }
    if (par[node] == 0) {
      continue;
    }
    int tmp_suffix_link = suffixLink[par[node]];
    while (tmp_suffix_link > 0) {
      if (trie[tmp_suffix_link][node_ch[node]] != 0) {
        break;
      }
      tmp_suffix_link = suffixLink[tmp_suffix_link];
    }
    suffixLink[node] = trie[tmp_suffix_link][node_ch[node]];
  }
}
inline void buildSuffixTerminalLinks() {
  queue<int> bfs_queue;
  bfs_queue.push(0);
  while (!bfs_queue.empty()) {
    int node = bfs_queue.front();
    bfs_queue.pop();
    for (long long int ch = 0; ch < 26; ++ch) {
      if (trie[node][ch] > 0) bfs_queue.push(trie[node][ch]);
    }
    suffixTerminalLink[node] =
        (isTerminal[node] ? node : suffixTerminalLink[suffixLink[node]]);
  }
}
inline void buildTrie() {
  for (long long int i = 1; i < n + 1; ++i) addStringToTrie(i);
}
inline void init() {
  buildTrie();
  buildSuffixLinks();
  buildSuffixTerminalLinks();
}
inline void update(int id, int x) {
  int node = node_id[id];
  nodeSuspecionValues[node].erase(
      nodeSuspecionValues[node].find(suspecionValue[id]));
  suspecionValue[id] = -x;
  nodeSuspecionValues[node].insert(-x);
}
inline int query() {
  int node = 0;
  int ans = -1;
  for (long long int i = 0; i < q.length(); ++i) {
    int ch = q[i] - 'a';
    while (node > 0 && trie[node][ch] == 0) {
      node = suffixLink[node];
    }
    node = trie[node][ch];
    if (node == 0) {
      continue;
    }
    int tmp_node = node;
    while (tmp_node > 0 && suffixTerminalLink[tmp_node] > 0) {
      tmp_node = suffixTerminalLink[tmp_node];
      ans = max(ans, -(*nodeSuspecionValues[node].begin()));
      tmp_node = suffixLink[tmp_node];
    }
  }
  return ans;
}
inline void solve() {
  int m;
  cin >> n >> m;
  for (long long int i = 1; i < n + 1; ++i) cin >> s[i];
  init();
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int i, x;
      cin >> i >> x;
      update(i, x);
    } else {
      cin >> q;
      cout << query() << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
