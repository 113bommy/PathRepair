#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  Node* Left;
  Node* Right;
  int lev;
};
Node* GetNode(int val, int l) {
  Node* newnode = new Node();
  newnode->val = val;
  newnode->lev = l;
  newnode->Left = NULL;
  newnode->Right = NULL;
  return newnode;
}
int main(void) {
  int n, m;
  map<int, int> nit;
  scanf("%d%d", &n, &m);
  if (n == m) {
    cout << 0 << endl;
    return 0;
  }
  Node* root = GetNode(n, 0);
  nit[n++];
  Node* tmp;
  queue<Node*> qu;
  qu.push(root);
  while (!qu.empty()) {
    tmp = qu.front();
    qu.pop();
    if (!nit.count(2 * tmp->val) && (tmp->val < n)) {
      tmp->Left = GetNode(2 * tmp->val, tmp->lev + 1);
      if ((2 * tmp->val) == m) {
        tmp = tmp->Left;
        break;
      }
      nit[2 * tmp->val]++;
      qu.push(tmp->Left);
    }
    if (!nit.count(tmp->val - 1) && (tmp->val - 1 > 0)) {
      tmp->Right = GetNode(tmp->val - 1, tmp->lev + 1);
      if ((tmp->val - 1) == m) {
        tmp = tmp->Right;
        break;
      }
      nit[tmp->val - 1]++;
      qu.push(tmp->Right);
    }
  }
  printf("%d\n", tmp->lev);
}
