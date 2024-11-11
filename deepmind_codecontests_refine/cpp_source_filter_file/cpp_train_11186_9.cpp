#include <bits/stdc++.h>
using namespace std;
typedef struct t_node {
  char val;
  bool e;
  struct t_node* child[26];
  bool win;
  bool lose;
} node;
class trie {
 public:
  int ct;
  node* root;
  void init() { root = getNode(); }
  node* getNode() {
    node* a = new node;
    a->e = 0;
    a->win = false;
    a->lose = false;
    for (int i = 0; i < 26; i++) a->child[i] = NULL;
    return a;
  }
  void insert(string s) {
    node* par = root;
    for (unsigned int i = 0; i < s.length(); i++) {
      if (!(par->child[s[i] - 'a'])) {
        par->child[s[i] - 'a'] = getNode();
        par = par->child[s[i] - 'a'];
        par->val = s[i];
      } else
        par = par->child[s[i] - 'a'];
      par->e = 0;
    }
    bool flag = false;
    for (int i = 0; i < 26; i++)
      if ((par->child[i] != NULL)) flag = true;
    if (flag) par->e = 1;
  }
  void solve(node* par) {
    if (par->e == 1) {
      par->win = false;
      par->lose = true;
      return;
    }
    for (int i = 0; i < 26; i++)
      if (par->child[i] != NULL) solve(par->child[i]);
    for (int i = 0; i < 26; i++)
      if (par->child[i] != NULL) {
        par->win = (par->win || !(par->child[i]->win));
        par->lose = (par->lose || !(par->child[i]->lose));
      }
    return;
  }
  void recurse() {
    node* par = root;
    solve(par);
  }
};
int main() {
  trie t;
  t.init();
  int n, k;
  cin >> n >> k;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    t.insert(s);
  }
  t.recurse();
  if (t.root->win == false)
    cout << "Second\n";
  else if (t.root->win == true && t.root->lose == true)
    cout << "First\n";
  else if ((k & 1) == 1)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}
