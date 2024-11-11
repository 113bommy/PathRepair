#include <bits/stdc++.h>
using namespace std;
template <class T>
class Node {
 public:
  Node(int low, int high) {
    this->low = low;
    this->high = high;
    this->key = (low + high) / 2;
  }
  Node* left = 0;
  Node* right = 0;
  int key;
  int low, high;
  T value = 0;
  T subvalue = 0;
};
template <class T>
class BST {
 public:
  BST(int low, int high) { root = new Node<T>(low, high); }
  ~BST() { dispose(root); }
  void dispose(Node<T>* node) {
    if (node->left) dispose(node->left);
    if (node->right) dispose(node->right);
    delete node;
  }
  void add(int key, T value) {
    Node<T>* node = root;
    while (node) {
      node->subvalue += value;
      if (key == node->key) {
        node->value += value;
        return;
      } else if (key < node->key) {
        if (!node->left) node->left = new Node<T>(node->low, node->key - 1);
        node = node->left;
      } else {
        if (!node->right) node->right = new Node<T>(node->key + 1, node->high);
        node = node->right;
      }
    }
  }
  T less(int key) {
    Node<T>* node = root;
    T value = 0;
    while (node) {
      if (node->key >= key) {
        node = node->left;
      } else {
        value += node->value;
        if (node->left) value += node->left->subvalue;
        node = node->right;
      }
    }
    return value;
  }
  void clearRange(int left, int right) {
    Node<T>* node = root;
    vector<Node<T>*> pathNodes;
    while (node) {
      pathNodes.push_back(node);
      if (node->key < left) {
        node = node->right;
      } else if (node->key > right) {
        node = node->left;
      } else {
        Node<T>* subnode = node->left;
        node->value = 0;
        while (subnode) {
          pathNodes.push_back(subnode);
          if (subnode->key < left) {
            subnode = subnode->right;
          } else {
            subnode->value = 0;
            if (subnode->right) {
              dispose(subnode->right);
              subnode->right = 0;
            }
            subnode = subnode->left;
          }
        }
        subnode = node->right;
        while (subnode) {
          pathNodes.push_back(subnode);
          if (subnode->key > right) {
            subnode = subnode->left;
          } else {
            subnode->value = 0;
            if (subnode->left) {
              dispose(subnode->left);
              subnode->left = 0;
            }
            subnode = subnode->right;
          }
        }
        node = 0;
      }
    }
    for (int i = pathNodes.size() - 1; i >= 0; i--) {
      Node<T>* node = pathNodes[i];
      node->subvalue = node->value;
      if (node->left) node->subvalue += node->left->subvalue;
      if (node->right) node->subvalue += node->right->subvalue;
    }
  }

 private:
  Node<T>* root;
};
struct ListNode {
  int c, index;
  ListNode* next = 0;
  ListNode* prev = 0;
  bool dead = false;
};
ListNode* head;
ListNode* tail;
void add(char c, int i) {
  ListNode* node = new ListNode();
  node->c = c - 'a';
  node->index = i;
  if (head) {
    tail->next = node;
    node->prev = tail;
    tail = node;
  } else
    head = tail = node;
}
vector<stack<ListNode*>> forw;
vector<stack<ListNode*>> backw;
int cnt[26];
vector<pair<int, int>> ans;
vector<ListNode*> deadNodes;
bool obsoleteForward(ListNode* node) {
  return node->dead || node == tail || node->c == node->next->c;
}
bool obsoleteBackward(ListNode* node) {
  return node->dead || node == head || node->c == node->prev->c;
}
void removeNode(ListNode* node) {
  node->dead = true;
  deadNodes.push_back(node);
  if (node->prev)
    node->prev->next = node->next;
  else
    head = node->next;
  if (node->next)
    node->next->prev = node->prev;
  else
    tail = node->prev;
}
void contract(ListNode* node, BST<int>& tree) {
  if (node == tail || node->c == node->next->c) {
    int lower = tree.less(node->index) + 1;
    ans.emplace_back(lower, lower);
    tree.add(node->index, -1);
    cnt[node->c]--;
    removeNode(node);
    return;
  }
  ListNode* a = node->prev;
  ListNode* b = node->next->next;
  cnt[node->c]--;
  cnt[node->next->c]--;
  int lower = tree.less(node->index + 1) + 1;
  int higher = tree.less(node->next->index) + 1;
  ans.emplace_back(lower, higher);
  tree.clearRange(node->index + 1, node->next->index);
  removeNode(node->next);
  removeNode(node);
  if (a && b && a->c != b->c) {
    forw[a->c].push(a);
    backw[b->c].push(b);
  }
}
char s[200005];
void solve() {
  scanf("%s", s);
  int n = strlen(s);
  if (n == 1) {
    cout << "1\n1 1\n";
    return;
  }
  BST<int> tree(0, n - 1);
  for (int i = 0; i < n; i++) tree.add(i, 1);
  head = tail = 0;
  memset(cnt, 0, sizeof(cnt));
  deadNodes.clear();
  for (int i = 0; i < n - 1; i++)
    if (s[i] == s[i + 1]) {
      add(s[i], i);
      cnt[s[i] - 'a']++;
    }
  forw.clear();
  backw.clear();
  forw.resize(26);
  backw.resize(26);
  for (ListNode* node = head; node != tail; node = node->next) {
    if (node->c != node->next->c) {
      forw[node->c].push(node);
      backw[node->next->c].push(node->next);
    }
  }
  ans.clear();
  while (head) {
    int c = 0;
    for (int i = 1; i < 26; i++)
      if (cnt[i] > cnt[c]) c = i;
    while (!forw[c].empty() && obsoleteForward(forw[c].top())) forw[c].pop();
    while (!backw[c].empty() && obsoleteBackward(backw[c].top()))
      backw[c].pop();
    if (!forw[c].empty())
      contract(forw[c].top(), tree);
    else if (!backw[c].empty())
      contract(backw[c].top()->prev, tree);
    else
      contract(head, tree);
  }
  ans.emplace_back(1, tree.less(1000000));
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  for (auto node : deadNodes) delete node;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
