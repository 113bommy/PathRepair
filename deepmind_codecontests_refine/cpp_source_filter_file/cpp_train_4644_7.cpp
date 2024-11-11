#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  struct node* nexNode[2];
  int cnt;
} Node;
Node* root;
void trie_insert(int num) {
  int i = 25;
  string s = "";
  while (i > 0) {
    char digit = '0' + num % 2;
    s = digit + s;
    num /= 2;
    i--;
  }
  Node* current = root;
  while (i < s.size()) {
    int digit = s[i] - '0';
    if (current->nexNode[digit] == NULL) {
      Node* n_node = new Node;
      n_node->cnt = 0;
      n_node->nexNode[0] = n_node->nexNode[1] = NULL;
      current->nexNode[digit] = n_node;
      current = n_node;
    } else
      current = current->nexNode[digit];
    i++;
    current->cnt++;
  }
}
void trie_delete(int num) {
  int i = 25;
  string s = "";
  while (i > 0) {
    char digit = '0' + num % 2;
    s = digit + s;
    num /= 2;
    i--;
  }
  Node* current = root;
  while (i < s.size()) {
    int digit = s[i] - '0';
    if (current->nexNode[digit] == NULL)
      return;
    else
      current = current->nexNode[digit];
    i++;
    current->cnt--;
  }
}
int find_respectors(int num, int l) {
  int i = 25, ans = 0;
  string s = "";
  string sl = "";
  while (i > 0) {
    char digit = '0' + num % 2;
    char digit_l = '0' + l % 2;
    s = digit + s;
    sl = digit_l + sl;
    num /= 2;
    l /= 2;
    i--;
  }
  Node* current = root;
  while (i < s.size()) {
    if (sl[i] == '1') {
      int digit = s[i] - '0';
      if (current->nexNode[digit] != NULL) ans += current->nexNode[digit]->cnt;
      if (current->nexNode[1 - digit] != NULL &&
          current->nexNode[1 - digit]->cnt > 0)
        current = current->nexNode[1 - digit];
      else
        return ans;
    } else {
      int digit = s[i] - '0';
      if (current->nexNode[digit] != NULL && current->nexNode[digit]->cnt > 0)
        current = current->nexNode[digit];
      else
        return ans;
    }
    i++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  root = new Node;
  root->cnt = 0;
  root->nexNode[0] = root->nexNode[1] = NULL;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    int p;
    cin >> p;
    if (type == 1) {
      trie_insert(p);
      continue;
    }
    if (type == 2) {
      trie_delete(p);
      continue;
    }
    int l;
    cin >> l;
    cout << find_respectors(p, l) << "\n";
  }
  return 0;
}
