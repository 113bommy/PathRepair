#include <bits/stdc++.h>
using namespace std;
struct T {
  int l, r, h;
} a[100005];
int n;
long long tree[100005 * 2];
void insert(int o, int l, int r, int k, long long v) {
  if (l == r) {
    tree[o] = max(tree[o], v);
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    insert(o << 1, l, mid, k, v);
  else
    insert(o * 2 + 1, mid + 1, r, k, v);
  tree[o] = max(tree[o << 1], tree[o * 2 + 1]);
}
long long query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tree[o];
  int mid = (l + r) >> 1;
  long long ans = 0;
  if (L <= mid) ans = max(ans, query(o << 1, l, mid, L, R));
  if (R > mid) ans = max(ans, query(o * 2 + 1, mid + 1, r, L, R));
  return ans;
}
bool cmp(T t1, T t2) {
  if (t1.r == t2.r) return t1.l > t2.l;
  return t1.r > t2.r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> q;
  map<int, int> hash;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r >> a[i].h;
    q.push_back(a[i].l + 1);
    q.push_back(a[i].r);
  }
  sort(a + 1, a + n + 1, cmp);
  sort(q.begin(), q.end());
  int tot = 0;
  vector<int>::iterator it;
  for (it = q.begin(); it != q.end(); it++)
    if (!hash[*it]) hash[*it] = ++tot;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long delta = query(1, 1, tot, hash[a[i].l + 1], hash[a[i].r]) + a[i].h;
    insert(1, 1, tot, hash[a[i].l + 1], delta);
    ans = max(ans, delta);
  }
  cout << ans << endl;
  return 0;
}
