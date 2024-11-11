#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100100];
int dl[100100], dr[100100];
int t[100100 * 4];
int get(int v, int l, int r, int L, int R) {
  if (r < L || R < l) return 0;
  if (L <= l && r <= R) return t[v];
  int mid = (l + r) >> 1;
  return max(get(v + v, l, mid, L, R), get(v + v + 1, mid + 1, r, L, R));
}
void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    t[v] = max(t[v], val);
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(v + v, l, mid, pos, val);
  else
    update(v + v + 1, mid + 1, r, pos, val);
  t[v] = max(t[v + v], t[v + v + 1]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    a[l]++;
    a[r + 1]--;
  }
  for (int i = 1; i <= m; ++i) {
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= m; ++i) {
    dl[i] = get(1, 0, n, 1, a[i]) + 1;
    update(1, 0, n, a[i], dl[i]);
  }
  memset(t, 0, sizeof t);
  int ans = 0;
  for (int i = m; i >= 1; --i) {
    dr[i] = get(1, 0, n, 1, a[i]) + 1;
    update(1, 0, n, a[i], dr[i]);
    ans = max(ans, dl[i] + dr[i] - 1);
  }
  cout << ans << endl;
  return 0;
}
