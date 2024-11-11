#include <bits/stdc++.h>
using namespace std;
struct trie {
  trie *childs[10];
  int currentHeight;
  int value;
  int dp[501][20];
  trie(int height) {
    this->currentHeight = height;
    this->value = 0;
    for (int i = 0; i < 10; ++i) this->childs[i] = nullptr;
    for (int i = 0; i <= 500; ++i) {
      for (int j = 0; j < 20; ++j) {
        this->dp[i][j] = 0;
      }
    }
  }
};
void insert(trie *node, string &s, int currentIndex, int val) {
  if (currentIndex == s.size()) {
    node->value += val;
    return;
  }
  int currentSon = s[currentIndex] - '0';
  if (node->childs[currentSon] == nullptr) {
    node->childs[currentSon] = new trie(node->currentHeight + 1);
  }
  insert(node->childs[currentSon], s, currentIndex + 1, val);
}
void buildDp(trie *node) {
  for (int i = 0; i < 10; ++i) {
    if (node->childs[i] == nullptr) continue;
    buildDp(node->childs[i]);
  }
  for (int height = 0; height <= node->currentHeight; ++height) {
    for (int currentK = 0; currentK <= 11; ++currentK) {
      vector<int> knapsack(static_cast<unsigned int>(currentK + 1), 0);
      int neigh = 0;
      for (int currentN = 0; currentN < 10; ++currentN) {
        if (node->childs[currentN] == nullptr) continue;
        neigh += 1;
        vector<int> auxiliar = knapsack;
        for (int i = 0; i <= currentK; ++i) {
          for (int currentPos = currentK; currentPos >= i; --currentPos) {
            auxiliar[currentPos] =
                max(auxiliar[currentPos],
                    knapsack[currentPos - i] +
                        node->childs[currentN]->dp[height][i]);
          }
        }
        knapsack = auxiliar;
      }
      node->dp[height][currentK] =
          max(node->dp[height][currentK],
              knapsack[currentK] + node->value * (max(height, 0)));
      if (currentK == 0) continue;
      vector<int> knapsack2(static_cast<unsigned int>(currentK), 0);
      for (int currentN = 0; currentN < 10; ++currentN) {
        if (node->childs[currentN] == nullptr) continue;
        vector<int> auxiliar = knapsack;
        for (int i = 0; i < currentK; ++i) {
          for (int currentPos = currentK - 1; currentPos >= i; --currentPos) {
            auxiliar[currentPos] =
                max(auxiliar[currentPos],
                    knapsack2[currentPos - i] +
                        node->childs[currentN]->dp[node->currentHeight][i]);
          }
        }
        knapsack2 = auxiliar;
      }
      node->dp[height][currentK] =
          max(node->dp[height][currentK],
              knapsack2[currentK - 1] +
                  node->value * (max(0, node->currentHeight)));
    }
  }
}
int main() {
  trie *root = new trie(0);
  int n, k, total = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    string s;
    cin >> s;
    int value;
    cin >> value;
    total += value * s.size();
    insert(root, s, 0, value);
  }
  buildDp(root);
  cout << max(0, total - root->dp[0][k]);
  return 0;
}
