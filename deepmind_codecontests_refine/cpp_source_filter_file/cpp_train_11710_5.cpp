#include <bits/stdc++.h>
using namespace std;
long long x[200010], bx[200010];
long long w[200010], bw[200010];
vector<pair<long long, int> > xpw;
long long tree[200010 << 2];
int ind[200010 << 2];
void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = x[l] - w[l];
    ind[i] = l;
    return;
  }
  build(2 * i, l, (l + r) / 2);
  build(2 * i + 1, (l + r) / 2 + 1, r);
  tree[i] = max(tree[2 * i], tree[2 * i + 1]);
  if (tree[2 * i] > tree[2 * i + 1])
    ind[i] = ind[2 * i];
  else
    ind[i] = ind[2 * i + 1];
}
pair<int, long long> query(int i, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return make_pair(ind[i], tree[i]);
  int mid = (l + r) / 2;
  if (qr <= mid)
    return query(2 * i, l, mid, ql, qr);
  else if (ql > mid)
    return query(2 * i + 1, mid + 1, r, ql, qr);
  pair<int, long long> p1 = query(2 * i, l, mid, ql, qr);
  pair<int, long long> p2 = query(2 * i + 1, mid + 1, r, ql, qr);
  if (p1.second > p2.second) return p1;
  return p2;
}
map<int, int> Hash;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ex, ww;
    scanf("%d%d", &ex, &ww);
    bx[i] = ex;
    bw[i] = ww;
    xpw.push_back(make_pair(ex + ww, i));
  }
  sort(xpw.begin(), xpw.end());
  for (int i = 0; i < xpw.size(); i++) {
    int indexx = xpw[i].second;
    x[i] = bx[indexx];
    w[i] = bw[indexx];
  }
  build(1, 0, n - 1);
  int le = 0, ri = n - 1;
  int csz = 0;
  int pre = -1;
  int x;
  while (le <= ri) {
    pair<int, long long> q = query(1, 0, n - 1, le, ri);
    if (Hash[q.first] == 0) {
      Hash[q.first] = 1;
      csz++;
    }
    x = lower_bound(xpw.begin(), xpw.end(), make_pair(q.second + 1, n)) -
        xpw.begin();
    ri = x - 1;
  }
  printf("%d\n", csz);
  return 0;
}
