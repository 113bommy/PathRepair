#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
int a[N];
map<int, int> mp;
map<int, int>::iterator it;
int seg[4 * N];
void update(int pos, int low, int high, int l, int r, int val) {
  if (l <= low && r >= high) {
    seg[pos] = val;
    return;
  }
  if (l > high || r < low) return;
  int mid = (low + high) / 2;
  update(pos * 2, low, mid, l, r, val);
  update(pos * 2 + 1, mid + 1, high, l, r, val);
  seg[pos] = seg[pos * 2] + seg[pos * 2 + 1];
}
int query(int pos, int low, int high, int l, int r) {
  if (l <= low && r >= high) return seg[pos];
  if (l > high || r < low) return 0;
  int mid = (low + high) / 2;
  return query(pos * 2, low, mid, l, r) +
         query(pos * 2 + 1, mid + 1, high, l, r);
}
int less_than[N];
int more_than[N];
long long ans;
int main() {
  int i;
  int ind = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mp[a[i]];
  }
  for (it = mp.begin(); it != mp.end(); ++it) {
    ind++;
    it->second = ind;
  }
  for (i = 1; i <= n; i++) a[i] = mp[a[i]];
  for (i = 1; i <= n; i++) {
    more_than[i] = query(1, 1, n, a[i] + 1, n);
    update(1, 1, n, a[i], a[i], 1);
  }
  memset(seg, 0, sizeof(seg));
  for (i = n; i >= 1; i--) {
    less_than[i] = query(1, 1, n, 1, a[i] - 1);
    update(1, 1, n, a[i], a[i], 1);
  }
  for (i = 1; i <= n; i++) ans += less_than[i] * 1LL * more_than[i];
  printf("%d\n", ans);
  return 0;
}
