#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
const int N = 100017;
int tree[12 * N];
int a[3 * N + 17];
int b[3 * N + 17];
deque<int> d[3 * N + 11];
void build(int l, int r, int v) {
  if (l == r)
    tree[v] = a[l];
  else {
    int mid = (l + r) / 2;
    build(l, mid, v * 2);
    build(mid + 1, r, v * 2 + 1);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }
}
void update(int l, int r, int v, int ind) {
  if (l > ind || r < ind) return;
  if (l == r && l == ind)
    tree[v] = 1e9;
  else {
    int mid = (l + r) / 2;
    update(l, mid, v * 2, ind);
    update(mid + 1, r, v * 2 + 1, ind);
    tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
  }
}
int get_min(int l, int r, int v, int x, int y) {
  if (l > y || r < x) return 1e9;
  if (l >= x && r <= y)
    return tree[v];
  else {
    int mid = (l + r) / 2;
    return min(get_min(l, mid, v * 2, x, y),
               get_min(mid + 1, r, v * 2 + 1, x, y));
  }
}
bool solve() {
  int n;
  cin >> n;
  int used[n + 17];
  for (int i = 1; i <= n; i++) d[i].clear();
  memset(used, 0ll, sizeof(int) * (n + 11));
  memset(tree, 0ll, sizeof(int) * (4 * n));
  bool ans = true;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  build(1, n, 1);
  for (int i = 1; i <= n; i++) d[a[i]].push_back(i);
  int ind = 1;
  for (int i = 1; i <= n; i++) {
    while (used[ind]) ind++;
    if (a[ind] == b[i]) {
      d[a[i]].pop_front();
      update(1, n, 1, i);
      used[i] = 1;
      ind++;
    } else {
      if (!d[b[i]].size()) return false;
      int pos = d[b[i]][0];
      int mn = get_min(1, n, 1, i, pos);
      if (mn < b[i]) return false;
      d[b[i]].pop_front();
      update(1, n, 1, pos);
      used[pos] = 1;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES" : "NO");
    cout << "\n";
  }
}
