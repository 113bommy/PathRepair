#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 3;
const long long linf = (long long)inf * inf + 2;
int N, K;
struct TrieNode {
  TrieNode *children[26];
  bool canWin, canLose;
  TrieNode() {
    canWin = canLose = false;
    for (int i = 0; i < 26; ++i) children[i] = nullptr;
  }
};
TrieNode *root;
struct Trie {
  Trie() { root = new TrieNode(); }
  void insert(string &key, int idx = 0, TrieNode *pCrawl = root) {
    if (idx == (int)key.length()) return;
    int charId = key[idx] - 'a';
    if (pCrawl->children[charId] == nullptr)
      pCrawl->children[charId] = new TrieNode();
    insert(key, idx + 1, pCrawl->children[charId]);
  }
  void precompute(TrieNode *pCrawl = root) {
    bool hasChildren = false;
    for (int i = 0; i < 26; ++i)
      if (pCrawl->children[i] != nullptr) {
        hasChildren = true;
        precompute(pCrawl->children[i]);
        if (!pCrawl->children[i]->canWin) pCrawl->canWin = true;
        if (!pCrawl->children[i]->canLose) pCrawl->canLose = true;
      }
    if (!hasChildren) pCrawl->canLose = true;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N >> K;
  Trie myTrie = Trie();
  string str;
  for (int i = 0; i < N; ++i) {
    cin >> str;
    myTrie.insert(str);
  }
  myTrie.precompute();
  bool canForceWin = root->canWin, canForceLose = root->canLose;
  if (canForceWin && canForceLose)
    cout << "First\n";
  else if (canForceWin)
    cout << (K % 2 ? "First\n" : "Second\n");
  else
    cout << "Second\n";
  return 0;
}
