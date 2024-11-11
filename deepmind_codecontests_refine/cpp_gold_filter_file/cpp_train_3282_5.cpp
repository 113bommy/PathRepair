#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
struct node {
  node *l, *r;
  long long int val;
  node() : l(NULL), r(NULL), val(0) {}
};
map<long long int, long long int> m1, m2;
void update(node *&cur, long long int s, long long int e, long long int idx,
            long long int val) {
  if (!cur) cur = new node();
  cur->val += val;
  if (s == e) return;
  long long int m = (s + e) >> 1;
  if (idx <= m)
    update(cur->l, s, m, idx, val);
  else
    update(cur->r, m + 1, e, idx, val);
}
long long int query(node *&cur, long long int s, long long int e,
                    long long int l, long long int r) {
  if (s > r || e < l || !cur)
    return 0;
  else if (l <= s && e <= r)
    return cur->val;
  long long int m = (s + e) >> 1;
  return query(cur->l, s, m, l, r) + query(cur->r, m + 1, e, l, r);
}
const long long int N = 1e5 + 5;
node *tr[N];
long long int a[N], t[N], x[N];
signed main() {
  ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i] >> t[i] >> x[i];
    m1[t[i]] = 0, m2[x[i]] = 0;
  }
  long long int c = 0;
  for (auto &it : m1) {
    it.second = ++c;
  }
  c = 0;
  for (auto &it : m2) {
    it.second = ++c;
  }
  for (long long int i = 1; i <= n; i++) {
    t[i] = m1[t[i]], x[i] = m2[x[i]];
    if (a[i] == 1) {
      update(tr[x[i]], 1, N, t[i], 1);
    } else if (a[i] == 2) {
      update(tr[x[i]], 1, N, t[i], -1);
    } else {
      cout << query(tr[x[i]], 1, N, 1, t[i]) << endl;
    }
  }
  return 0;
}
