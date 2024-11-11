#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
int nxt() {
  int x;
  cin >> x;
  return x;
}
long long nxtLong() {
  long long x;
  cin >> x;
  return x;
}
string nxtStr() {
  string x;
  cin >> x;
  return x;
}
char nxtChar() {
  char x;
  cin >> x;
  return x;
}
double nxtDouble() {
  double x;
  cin >> x;
  return x;
}
long double nxtLDouble() {
  long double x;
  cin >> x;
  return x;
}
TreeNode* makeTree(int n) {
  queue<TreeNode*> tree_nodes;
  TreeNode* root;
  if (n) {
    root = new TreeNode(nxt());
    tree_nodes.push(root);
  } else {
    return NULL;
  }
  while (!tree_nodes.empty()) {
    TreeNode* node = tree_nodes.front();
    tree_nodes.pop();
    bool left;
    cin >> left;
    if (left) {
      node->left = new TreeNode(nxt());
      tree_nodes.push(node->left);
    }
    bool right;
    cin >> right;
    if (right) {
      node->right = new TreeNode(nxt());
      tree_nodes.push(node->right);
    }
  }
  return root;
}
ListNode* makeLinkedList(int n) {
  ListNode* list = new ListNode(0);
  ListNode* dummy = list;
  for (int i = 0; i < n; ++i) {
    list->next = new ListNode(nxt());
    list = list->next;
  }
  return dummy->next;
}
void solve() {
  int n = nxt();
  vector<int> m(n);
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
  }
  vector<int> t(n);
  int cur;
  for (int i = n - 1, cur = 0; i >= 0; --i) {
    cur = max(0, cur - 1);
    cur = max(cur, m[i] + 1);
    t[i] = cur;
  }
  long long ans = 0;
  for (int i = 0, cur = 0; i < n; ++i) {
    cur = max(cur, t[i]);
    ans += cur;
  }
  for (int i = 0; i < n; ++i) {
    ans -= (m[i] + 1);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(9);
  solve();
  return 0;
}
