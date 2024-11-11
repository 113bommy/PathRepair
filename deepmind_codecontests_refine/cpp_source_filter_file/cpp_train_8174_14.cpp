#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x;
  int y;
  int number;
};
struct vert {
  vert* leftChild;
  vert* rightChild;
  node vertNode;
};
vert* Merge(vert* left, vert* right) {
  if (left == 0) {
    return right;
  }
  if (right == 0) {
    return left;
  }
  if (left->vertNode.y >= right->vertNode.y) {
    left->rightChild = Merge(left->rightChild, right);
    return left;
  } else {
    right->leftChild = Merge(left, right->leftChild);
    return right;
  }
}
struct ResultTree {
  vert* leftTree;
  vert* rightTree;
};
ResultTree Split(vert* tree, double value) {
  ResultTree result;
  if (tree == 0) {
    result.leftTree = 0;
    result.rightTree = 0;
    return result;
  }
  if (tree->vertNode.x < value) {
    ResultTree curResult = Split(tree->rightChild, value);
    result.leftTree = tree;
    result.leftTree->rightChild = curResult.leftTree;
    result.rightTree = curResult.rightTree;
  } else {
    ResultTree curResult = Split(tree->leftChild, value);
    result.rightTree = tree;
    result.rightTree->leftChild = curResult.rightTree;
    result.leftTree = curResult.leftTree;
  }
  return result;
}
vert* NewTree(long long value, int number, int maxValue = 1000) {
  vert* newVert = new vert();
  newVert->leftChild = 0;
  newVert->rightChild = 0;
  newVert->vertNode.x = value;
  newVert->vertNode.number = number;
  newVert->vertNode.y = rand() % maxValue;
  return newVert;
}
vert* AddValue(vert* tree, long long value, int number,
               int maximalValue = 1000) {
  if (tree == 0) {
    return NewTree(value, number, maximalValue);
  }
  ResultTree splitResult = Split(tree, value);
  vert* newVert = NewTree(value, number, maximalValue);
  vert* left = Merge(splitResult.leftTree, newVert);
  return Merge(left, splitResult.rightTree);
}
bool Find(vert* tree, long long value) {
  if (tree == 0) {
    return false;
  }
  if (tree->vertNode.x == value) {
    return true;
  }
  if (tree->vertNode.x <= value) {
    return Find(tree->rightChild, value);
  } else {
    return Find(tree->leftChild, value);
  }
}
const int MAXN = 100001;
int a[MAXN];
int b[MAXN];
long long k;
void minesK(vert** root) {
  if ((*root) == 0) {
    return;
  }
  if ((*root)->vertNode.x < k) {
    (*root)->leftChild = 0;
    (*root) = (*root)->rightChild;
    minesK(root);
  } else {
    minesK(&((*root)->leftChild));
  }
}
void processTree(vert** root, int curStation) {
  if ((*root) == 0) {
    return;
  }
  k += b[curStation - 1];
  minesK(root);
}
vector<int> result;
void treeToResult(vert* root) {
  if (root == 0) {
    return;
  }
  result.push_back(root->vertNode.number);
  treeToResult(root->leftChild);
  treeToResult(root->rightChild);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vert* root = 0;
  for (int i = 0; i < 2 * n; i++) {
    int cur = 1 + i % n;
    if (cur == n) {
      processTree(&root, n + 1);
    } else {
      processTree(&root, cur);
    }
    if (root == 0) {
      k = 0;
    }
    k -= a[cur];
    if (i < n) {
      root = AddValue(root, a[cur] + k, cur, MAXN);
    }
  }
  treeToResult(root);
  root = 0;
  for (int i = 2 * n - 1; i > -1; i--) {
    int cur = 1 + i % n;
    processTree(&root, cur + 1);
    if (root == 0) {
      k = 0;
    }
    k -= a[cur];
    if (i >= n) {
      root = AddValue(root, a[cur] + k, cur, MAXN);
    }
  }
  treeToResult(root);
  sort(result.begin(), result.end());
  vector<int> finalResult;
  for (int i = 0; i < result.size(); i++) {
    if (i > 0 && result[i - 1] != result[i]) {
      finalResult.push_back(result[i]);
    }
    if (i == 0) {
      finalResult.push_back(result[i]);
    }
  }
  cout << finalResult.size() << endl;
  for (int i = 0; i < finalResult.size(); i++) {
    cout << finalResult[i] << " ";
  }
  return 0;
}
