#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 * 2 + 5;
const int M = 1e9 + 9;
const int B = 11;
int invB;
int n;
int str[MAXN];
void read_input() {
  scanf("%d", &n);
  char c;
  for (int i = 0; i < n; i++) {
    scanf(" %c", &c);
    int temp = c - '0';
    str[i] = temp;
  }
}
struct Node {
  bool left, right;
  int hsh, len;
  bool operator==(Node other) const {
    return hsh == other.hsh && len == other.len;
  }
};
int add(int f, int s) {
  f += s;
  if (f >= M)
    f %= M;
  else if (f < 0)
    f += M;
  return f;
}
int mul(int f, int s) {
  long long temp = 1LL * f * s;
  if (temp >= M) {
    temp %= M;
  }
  return temp;
}
int pw[MAXN];
Node merge(Node left, Node right) {
  if (right.len == 0) {
    return left;
  }
  if (left.len == 0) {
    return right;
  }
  if (left.right && right.left) {
    left.len--;
    right.len--;
    left.hsh = mul(add(left.hsh, -1), invB);
    right.hsh = add(right.hsh, -pw[right.len]);
    if (left.len == 0) {
      left.left = 0;
    }
    if (right.len == 0) {
      right.right = 0;
    }
  }
  left.hsh = add(mul(left.hsh, pw[right.len]), right.hsh);
  return {left.left, right.right, left.hsh, left.len + right.len};
}
const int TSIZE = (1 << 20);
Node tree[TSIZE];
void build_tree(int node, int l, int r) {
  if (l == r) {
    if (str[l] == 0) {
      tree[node] = {0, 0, 0, 1};
    } else {
      tree[node] = {1, 1, 1, 1};
    }
  } else {
    int middle = (l + r) >> 1;
    build_tree(node << 1, l, middle);
    build_tree((node << 1) + 1, middle + 1, r);
    tree[node] = merge(tree[node << 1], tree[(node << 1) + 1]);
  }
}
Node query(int node, int l, int r, int i, int j) {
  if (r < i || l > j || l > r) return {0, 0, 0, 0};
  if (r <= j && l >= i) {
    return tree[node];
  }
  int middle = (l + r) >> 1;
  return merge(query(node << 1, l, middle, i, j),
               query((node << 1) + 1, middle + 1, r, i, j));
}
int fast_pow(int x, int y) {
  int ans = 1;
  x %= M;
  while (y) {
    if (y & 1) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    y >>= 1;
  }
  return ans;
}
void solve() {
  pw[0] = 1;
  for (int i = 1; i <= n; i++) {
    pw[i] = mul(pw[i - 1], B);
  }
  invB = fast_pow(B, M - 2);
  int q;
  scanf("%d", &q);
  build_tree(1, 0, n - 1);
  int l1, l2, r1, r2, len;
  while (q--) {
    scanf("%d %d %d", &l1, &l2, &len);
    l1--;
    l2--;
    int r1 = l1 + len - 1;
    int r2 = l2 + len - 1;
    if (query(1, 0, n - 1, l1, r1) == query(1, 0, n - 1, l2, r2)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
int main() {
  read_input();
  solve();
  return 0;
}
