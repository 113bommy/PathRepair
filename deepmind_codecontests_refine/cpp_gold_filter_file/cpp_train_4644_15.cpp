#include <bits/stdc++.h>
using namespace std;
struct Trie {
  Trie* child[2];
  int sz;
  Trie() {
    for (int i = 0; i <= 1; i++) child[i] = NULL;
    sz = 0;
  }
};
Trie* root = new Trie();
int ques, x, y;
void add(int val) {
  Trie* cur = root;
  int bit;
  for (int i = 27; i >= 0; i--) {
    if (x & (1 << i))
      bit = 1;
    else
      bit = 0;
    if (cur->child[bit] == NULL) {
      cur->child[bit] = new Trie();
    }
    cur = cur->child[bit];
    cur->sz += val;
  }
}
int get() {
  int ret = 0;
  Trie* cur = root;
  int bit_x, bit_y;
  for (int i = 27; i >= 0; i--) {
    if (x & (1 << i))
      bit_x = 1;
    else
      bit_x = 0;
    if (y & (1 << i))
      bit_y = 1;
    else
      bit_y = 0;
    if (bit_y == 1) {
      if (cur->child[bit_x] != NULL && (cur->child[bit_x])->sz != 0)
        ret += (cur->child[bit_x])->sz;
      if (cur->child[!bit_x] == NULL || (cur->child[!bit_x])->sz == 0)
        return ret;
      else
        cur = cur->child[!bit_x];
      continue;
    }
    if (cur->child[bit_x] == NULL || (cur->child[bit_x])->sz == 0)
      return ret;
    else
      cur = cur->child[bit_x];
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> ques;
  while (ques--) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> x;
      add(1);
    } else if (type == 2) {
      cin >> x;
      add(-1);
    } else {
      cin >> x >> y;
      cout << get() << '\n';
    }
  }
  return 0;
}
