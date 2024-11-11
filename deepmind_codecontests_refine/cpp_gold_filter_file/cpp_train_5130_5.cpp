#include <bits/stdc++.h>
using namespace std;
struct Node {
  int down;
  int left, right;
  Node() : down(0), left(-1), right(-1) {}
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n) {
    int a;
    vector<Node> tree(1);
    vector<long long> left(32), right(32);
    for (int i = 0; i < n; i++) {
      cin >> a;
      int cur = 0;
      for (int pos = 31; pos >= 0; pos--) {
        if (a & (1 << pos)) {
          if (tree[cur].right == -1) {
            tree[cur].right = tree.size();
            tree.emplace_back();
          }
          right[pos] += (tree[cur].left != -1 ? tree[tree[cur].left].down : 0);
          cur = tree[cur].right;
        } else {
          if (tree[cur].left == -1) {
            tree[cur].left = tree.size();
            tree.emplace_back();
          }
          left[pos] += (tree[cur].right != -1 ? tree[tree[cur].right].down : 0);
          cur = tree[cur].left;
        }
        tree[cur].down++;
      }
    }
    int ans = 0;
    long long inv = 0;
    for (int pos = 31; pos >= 0; pos--) {
      if (left[pos] > right[pos]) {
        ans |= (1 << pos);
      }
      inv += min(left[pos], right[pos]);
    }
    cout << inv << ' ' << ans << '\n';
  }
  return 0;
}
