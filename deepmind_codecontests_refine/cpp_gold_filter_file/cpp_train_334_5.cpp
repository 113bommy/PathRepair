#include <bits/stdc++.h>
using namespace std;
int n, a[206000], b[206000], ans[206000], p[206000];
vector<pair<int, int> > v[206000];
struct node {
  int id, val;
} tree[1009000];
void build(int i, int l, int r) {
  if (l == r) {
    tree[i].id = l;
    tree[i].val = a[p[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  if (tree[i << 1].val < tree[i << 1 | 1].val)
    tree[i] = tree[i << 1];
  else
    tree[i] = tree[i << 1 | 1];
}
node q;
void query(int i, int l, int r, int x, int y) {
  if (r < x || l > y) return;
  if (r <= y && x <= l) {
    if (tree[i].val < q.val) q = tree[i];
    return;
  }
  int mid = (l + r) >> 1;
  query(i << 1, l, mid, x, y);
  query(i << 1 | 1, mid + 1, r, x, y);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    a[i] = l;
    b[i] = r;
    v[l].push_back(make_pair(r, i));
  }
  set<pair<int, int> > st;
  for (int i = 1; i <= n; ++i) {
    st.insert(v[i].begin(), v[i].end());
    int y = (*st.begin()).second;
    st.erase(st.begin());
    ans[y] = i;
    p[i] = y;
  }
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    if (i + 1 > b[p[i]]) continue;
    q.val = 99999999;
    query(1, 1, n, i + 1, b[p[i]]);
    if (q.val <= i) {
      cout << "NO" << endl;
      for (int j = 1; j <= n; ++j) printf("%d%c", ans[j], j == n ? '\n' : ' ');
      swap(ans[p[i]], ans[p[q.id]]);
      for (int j = 1; j <= n; ++j) printf("%d%c", ans[j], j == n ? '\n' : ' ');
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
