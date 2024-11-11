#include <bits/stdc++.h>
using namespace std;
struct SegmentTree {
  int N;
  vector<int> tree;
  SegmentTree(const vector<int> &arr) {
    N = (1 << (((int)ceil(log2(arr.size())))));
    tree.resize(2 * N, 0);
    for (int i = 0; i < arr.size(); i++) add(i, arr[i]);
  }
  int query(int a, int b) {
    int s = 0;
    for (a += N, b += N; a <= b; a >>= 1, b >>= 1) {
      if (a % 2 == 1) s += tree[a++];
      if (b % 2 == 0) s += tree[b--];
    }
    return s;
  }
  void add(int i, int x) {
    i += N;
    tree[i] += x;
    for (i /= 2; i >= 1; i /= 2) {
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }
  inline void set(int i, int x) { add(i, x - query(i, i)); }
};
int n_killed(SegmentTree &tree, int a, int b, int n) {
  int ans = 0;
  if (a <= b) {
    ans = tree.query(a, b);
  } else {
    if (b + 1 <= a - 1) ans = tree.query(b + 1, a - 1);
    ans = tree.query(0, n - 1) - ans;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[v[i]].push_back(i);
  }
  long long ans = 0;
  int next = 0;
  SegmentTree tree(vector<int>(n, 0));
  for (auto it : mp) {
    vector<int> &indices = it.second;
    int mnd = n;
    int split_at = 0;
    for (int i = 0; i < indices.size(); ++i) {
      if (mnd > ((indices[i] - next + n) % n)) {
        mnd = ((indices[i] - next + n) % n);
        split_at = i;
      }
    }
    for (int i = 0; i < indices.size(); ++i) {
      int ind = indices[(i + split_at) % indices.size()];
      ans += ((ind - next + n) % n) + 1 - n_killed(tree, next, ind, n);
      tree.set(ind, 1);
      next = (ind + 1) % n;
    }
  }
  cout << ans << endl;
}
