#include <bits/stdc++.h>
using std::pair;
using std::vector;
struct indexed_tree {
  vector<pair<int, int>> tree;
  int k = 1;
  indexed_tree(int n) {
    while (k < n) k *= 2;
    tree.resize(k * 3, {0, 0});
  }
  void update(int i) {
    tree[k + i].first++;
    tree[k + i].second = -i;
    int idx = (k + i) / 2;
    while (idx) {
      tree[idx] = std::max(tree[idx * 2], tree[idx * 2 + 1]);
      idx /= 2;
    }
  }
  pair<int, int> getRange(int left, int right) {
    left += k;
    right += k;
    pair<int, int> ret = {0, 0};
    while (1) {
      if (left > right) {
        break;
      }
      if (left == right) {
        ret = std::max(ret, tree[left]);
        break;
      }
      if (left % 2 == 1) {
        ret = std::max(ret, tree[left]);
      }
      if (right % 2 == 0) {
        ret = std::max(ret, tree[right]);
      }
      left = (left + 1) / 2;
      right = (right - 1) / 2;
    }
    return ret;
  }
};
int arr[5001];
int cnt[5001];
int idx[5001];
int ans[5001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    if (idx[arr[i]] == 0) {
      idx[arr[i]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    indexed_tree tree(n + 1);
    for (int j = i; j <= n; j++) {
      tree.update(arr[j]);
      cnt[-tree.tree[1].second]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (idx[i] != 0) {
      ans[idx[i]] = cnt[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", cnt[i]);
  }
}
