#include <bits/stdc++.h>
using namespace std;
struct V {
  int l, r;
  int v;
  int p;
  int nearl, nearr;
  int minv;
  int maxv;
  V() {
    l = r = -1;
    nearl = nearr = -1;
  }
};
vector<V> tree;
int root = 0;
pair<int, int> calc(int v) {
  if (tree[v].l == -1)
    return make_pair(tree[v].minv = tree[v].v, tree[v].maxv = tree[v].v);
  pair<int, int> a = calc(tree[v].l);
  pair<int, int> b = calc(tree[v].r);
  tree[v].nearl = a.second;
  tree[v].nearr = b.first;
  return make_pair(tree[v].minv = a.first, tree[v].maxv = b.second);
}
long long sum = 0;
int cnt = 0;
int now;
queue<long long> q;
void relax(int value) {
  while (tree[now].p >= 0) {
    int p = tree[now].p;
    if (tree[now].minv <= value && value <= tree[now].maxv) break;
    if (value > tree[now].maxv && tree[now].maxv == tree[root].maxv) break;
    if (value < tree[now].minv && tree[now].minv == tree[root].minv) break;
    sum -= q.front();
    q.pop();
    cnt--;
    now = p;
  }
  while (tree[now].l != -1) {
    if (tree[now].v > value) {
      sum += tree[now].nearr;
      cnt++;
      q.push(tree[now].nearr);
      now = tree[now].l;
    } else {
      sum += tree[now].nearl;
      cnt++;
      q.push(tree[now].nearl);
      now = tree[now].r;
    }
  }
}
int main() {
  int n;
  cin >> n;
  tree.resize(n);
  for (int i = 0; i < n; i++) cin >> tree[i].p >> tree[i].v;
  for (int i = 0; i < n; i++) {
    tree[i].p--;
    int p = tree[i].p;
    if (p >= 0) {
      if (tree[p].v > tree[i].v)
        tree[p].l = i;
      else
        tree[p].r = i;
    } else
      root = i;
  }
  calc(root);
  now = root;
  int k;
  cin >> k;
  vector<pair<int, int> > arr(k);
  vector<long double> res(k);
  for (int i = 0; i < k; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < k; i++) {
    relax(arr[i].first);
    res[arr[i].second] = (long double)sum / cnt;
  }
  for (int i = 0; i < k; i++) printf("%.10Lf\n", res[i]);
  return 0;
}
