#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 50;
struct SegNode {
  long long sum, delta, color;
  SegNode *left, *right;
};
SegNode nodePool[maxn << 2];
SegNode *cur = nodePool;
SegNode *root = nullptr;
void BuildTree(SegNode *&root, int nL, int nR) {
  root = cur++;
  root->left = root->right = nullptr;
  if (nL == nR) {
    root->color = nL;
    root->sum = root->delta = 0;
    return;
  }
  int Mid = (nL + nR) >> 1;
  BuildTree(root->left, nL, Mid);
  BuildTree(root->right, Mid + 1, nR);
}
long long Query(SegNode *root, const int &nL, const int &nR, const int &qL,
                const int &qR) {
  if (qL <= nL && nR <= qR) {
    return root->sum;
  }
  int Mid = (nL + nR) >> 1;
  if (qR <= Mid)
    return Query(root->left, nL, Mid, qL, qR) +
           1LL * root->delta * (qR - qL + 1);
  if (Mid < qL)
    return Query(root->right, Mid + 1, nR, qL, qR) +
           1LL * root->delta * (qR - qL + 1);
  return Query(root->left, nL, Mid, qL, Mid) +
         Query(root->right, Mid + 1, nR, Mid + 1, qR) +
         1LL * root->delta * (qR - qL + 1);
}
void Clear(SegNode *root, const int &nL, const int &nR, const int &newColor) {
  if (root->color > 0) {
    root->delta += abs(root->color - newColor);
    root->sum += 1LL * abs(root->color - newColor) * (nR - nL + 1);
  } else {
    int Mid = (nL + nR) >> 1;
    Clear(root->left, nL, Mid, newColor);
    Clear(root->right, Mid + 1, nR, newColor);
    root->sum +=
        root->left->sum + root->right->sum + 1LL * root->delta * (nR - nL + 1);
  }
  root->color = -1;
}
void Modify(SegNode *root, const int &nL, const int &nR, const int &qL,
            const int &qR, const int &newColor) {
  if (qL <= nL && nR <= qR) {
    Clear(root, nL, nR, newColor);
    root->color = newColor;
  } else {
    if (root->color > 0)
      root->left->color = root->right->color = root->color, root->color = -1;
    int Mid = (nL + nR) >> 1;
    if (qL <= Mid) Modify(root->left, nL, Mid, qL, qR, newColor);
    if (Mid < qR) Modify(root->right, Mid + 1, nR, qL, qR, newColor);
    root->sum =
        root->left->sum + root->right->sum + 1LL * root->delta * (nR - nL + 1);
  }
}
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  BuildTree(root, 1, n);
  while (m--) {
    int ope, L, R;
    scanf("%d%d%d", &ope, &L, &R);
    if (ope == 1) {
      int newColor;
      scanf("%d", &newColor);
      Modify(root, 1, n, L, R, newColor);
    } else {
      cout << Query(root, 1, n, L, R) << endl;
    }
  }
  return 0;
}
