#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAX = 1000005;
struct MaxSegtree {
  int arr[4 * MAX];
  int tree[4 * MAX];
  void build(int node, int a, int b) {
    if (a == b) {
      tree[node] = arr[a];
      return;
    }
    build(2 * node, a, (a + b) / 2);
    build(2 * node + 1, (a + b) / 2 + 1, b);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
  }
  int query(int node, int a, int b, int i, int j) {
    if (a > j || b < i) {
      return -1000000001;
    }
    if (i <= a && b <= j) {
      return tree[node];
    }
    int x = query(2 * node, a, (a + b) / 2, i, j);
    int y = query(2 * node + 1, (a + b) / 2 + 1, b, i, j);
    return max(x, y);
  }
};
struct MinSegtree {
  int arr[4 * MAX];
  int tree[4 * MAX];
  void build(int node, int a, int b) {
    if (a == b) {
      tree[node] = arr[a];
      return;
    }
    build(2 * node, a, (a + b) / 2);
    build(2 * node + 1, (a + b) / 2 + 1, b);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }
  int query(int node, int a, int b, int i, int j) {
    if (a > j || b < i) {
      return 1000000001;
    }
    if (i <= a && b <= j) {
      return tree[node];
    }
    int x = query(2 * node, a, (a + b) / 2, i, j);
    int y = query(2 * node + 1, (a + b) / 2 + 1, b, i, j);
    return min(x, y);
  }
};
MinSegtree s1;
MaxSegtree s2;
int n, k;
int st1[MAX][20];
int st2[MAX][20];
int v[MAX];
int c[MAX];
int ans[MAX];
double factor[MAX];
int log(int x) {
  int ct = 0;
  int k = 1;
  while (k <= x) {
    k *= 2;
    ct++;
  }
  return ct - 1;
}
int pow2(int x) {
  int i = 1;
  for (int i = 0; i < x; i++) {
    i *= 2;
  }
  return i;
}
void process2() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      if (st2[i][j - 1] < st2[i + (1 << (j - 1))][j - 1]) {
        st2[i][j] = st2[i][j - 1];
      } else {
        st2[i][j] = st2[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}
int rmq2(int i, int j) {
  int k = log(j - i + 1);
  if (st2[i][k] <= st2[j - pow2(k) + 1][k]) {
    return st2[i][k];
  }
  return st2[j - pow2(k) + 1][k];
}
void process1() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      if (st1[i][j - 1] > st1[i + (1 << (j - 1))][j - 1]) {
        st1[i][j] = st1[i][j - 1];
      } else {
        st1[i][j] = st1[i + (1 << (j - 1))][j - 1];
      }
    }
  }
}
int rmq1(int i, int j) {
  int k = log(j - i + 1);
  if (st1[i][k] >= st1[j - pow2(k) + 1][k]) {
    return st1[i][k];
  }
  return st1[j - pow2(k) + 1][k];
}
int first(int l, int r) { return 100 * rmq1(l, r); }
int g(int l, int r) { return rmq2(l, r); }
int p(int l, int r) { return min(g(l, r), first(l, r)); }
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i + 1]);
    s2.arr[i + 1] = v[i + 1];
    st1[i + 1][0] = v[i + 1];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i + 1]);
    s1.arr[i + 1] = c[i + 1];
    st2[i + 1][0] = c[i + 1];
  }
  process1();
  process2();
  factor[1] = (k + 0.0) / n;
  for (int i = 2; i < n + 1; i++) {
    factor[i] = factor[i - 1] * (0.0 + n - k - (i - 2)) / (n - i + 1);
  }
  s1.build(1, 0, n);
  s2.build(1, 0, n);
  for (int l = 1; l < n + 1; l++) {
    int lo = l;
    int hi = n;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (first(l, mid) == g(l, mid)) {
        lo = mid;
        ans[l] = first(l, mid);
        break;
      }
      if (first(l, mid) < g(l, mid)) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    if (ans[l] == 0) {
      ans[l] = p(l, lo);
      if (l <= lo - 1) {
        ans[l] = max(ans[l], p(l, lo - 1));
      }
    }
  }
  sort(ans + 1, ans + n + 1);
  double fin = 0;
  for (int i = 1; i < n + 1; i++) {
    fin += ans[i] * factor[i];
  }
  printf("%.10f\n", fin);
}
