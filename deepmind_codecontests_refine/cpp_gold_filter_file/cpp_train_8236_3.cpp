#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, a;
  cin >> n >> a;
  vector<long long> d((size_t)n + 2, 0), c((size_t)n + 2, 0),
      e((size_t)n + 2, (long long)2e9);
  for (long long i = 1; i <= n; i++) {
    cin >> d[i] >> c[i];
    c[i] = a - c[i];
  }
  for (long long i = 1; i <= n - 1; i++) {
    e[i] = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
  }
  vector<long long> left((size_t)n + 2, 0);
  {
    vector<long long> stack;
    for (long long i = n + 1; i >= 0; i--) {
      while (!stack.empty() && e[stack.back()] < e[i]) {
        left[stack.back()] = i;
        stack.pop_back();
      }
      stack.push_back(i);
    }
  }
  vector<long long> right((size_t)n + 2, n + 1);
  {
    vector<long long> stack;
    for (long long i = 0; i < n + 2; i++) {
      while (!stack.empty() && e[stack.back()] < e[i]) {
        right[stack.back()] = i;
        stack.pop_back();
      }
      stack.push_back(i);
    }
  }
  long long tree_size = 1 << 20;
  struct tree_node {
    long long left, right, inner, full;
  };
  vector<tree_node> tree((size_t)tree_size * 2 + 1, {0, 0, 0, 0});
  auto tree_combine = [&](tree_node x, tree_node y) {
    tree_node z{};
    z.left = max(x.left, x.full + y.left);
    z.right = max(y.right, x.right + y.full);
    z.inner = max({x.inner, y.inner, x.right + y.left});
    z.full = x.full + y.full;
    return z;
  };
  function<void(long long, long long, long long)> tree_build =
      [&](long long tree_i, long long tree_l, long long tree_r) {
        if (tree_l == tree_r) {
          if (tree_l <= n) {
            tree[tree_i].left = c[tree_l];
            tree[tree_i].right = c[tree_l];
            tree[tree_i].inner = c[tree_l];
            tree[tree_i].full = c[tree_l];
          }
        } else {
          tree_build(tree_i * 2 + 0, tree_l, tree_l + (tree_r - tree_l) / 2);
          tree_build(tree_i * 2 + 1, tree_r - (tree_r - tree_l) / 2, tree_r);
          tree[tree_i] =
              tree_combine(tree[tree_i * 2 + 0], tree[tree_i * 2 + 1]);
        }
      };
  function<tree_node(long long, long long, long long, long long, long long)>
      tree_query = [&](long long tree_i, long long tree_l, long long tree_r,
                       long long l, long long r) {
        if (tree_l >= l && tree_r <= r) {
          return tree[tree_i];
        } else if (tree_l <= r && tree_r >= l) {
          return tree_combine(
              tree_query(tree_i * 2 + 0, tree_l, tree_l + (tree_r - tree_l) / 2,
                         l, r),
              tree_query(tree_i * 2 + 1, tree_r - (tree_r - tree_l) / 2, tree_r,
                         l, r));
        }
        return tree_node{(long long)-1e16, (long long)-1e16, (long long)-1e16,
                         (long long)-1e16};
      };
  tree_build(1, 0, tree_size - 1);
  long long o = 0;
  o = max(o, *max_element(c.begin(), c.end()));
  for (long long i = 1; i <= n - 1; i++) {
    o = max(
        o, tree_query(1, 0, tree_size - 1, left[i] + 1, right[i]).inner - e[i]);
  }
  cout << o << endl;
  return 0;
}
