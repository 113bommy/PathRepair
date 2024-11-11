#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int mod = 998244353;
struct node {
  int l, r;
} tr[N * 4];
int ans[N], nxt[N];
int id[N], in[N * 10], d[N * 10];
int h[N * 10], ne[N * 10], e[N * 10], idx;
void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
  in[b]++;
}
void build(int u, int l, int r) {
  h[u] = -1, in[u] = d[u] = 0;
  if (l == r) {
    tr[u] = {l, r};
    id[l] = u, d[u] = l;
  } else {
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    add(u << 1, u), add(u << 1 | 1, u);
  }
}
void modify(int u, int l, int r, int x) {
  if (tr[u].l >= l && tr[u].r <= r) {
    add(u, x);
    return;
  }
  int mid = tr[u].l + tr[u].r >> 1;
  if (l <= mid) {
    modify(u << 1, l, r, x);
  }
  if (r > mid) modify(u << 1 | 1, l, r, x);
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i;
    idx = 0;
    for (i = 1; i <= n; i++) {
      cin >> nxt[i];
    }
    build(1, 1, n);
    for (i = 1; i <= n; i++) {
      if (nxt[i] != -1) {
        modify(1, i + 1, nxt[i] - 1, id[i]);
        if (nxt[i] != n + 1) {
          modify(1, i, i, id[nxt[i]]);
        }
      }
    }
    queue<int> q;
    for (i = 1; i <= n; i++) {
      if (!in[id[i]]) {
        q.push(id[i]);
      }
    }
    int res = 0;
    while (q.size()) {
      int t = q.front();
      q.pop();
      if (d[t]) ans[d[t]] = ++res;
      for (int i = h[t]; i != -1; i = ne[i]) {
        int j = e[i];
        in[j]--;
        if (!in[j]) q.push(j);
      }
    }
    if (res != n) {
      cout << -1 << endl;
    } else {
      for (i = 1; i <= n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
