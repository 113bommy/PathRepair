#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1e5 + 7;
const int CMAX = 22 * NMAX;
int n, k, q, root[NMAX + 3], x[CMAX + 3], l[CMAX + 3], r[CMAX + 3];
queue<int> Q[NMAX + 3];
int Time, last;
void update(int node, int &cur, int st, int en, int idx, int val) {
  cur = ++Time;
  l[cur] = l[node];
  r[cur] = r[node];
  x[cur] = x[node] + val;
  if (st == en) return;
  int mid = (st + en) / 2;
  if (idx <= mid)
    update(l[node], l[cur], st, mid, idx, val);
  else
    update(r[node], r[cur], mid + 1, en, idx, val);
}
int get(int node, int st, int en, int ll, int rr) {
  if (ll > en || rr < st) return 0;
  if (ll <= st && en <= rr) return x[node];
  int mid = (st + en) / 2;
  int t1 = get(l[node], st, mid, ll, rr);
  int t2 = get(r[node], mid + 1, en, ll, rr);
  return t1 + t2;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    update(root[i - 1], root[i], 1, n, i, 1);
    int u;
    scanf("%d", &u);
    Q[u].push(i);
    while (Q[u].size() > k) {
      update(root[i], root[i], 1, n, Q[u].front(), -1);
      Q[u].pop();
    }
  }
  scanf("%d", &q);
  while (q--) {
    int xi, yi;
    scanf("%d%d", &yi, &xi);
    xi = ((xi + last) % n) + 1;
    yi = ((yi + last) % n) + 1;
    if (yi > xi) swap(xi, yi);
    last = get(root[xi], 1, n, yi, xi);
    printf("%d\n", last);
  }
  return 0;
}
