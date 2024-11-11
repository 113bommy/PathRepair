#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int n, q;
long long a[maxn], tree[maxn];
void upd(int x, int val) {
  for (; x < maxn; x += (x & (-x))) tree[x] += val;
}
long long get(int x) {
  long long res = 0;
  for (; x; x -= (x & (-x))) res += tree[x];
  return res;
}
void solve() {
  if (a[1] == 0) {
    cout << 1 << endl;
    return;
  }
  int pos = 1;
  while (pos <= n) {
    int l = pos + 1, r = n, res = pos;
    long long sum = 2 * get(pos);
    if (get(pos + 1) == sum) {
      cout << pos + 1 << endl;
      return;
    }
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (get(mid) <= sum)
        l = mid + 1, res = mid;
      else
        r = mid - 1;
    }
    if (res == pos)
      pos = res + 1;
    else
      pos = res;
  }
  cout << -1 << endl;
}
int main() {
  memset(tree, 0, sizeof(tree));
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    upd(i, a[i]);
  }
  for (int i = 1; i <= q; i++) {
    int pos, val;
    cin >> pos >> val;
    upd(pos, val - a[pos]);
    a[pos] = val;
    solve();
  }
  return 0;
}
