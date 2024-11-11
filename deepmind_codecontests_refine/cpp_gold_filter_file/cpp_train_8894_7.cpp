#include <bits/stdc++.h>
using namespace std;
struct treenode {
  long long a, b, c;
  treenode(long long a, long long b, long long c) : a(a), b(b), c(c) {}
};
bool compare(treenode v1, treenode v2) {
  return (v1.a == v2.a) ? ((v1.b == v2.b) ? (v1.c < v2.c) : (v1.b < v2.b))
                        : v1.a < v2.a;
}
int n, mm, s[111111], m[111111], r[111111], zero[111111], *add;
vector<treenode> tree1[4 * 111111], tree2[4 * 111111], *tree;
set<pair<int, int> > seg;
void mergetrees(vector<treenode>& v1, vector<treenode>& v2,
                vector<treenode>& res) {
  for (int i = 0, j = 0;;) {
    if (v1[i].a > v2[j].a)
      res.push_back(treenode(v1[i].a,
                             v1[i].b + v2[j].b + v2[j].c * (v1[i].a - v2[j].a),
                             v2[j].c + v1[i].c));
    else
      res.push_back(treenode(v2[j].a,
                             v2[j].b + v1[i].b + v1[i].c * (v2[j].a - v1[i].a),
                             v1[i].c + v2[j].c));
    if (v1[i].a == 2000000000) break;
    if (v1[i + 1].a > v2[j + 1].a)
      j++;
    else if (v1[i + 1].a < v2[j + 1].a)
      i++;
    else
      i++, j++;
  }
}
void build(int node, int vl, int vr) {
  if (vl == vr) {
    tree[node].push_back(treenode(0, add[vl], r[vl]));
    if (r[vl])
      tree[node].push_back(treenode((m[vl] - add[vl]) / r[vl] + 1, m[vl], 0));
    tree[node].push_back(treenode(2000000000, r[vl] ? m[vl] : add[vl], 0));
  } else {
    build(node * 2, vl, (vl + vr) / 2);
    build(node * 2 + 1, (vl + vr) / 2 + 1, vr);
    mergetrees(tree[node * 2], tree[node * 2 + 1], tree[node]);
  }
}
long long getsum(int t, int node, int vl, int vr, int l, int r) {
  if (l > vr || r < vl)
    return 0;
  else if (vl >= l && vr <= r) {
    int i = (int)(upper_bound(tree[node].begin(), tree[node].end(),
                              treenode(t, 2000000000, 0), compare) -
                  tree[node].begin()) -
            1;
    return tree[node][i].b + tree[node][i].c * (t - tree[node][i].a);
  } else {
    return getsum(t, node * 2, vl, (vl + vr) / 2, l, r) +
           getsum(t, node * 2 + 1, (vl + vr) / 2 + 1, vr, l, r);
  }
}
long long getdif(int tnow, int tprev, int l, int r) {
  if (tprev == -1)
    tree = tree2;
  else
    tree = tree1;
  return getsum((tprev == -1) ? tnow : tnow - tprev, 1, 0, n - 1, l - 1, r - 1);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d%d%d", &s[i], &m[i], &r[i]);
  cin >> mm;
  tree = tree1;
  add = zero;
  build(1, 0, n - 1);
  tree = tree2;
  add = s;
  build(1, 0, n - 1);
  seg.insert(make_pair(1, -1));
  seg.insert(make_pair(n + 1, -1));
  for (int i = 0; i < mm; i++) {
    int tt, ll, rr;
    scanf("%d%d%d", &tt, &ll, &rr);
    auto j = seg.upper_bound(make_pair(ll, 2000000000));
    j--;
    long long ans = 0;
    bool flag = true;
    for (; j->first <= rr;) {
      auto next = j;
      next++;
      ans += getdif(tt, j->second, max(j->first, ll), min(next->first - 1, rr));
      int l1 = j->first, t1 = j->second;
      seg.erase(j);
      if (l1 < ll) seg.insert(make_pair(l1, t1));
      if (flag) seg.insert(make_pair(ll, tt)), flag = false;
      if (next->first - 1 > rr) seg.insert(make_pair(rr + 1, t1));
      j = next;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
