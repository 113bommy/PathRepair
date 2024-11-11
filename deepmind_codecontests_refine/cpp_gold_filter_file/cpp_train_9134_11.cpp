#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, q;
const int oo = 40;
const int ii = 32;
long long a[N], node[N << 2];
int visited[N];
set<int> King[oo];
void Build_Tree(int I, int l, int r) {
  if (l > r) return;
  if (l == r) {
    node[I] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  Build_Tree(I << 1, l, mid);
  Build_Tree(I << 1 | 1, mid + 1, r);
  node[I] = node[I << 1] + node[I << 1 | 1];
}
void update(int I, int l, int r, int p, int x) {
  if (l > r || p < l || r < p) return;
  if (l == r && l == p) {
    node[I] = x;
    return;
  }
  int mid = (l + r) >> 1;
  update(I << 1, l, mid, p, x);
  update(I << 1 | 1, mid + 1, r, p, x);
  node[I] = node[I << 1] + node[I << 1 | 1];
}
long long get(int I, int l, int r, int u, int v) {
  if (l > r || v < l || r < u) return 0;
  if (u <= l && r <= v) {
    return node[I];
  }
  int mid = (l + r) >> 1;
  return get(I << 1, l, mid, u, v) + get(I << 1 | 1, mid + 1, r, u, v);
}
signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i]) {
      int ind = log2(a[i]);
      King[ind].insert(i);
    } else {
      King[ii].insert(i);
    }
  }
  Build_Tree(1, 1, n);
  while (q--) {
    int p, x, ind;
    scanf("%d %d", &p, &x);
    if (a[p])
      ind = log2(a[p]);
    else
      ind = ii;
    King[ind].erase(p);
    a[p] = x;
    if (x)
      ind = log2(x);
    else
      ind = ii;
    King[ind].insert(p);
    update(1, 1, n, p, x);
    int index = -1;
    for (int i = 0; i <= ii; i++) {
      int cnt = 0;
      for (set<int>::iterator it = King[i].begin(); it != King[i].end(); it++) {
        cnt++;
        if (cnt > 3) break;
        long long res = get(1, 1, n, 1, *it - 1);
        if (res == a[*it]) {
          index = *it;
          break;
        }
      }
      if (index != -1) break;
    }
    cout << index << endl;
  }
}
