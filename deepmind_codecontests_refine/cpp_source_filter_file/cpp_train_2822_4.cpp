#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int tot = 0;
vector<int> v, x;
int root[maxn + 11];
int ls[40 * maxn + 11], rs[40 * maxn + 11], tree[40 * maxn + 11];
struct node {
  int x, r, q;
} rob[maxn + 11];
void update(int &rt, int l, int r, int pos) {
  if (!rt) rt = ++tot;
  tree[rt]++;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (mid >= pos)
    update(ls[rt], l, mid, pos);
  else
    update(rs[rt], mid + 1, r, pos);
}
int query(int rt, int l, int r, int al, int ar) {
  if (!rt || l > ar || r < al) return 0;
  if (l >= al && r <= ar) return tree[rt];
  int mid = (l + r) >> 1;
  return query(ls[rt], l, mid, al, ar) + query(rs[rt], mid + 1, r, al, ar);
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> rob[i].x >> rob[i].r >> rob[i].q;
    v.emplace_back(rob[i].q);
    x.emplace_back(rob[i].x);
  }
  sort((v).begin(), (v).end());
  v.erase(unique((v).begin(), (v).end()), v.end());
  sort((x).begin(), (x).end());
  x.erase(unique((x).begin(), (x).end()), x.end());
  sort(rob + 1, rob + 1 + n, [&](node x, node y) { return x.r < y.r; });
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = lower_bound((x).begin(), (x).end(), rob[i].x - rob[i].r) -
            x.begin() + 1;
    int r =
        upper_bound((x).begin(), (x).end(), rob[i].x + rob[i].r) - x.begin();
    int pos = lower_bound((v).begin(), (v).end(), rob[i].q) - v.begin();
    if (l > r) {
      update(root[pos], 1, x.size(),
             lower_bound((x).begin(), (x).end(), rob[i].x) - x.begin() + 1);
      continue;
    }
    for (int j = rob[i].q - k; j <= rob[i].q + k; j++) {
      int ind = lower_bound((v).begin(), (v).end(), j) - v.begin();
      if (ind > v.size() || v[ind] != j) continue;
      ans += query(root[ind], 1, x.size(), l, r);
    }
    update(root[pos], 1, x.size(),
           lower_bound((x).begin(), (x).end(), rob[i].x) - x.begin() + 1);
  }
  printf("%lld\n", ans);
}
