#include <bits/stdc++.h>
using namespace std;
long long longOne = 1;
struct trieNode {
  int count;
  trieNode *left;
  trieNode *right;
  trieNode() : count(0), left(NULL), right(NULL) {}
};
void insertElement(trieNode *root, int level, long long n, int diff) {
  if (level < 0) return;
  if ((n & (longOne << level)) == 0) {
    if (root->left == NULL) root->left = new trieNode();
    root->left->count += diff;
    insertElement(root->left, level - 1, n, diff);
  } else {
    if (root->right == NULL) root->right = new trieNode();
    root->right->count += diff;
    insertElement(root->right, level - 1, n, diff);
  }
}
long long prefixEnter(trieNode *root, int level, long long n) {
  if (root == NULL) return 0;
  if (level < 0) return 0;
  if ((longOne << level) & n) {
    if (root->left != NULL) {
      if (root->left->count)
        return (longOne << level) + prefixEnter(root->left, level - 1, n);
      else
        return prefixEnter(root->right, level - 1, n);
    } else
      return prefixEnter(root->right, level - 1, n);
  } else {
    if (root->right != NULL) {
      if (root->right->count)
        return (longOne << level) + prefixEnter(root->right, level - 1, n);
      else
        return prefixEnter(root->left, level - 1, n);
    } else
      return prefixEnter(root->left, level - 1, n);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  trieNode *root = new trieNode();
  int n;
  cin >> n;
  long long arr[n];
  for (int i(0); i < n; i++) cin >> arr[i];
  long long suffix[n + 1];
  suffix[n] = 0;
  insertElement(root, 40, 0, 1);
  long long xorE = 0;
  for (int i(n - 1); i >= 0; i--) {
    xorE = xorE ^ arr[i];
    suffix[i] = xorE;
    insertElement(root, 40, xorE, 1);
  }
  xorE = 0;
  long long result = prefixEnter(root, 40, 0);
  for (int i(0); i <= n - 1; i++) {
    insertElement(root, 40, suffix[i], -1);
    xorE = xorE ^ arr[i];
    long long temp = prefixEnter(root, 40, xorE);
    result = max(result, temp);
  }
  cout << result << endl;
  return 0;
}
