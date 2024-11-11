#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  vector<int> v;
  int siz;
  segment_tree() : siz(0) {}
  segment_tree(int _siz) {
    siz = 1;
    while (siz < _siz) siz *= 2;
    v = vector<int>(siz * 2);
  }
  void add(int l, int r, int val) {
    for (l += siz, r += siz; l < r; l >>= 1, r >>= 1) {
      if (l & 1) v[l--] += val;
      if (r & 1) v[--r] += val;
    }
  }
  int query(int idx) {
    idx += siz;
    int ret = 0;
    while (idx) {
      ret += v[idx];
      idx >>= 1;
    }
    return ret;
  }
};
vector<int> ch[100001];
segment_tree num[100001];
int a[100001], t[100001], x[10001];
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> disc;
  int pos = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", a + i, t + i, x + i);
    if (!disc.count(x[i])) disc[x[i]] = pos++;
    ch[disc[x[i]]].push_back(t[i]);
  }
  for (int i = 0; i < pos; ++i) {
    sort(ch[i].begin(), ch[i].end());
    ch[i].erase(unique(ch[i].begin(), ch[i].end()), ch[i].end());
    num[i] = segment_tree(ch[i].size());
  }
  for (int i = 1; i <= n; ++i) {
    int p = disc[x[i]];
    int tidx = lower_bound(ch[p].begin(), ch[p].end(), t[i]) - ch[p].begin();
    if (a[i] == 1)
      num[p].add(tidx, ch[p].size(), 1);
    else if (a[i] == 2)
      num[p].add(tidx, ch[p].size(), -1);
    else
      printf("%d\n", num[p].query(tidx));
  }
  return 0;
}
