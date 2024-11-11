#include <bits/stdc++.h>
using ll = long long;
const int INF = 1e9;
const int N = 1e5 + 5;
using namespace std;
int n, a[N];
int block_right[4 * N], block_left[4 * N];
void update(int *tree, int n, int l, int r, int a, int b, int v) {
  if (r < a || b < l) return;
  if (a <= l && r <= b) {
    tree[n] = min(tree[n], v);
    return;
  }
  int m = (l + r) / 2;
  update(tree, n * 2, l, m, a, b, v);
  update(tree, n * 2 + 1, m + 1, r, a, b, v);
}
int get(int *tree, int n, int l, int r, int p) {
  if (r < p || p < l) return INF;
  if (l == r) return tree[n];
  int m = (l + r) / 2;
  int x = get(tree, n * 2, l, m, p);
  int y = get(tree, n * 2 + 1, m + 1, r, p);
  int z = tree[n];
  return min(min(x, y), z);
}
bool blocked(int time) {
  for (int i = 0; i < (4 * n + 5); ++i) block_left[i] = block_right[i] = INF;
  for (int i = (1); i <= (n); ++i) {
    int threshold = min(i, time + 1) - a[i];
    if (threshold > 0) {
      update(block_right, 1, 1, n, i - threshold + 1, i + threshold - 1, i);
    }
  }
  for (int i = (1); i <= (n); ++i) {
    int l = max(0, i - a[i]), r = time - a[i];
    if (l <= r) {
      update(block_left, 1, 1, n, i + l, i + r, i);
      update(block_left, 1, 1, n, i - r, i - l, i);
    }
  }
  for (int i = (1); i <= (n); ++i) {
    int l = get(block_left, 1, 1, n, i);
    int r = get(block_right, 1, 1, n, i);
    if (l != INF && r != INF && l < r) {
      return true;
    }
  }
  return false;
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  int low = 1, high = INF;
  while (low < high) {
    int mid = (low + high) / 2;
    if (blocked(mid))
      high = mid;
    else
      low = mid + 1;
  }
  if (low == INF)
    cout << -1 << endl;
  else
    cout << low << endl;
  return 0;
}
