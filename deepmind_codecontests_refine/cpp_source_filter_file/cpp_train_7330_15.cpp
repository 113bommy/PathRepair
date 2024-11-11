#include <bits/stdc++.h>
using namespace std;
int n, l[100010], v[100010], r[100010];
pair<int, pair<long long, long long> > event[200010];
struct segtree {
  int l, r;
  int val1, val2, pos;
  segtree *cl, *cr;
  segtree(int l, int r) : l(l), r(r) {
    val1 = val2 = 0;
    pos = l;
    if (l + 1 == r) {
      return;
    }
    cl = new segtree(l, l + r >> 1);
    cr = new segtree(l + r >> 1, r);
  }
  void add(int L, int R, int v) {
    if (L <= l && r <= R) {
      val1 += v;
      val2 += v;
      return;
    }
    if (R <= l || r <= L) {
      return;
    }
    cl->add(L, R, v);
    cr->add(L, R, v);
    val1 = val2 + max(cl->val1, cr->val1);
    if (cl->val1 > cr->val1) {
      pos = cl->pos;
    } else {
      pos = cr->pos;
    }
  }
} * root;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (n); i++)
    cin >> l[i] >> v[i] >> r[i], l[i]--, v[i]--, r[i]--;
  for (int i = 0; i < (n); i++) {
    event[i] = make_pair(l[i], make_pair(+1, i));
    event[n + i] = make_pair(v[i], make_pair(-1, i));
  }
  sort(event, event + 2 * n);
  root = new segtree(0, 300000);
  int ans = -1, pos1, pos2;
  for (int i = 0; i < (2 * n); i++) {
    int id = event[i].second.second;
    root->add(v[id], r[id] + 1, event[i].second.first);
    if (root->val1 > ans) {
      ans = root->val1;
      pos1 = l[id];
      pos2 = root->pos;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < (n); i++)
    if (l[i] <= pos1 && pos1 <= v[i] && v[i] <= pos2 && pos2 <= r[i])
      cout << i + 1 << " ";
}
