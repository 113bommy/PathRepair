#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int tree[4 * N], n;
void update(int v, int l, int r, int idx, int val) {
  if (l > r) return;
  if (idx > r || idx < l) return;
  if (l == r) {
    tree[v] = val;
    return;
  }
  int m = (l + r) / 2;
  if (idx <= m)
    update(2 * v + 1, l, m, idx, val);
  else
    update(2 * v + 2, m + 1, r, idx, val);
  tree[v] = min(tree[2 * v + 1], tree[2 * v + 2]);
}
int query(int v, int l, int r, int x, int y) {
  if (x > y) return n;
  if (r < x || l > y) return n;
  if (x <= l && r <= y) return tree[v];
  int m = (l + r) / 2;
  return min(query(2 * v + 1, l, m, x, y), query(2 * v + 1, m + 1, r, x, y));
}
bool solve() {
  cin >> n;
  int A[n], B[n];
  for (auto &v : A) cin >> v;
  for (auto &v : B) cin >> v;
  stack<int> s[n + 1];
  for (int i = 0; i <= n; i++) s[i].push(n);
  for (int i = n - 1; i >= 0; i--) s[A[i]].push(i);
  for (int i = 0; i <= 4 * n + 10; i++) tree[i] = n;
  for (int i = 1; i <= n; i++) {
    update(0, 1, n, i, s[i].top());
  }
  for (int i = 0; i < n; i++) {
    int &v = B[i];
    if (s[v].top() == n) return false;
    int q;
    if (v != 1) {
      q = query(0, 1, n, 1, v - 1);
      if (q < s[v].top()) return false;
    }
    s[v].pop();
    update(0, 1, n, v, s[v].top());
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    if (solve())
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
