#include <bits/stdc++.h>
using namespace std;
struct BstNode {
  int data;
  BstNode *left;
  BstNode *right;
};
BstNode *GetNewNode(int data) {
  BstNode *newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
BstNode *Insert(BstNode *root, int data) {
  if (root == NULL) {
    root = GetNewNode(data);
  } else if (data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  return root;
}
bool Search(BstNode *root, int data) {
  if (root == NULL) {
    return false;
  } else if (root->data == data) {
    return true;
  } else if (data <= root->data) {
    return Search(root->left, data);
  } else {
    return Search(root->right, data);
  }
}
int find_min(BstNode *root) {
  BstNode *current = root;
  if (current->left == NULL) {
    return current->data;
  }
  find_min(current->left);
}
int cnt = 1;
int max_e(BstNode *root) {
  BstNode *cure = root;
  if (root == NULL) {
    return cure->data;
  }
  max_e(root->right);
}
void travel_orde(BstNode *root) {
  if (root == NULL) {
    return;
  }
  queue<BstNode *> Q;
  Q.push(root);
  while (!Q.empty()) {
    BstNode *current = Q.front();
    Q.pop();
    cout << current->data << " ";
    if (current->left != NULL) Q.push(current->left);
    if (current->right != NULL) Q.push(current->right);
  }
}
void prorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << " ";
  prorder(root->left);
  prorder(root->right);
}
void inorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}
void postorder(BstNode *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
int find_hieg(BstNode *root) {
  if (root == NULL) {
    return -1;
  }
  int le = find_hieg(root->left);
  int ri = find_hieg(root->right);
  cout << "val " << root->data << " "
       << " " << endl;
  cout << le << " " << ri << endl;
  return max(le, ri) + 1;
}
long long generate_divisors(long long n) {
  vector<int> v;
  long long i;
  for (i = 1; i * i < n; i++) {
    if (v.size() > 3) {
      return 4;
    }
    if (n % i == 0) {
      v.push_back(i), v.push_back(n / i);
    }
  }
  if (i * i == n) v.push_back(i);
  return v.size();
}
deque<int> t;
void terrnary(int number) {
  if (number == 0) {
    return;
  }
  terrnary(number / 3);
  t.push_back(number % 3);
}
int main() {
  deque<int> temp;
  long long a, b;
  cin >> a;
  cin >> b;
  if (a == b) {
    cout << a;
    return 0;
  }
  terrnary(a);
  for (int i = 0; i < t.size(); i++) {
    temp.push_back(t[i]);
  }
  t.clear();
  terrnary(b);
  if (temp.size() > t.size()) {
    int diff = temp.size() - t.size();
    while (diff) {
      t.push_front(0);
      diff--;
    }
  } else if (temp.size() < t.size()) {
    int diff = t.size() - temp.size();
    while (diff) {
      temp.push_front(0);
      diff--;
    }
  }
  vector<int> num;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 1) {
      if (temp[i] != 2)
        num.push_back(!temp[i]);
      else
        num.push_back(2);
    } else if (t[i] == 0) {
      if (temp[i] != 0)
        num.push_back(3 - temp[i]);
      else
        num.push_back(0);
    } else if (t[i] == 2) {
      num.push_back(2 - temp[i]);
    }
  }
  int len = num.size();
  long long number = 0;
  for (int i = 0; i < num.size(); i++) {
    len--;
    number += num[i] * pow(3, len);
    if (i + 1 == num.size()) cout << number;
  }
  return 0;
}
