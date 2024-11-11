#include <bits/stdc++.h>
using namespace std;
long long a, b, c, s;
int N, Q;
int ac[100005][18], level[100005];
vector<int> v[100005], tv[100005];
int p[100005];
void dfs(int cur, int lev) {
  level[cur] = lev;
  for (int nxt : v[cur]) {
    if (!level[nxt]) {
      dfs(nxt, lev + 1);
      ac[nxt][0] = cur;
    }
  }
}
long long lca(int a, int b) {
  if (a * b == 0) return a + b;
  if (level[a] < level[b]) swap(a, b);
  long long ret = 0, gap = level[a] - level[b];
  for (int i = 0; gap; i++, gap >>= 1) {
    if (gap & 1) {
      a = ac[a][i];
    }
  }
  if (a == b) return a;
  for (int i = 18; i >= 0; i--) {
    if (ac[a][i] != ac[b][i]) {
      a = ac[a][i];
      b = ac[b][i];
    }
  }
  return ac[a][0];
}
int tree[400005];
void update(int i, int v, int n = 1, int s = 1, int e = N) {
  if (i < s || e < i) return;
  if (s == e)
    tree[n] = v;
  else {
    int mid = s + e >> 1;
    update(i, v, n * 2, s, mid);
    update(i, v, n * 2 + 1, mid + 1, e);
    tree[n] = lca(tree[n * 2], tree[n * 2 + 1]);
  }
}
int find(int l, int r, int n = 1, int s = 1, int e = N) {
  if (r < l || r < s || e < l) return 0;
  if (l <= s && e <= r) return tree[n];
  int mid = s + e >> 1;
  return lca(find(l, r, n * 2, s, mid), find(l, r, n * 2 + 1, mid + 1, e));
}
int main() {
  scanf("%d %d", &N, &Q);
  for (int i = 2; i <= N; i++) {
    scanf("%d", p + i);
    v[p[i]].push_back(i);
  }
  dfs(1, 1);
  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j <= N; j++) {
      ac[j][i] = ac[ac[j][i - 1]][i - 1];
    }
  }
  for (int i = 1; i <= N; i++) {
    update(i, i);
  }
  while (Q--) {
    int a, b;
    scanf("%d %d", &a, &b);
    int P = find(a, b);
    int l1 = a - 1, r1 = b;
    while (l1 + 1 < r1) {
      int mid = l1 + r1 >> 1;
      if (find(a, mid) != P)
        l1 = mid;
      else
        r1 = mid;
    }
    int l2 = a, r2 = b + 1;
    while (l2 + 1 < r2) {
      int mid = l2 + r2 >> 1;
      if (find(mid, b) != P)
        r2 = mid;
      else
        l2 = mid;
    }
    int A = r1, B = l2;
    int pa = lca(find(a, A - 1), find(A + 1, b)),
        pb = lca(find(a, B - 1), find(B + 1, b));
    if (level[pa] >= level[pb]) {
      printf("%d %d\n", A, level[pa] - 1);
    } else {
      printf("%d %d\n", B, level[pb] - 1);
    }
  }
}
