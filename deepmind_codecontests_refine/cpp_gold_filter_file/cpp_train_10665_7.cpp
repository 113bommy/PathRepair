#include <bits/stdc++.h>
using namespace std;
bool fwin = false;
struct TrieNode {
  char c;
  vector<TrieNode*> ch;
  TrieNode(char _c) : c(_c) { ch.clear(); }
  void newCh(char _c) { ch.push_back(new TrieNode(_c)); }
} * root;
bool game(TrieNode* now) {
  bool win = false;
  vector<TrieNode*>::iterator it;
  if (now->ch.size() == 0) return false;
  for (it = now->ch.begin(); it != now->ch.end(); ++it) {
    if (!game(*it)) {
      win = true;
      break;
    }
  }
  return win;
}
bool game2(TrieNode* now) {
  bool win = false;
  vector<TrieNode*>::iterator it;
  if (now->ch.size() == 0) return true;
  for (it = now->ch.begin(); it != now->ch.end(); ++it) {
    if (!game2(*it)) {
      win = true;
      break;
    }
  }
  return win;
}
void insert(char* s, int k, TrieNode* now) {
  vector<TrieNode*>::iterator it;
  if (k == strlen(s)) return;
  bool ok = false;
  for (it = now->ch.begin(); it != now->ch.end(); ++it) {
    if ((*it)->c == s[k]) {
      ok = true;
      insert(s, k + 1, (*it));
    }
  }
  if (!ok) {
    now->newCh(s[k]);
    insert(s, k + 1, now->ch[now->ch.size() - 1]);
  }
}
int main(int argc, const char* argv[]) {
  int n, k;
  bool fwin, flose;
  char s[100100];
  scanf("%d%d", &n, &k);
  root = new TrieNode(0);
  root->ch.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    insert(s, 0, root);
  }
  fwin = game(root);
  flose = game2(root);
  if ((fwin && k % 2) || (fwin && flose)) {
    printf("First\n");
  } else {
    printf("Second\n");
  }
  return 0;
}
