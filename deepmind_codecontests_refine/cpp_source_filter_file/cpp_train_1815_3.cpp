#include <bits/stdc++.h>
using namespace std;
void add(int &a, int b) {
  a += b;
  if (a >= 1000000007) a -= 1000000007;
}
vector<int> L[300005];
int h[300005], cont, in[300005], out[300005];
void dfs(int cur, int curh) {
  h[cont] = curh;
  in[cur] = cont++;
  for (int i = 0; i < L[cur].size(); ++i) {
    int to = L[cur][i];
    dfs(to, curh + 1);
  }
  out[cur] = cont;
}
int T[300005], lazy0[4 * 300005], lazy1[4 * 300005];
void push(int node, int l, int r) {
  if (lazy0[node] > 0 || lazy1[node] > 0) {
    if (l != r) {
      add(lazy0[2 * node + 1], lazy0[node]);
      add(lazy0[2 * node + 2], lazy0[node]);
      add(lazy1[2 * node + 1], lazy1[node]);
      add(lazy1[2 * node + 2], lazy1[node]);
    } else {
      T[l] = (T[l] + lazy0[node] - (long long)h[l] * lazy1[node]) % 1000000007;
      if (T[l] < 0) T[l] += 1000000007;
    }
    lazy0[node] = 0;
    lazy1[node] = 0;
  }
}
int query(int node, int l, int r, int x) {
  push(node, l, r);
  if (l == r) return T[l];
  int mi = (l + r) >> 1;
  int ret;
  if (x <= mi)
    ret = query(2 * node + 1, l, mi, x);
  else
    ret = query(2 * node + 2, mi + 1, r, x);
  return ret;
}
void update(int node, int l, int r, int x, int y, int add0, int add1) {
  push(node, l, r);
  if (l < x || r > y) return;
  if (x <= l && r <= y) {
    add(lazy0[node], add0);
    add(lazy1[node], add1);
    push(node, l, r);
  } else {
    int mi = (l + r) >> 1;
    update(2 * node + 1, l, mi, x, y, add0, add1);
    update(2 * node + 2, mi + 1, r, x, y, add0, add1);
  }
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 2, p; i <= n; ++i) {
    scanf("%d", &p);
    L[p].push_back(i);
  }
  cont = 0;
  h[1] = 0;
  dfs(1, 0);
  scanf("%d", &m);
  int op, v, x, k;
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d %d", &v, &x, &k);
      int add = (x + (long long)h[in[v]] * k) % 1000000007;
      update(0, 0, n - 1, in[v], out[v] - 1, add, k);
    } else {
      scanf("%d", &v);
      printf("%d\n", query(0, 0, n - 1, in[v]));
    }
  }
  return 0;
}
