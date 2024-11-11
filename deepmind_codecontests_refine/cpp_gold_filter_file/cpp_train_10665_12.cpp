#include <bits/stdc++.h>
using namespace std;
struct trie {
  trie *child[26];
  trie() {
    for (long long i = 0; i < 26; i++) child[i] = NULL;
  }
};
void insert(trie *root, string s) {
  for (long long i = 0; i < s.size(); i++) {
    if (root->child[s[i] - 'a'] == NULL) root->child[s[i] - 'a'] = new trie();
    root = root->child[s[i] - 'a'];
  }
}
bool dfs1(trie *root) {
  bool isleaf = true;
  bool win = false;
  for (long long i = 0; i < 26; i++) {
    if (root->child[i] != NULL) {
      isleaf = false;
      win |= !dfs1(root->child[i]);
    }
  }
  if (isleaf) return false;
  return win;
}
bool dfs2(trie *root) {
  bool isleaf = true;
  bool lose = false;
  for (long long i = 0; i < 26; i++) {
    if (root->child[i] != NULL) {
      isleaf = false;
      lose |= !dfs2(root->child[i]);
    }
  }
  if (isleaf) return true;
  return lose;
}
int main() {
  int n, k;
  cin >> n >> k;
  trie *root = new trie();
  for (long long i = 0; i < n; i++) {
    string s;
    cin >> s;
    insert(root, s);
  }
  bool win = dfs1(root);
  bool lose = dfs2(root);
  if (win && lose) {
    cout << "First";
  } else if (win) {
    if (k % 2)
      cout << "First";
    else
      cout << "Second";
  } else {
    cout << "Second";
  }
}
