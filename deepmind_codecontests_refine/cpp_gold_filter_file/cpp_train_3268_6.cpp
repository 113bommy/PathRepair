#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
class binary_indexed_tree {
  int tree[1000005];
  int n;

 public:
  void init(int n) {
    this->n = n;
    memset(tree, 0, sizeof(tree));
  }
  void update(int pos, int delta) {
    while (pos <= n) {
      tree[pos] = ((long long int)tree[pos] + delta) % mod;
      pos += ((pos) & -(pos));
    }
  }
  int query(int pos) {
    int ans = 0;
    while (pos > 0) {
      ans = ((long long int)ans + tree[pos]) % mod;
      pos -= ((pos) & -(pos));
    }
    return ans;
  }
};
int a[100005];
binary_indexed_tree tree;
int pre[1000005];
int dp[100005];
int n;
int main(int argc, char* argv[]) {
  scanf("%d", &n);
  int maxa = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    maxa = max(maxa, a[i]);
  }
  tree.init(maxa);
  for (int i = 1; i <= n; ++i) {
    dp[i] =
        ((long long int)a[i] * (1 + tree.query(a[i])) % mod - pre[a[i]] + mod) %
        mod;
    pre[a[i]] = (pre[a[i]] + dp[i]) % mod;
    tree.update(a[i], dp[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = ((long long int)ans + dp[i]) % mod;
  printf("%d\n", ans);
  return 0;
}
