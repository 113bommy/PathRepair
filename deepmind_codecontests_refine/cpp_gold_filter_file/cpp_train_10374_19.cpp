#include <bits/stdc++.h>
using namespace std;
int tree[500000];
int query(int node, int st, int en, int l, int r) {
  if (st > r || en < l || l > r) return -1;
  if ((l <= st && en <= r)) {
    return tree[node];
  }
  int mid = (st + en) / 2;
  int p1 = query(node * 2, st, mid, l, r);
  int p2 = query(node * 2 + 1, mid + 1, en, l, r);
  return max(p1, p2);
}
void update(int node, int st, int en, int i, int val) {
  if (st > i || en < i) return;
  if ((st == en && en == i)) {
    tree[node] = max(tree[node], val);
    return;
  }
  if (st == en) return;
  int mid = (st + en) / 2;
  update(node * 2, st, mid, i, val);
  update(node * 2 + 1, mid + 1, en, i, val);
  tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
vector<int> vc, ans;
int ara[200000];
int main() {
  int i, j, k, l, m, n, cnt = 0;
  map<int, int> name;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &ara[i]);
    if (name[ara[i]] == 0) {
      vc.push_back(ara[i]);
      name[ara[i]] = 1;
    }
  }
  sort(vc.begin(), vc.end());
  for (i = 0; i < vc.size(); i++) {
    name[vc[i]] = ++cnt;
  }
  memset(tree, -1, sizeof tree);
  for (i = n; i >= 1; i--) {
    int d = name[ara[i]];
    l = query(1, 1, cnt, 1, d - 1);
    if (l == -1) {
      ans.push_back(-1);
    } else {
      ans.push_back(l - i - 1);
    }
    update(1, 1, cnt, d, i);
  }
  for (i = ans.size() - 1; i >= 0; i--) printf("%d ", ans[i]);
}
