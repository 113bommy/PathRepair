#include <bits/stdc++.h>
using namespace std;
int n, k, q, siz[100005], now[100005], a[100005];
vector<int> vt[100005 * 3];
void add(vector<int> &v1, vector<int> &v2, vector<int> &v3) {
  int siz1 = v1.size(), siz2 = v2.size(), i = 0, j = 0;
  while (i < siz1 && j < siz2) {
    if (v1[i] < v2[j]) {
      v3.push_back(v1[i]);
      i++;
    } else {
      v3.push_back(v2[j]);
      j++;
    }
  }
  while (i < siz1) {
    v3.push_back(v1[i]);
    i++;
  }
  while (j < siz2) {
    v3.push_back(v2[j]);
    j++;
  }
}
void build(int node, int b, int e) {
  if (b == e) {
    if (a[b]) vt[node].push_back(a[b]);
    return;
  }
  int lef = node << 1, ri = (node << 1) + 1, mid = (b + e) >> 1;
  build(lef, b, mid);
  build(ri, mid + 1, e);
  add(vt[lef], vt[ri], vt[node]);
}
int binlo(int node, int num) {
  int lo = 0, hi = vt[node].size() - 1, mid, tmp = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (vt[node][mid] <= num)
      tmp = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  return tmp;
}
int binup(int node, int num) {
  int lo = 0, hi = vt[node].size() - 1, mid, tmp = -1;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (vt[node][mid] >= num)
      tmp = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  return tmp;
}
int query(int node, int b, int e, int i, int j) {
  int tmp = 0, tpp = 0;
  if (b > j || e < i)
    return 0;
  else if (b >= i && e <= j) {
    tmp = binup(node, i), tpp = binlo(node, j);
    if (tmp == -1 || tpp == -1) return 0;
    return (tpp - tmp + 1);
  }
  int lef = node << 1, ri = (node << 1) + 1, mid = (b + e) >> 1;
  tmp = query(lef, b, mid, i, j), tpp = query(ri, mid + 1, e, i, j);
  return (tmp + tpp);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  scanf("%d%d", &n, &k);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    vt[x].push_back(i);
    siz[x]++;
    if (siz[x] > k) {
      a[vt[x][now[x]]] = i;
      now[x]++;
    }
  }
  for (int i = 1; i <= n + 2; i++) vt[i].clear();
  build(1, 1, n);
  scanf("%d", &q);
  for (int x, y, last = 0; q; q--) {
    scanf("%d%d", &x, &y);
    x = ((x + last) % n) + 1;
    y = ((y + last) % n) + 1;
    if (x > y) swap(x, y);
    last = y - x + 1 - query(1, 1, n, x, y);
    printf("%d\n", last);
  }
  return 0;
}
