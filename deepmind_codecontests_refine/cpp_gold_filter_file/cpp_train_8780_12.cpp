#include <bits/stdc++.h>
using namespace std;
const int N = 200012, MOD = 100000007;
int a[N], b[N], pos[N], n, m, ans = 0;
long long delta, p[N], ha;
struct Xnode {
  Xnode *lch, *rch;
  int l, r, size;
  long long hash;
  inline void Update() {
    hash = (lch->hash * p[rch->size] + rch->hash) % MOD;
    size = lch->size + rch->size;
  }
  void Change(int x, int t) {
    if (l == r) {
      size = t;
      hash = t * b[x];
      return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
      lch->Change(x, t);
    else
      rch->Change(x, t);
    Update();
  }
} X[N * 2], *P = X, *root;
void Build(Xnode *&node, int left, int right) {
  node = P++;
  node->l = left;
  node->r = right;
  node->size = 0;
  node->hash = 0;
  if (left == right) return;
  int mid = (left + right) >> 1;
  Build(node->lch, left, mid);
  Build(node->rch, mid + 1, right);
  node->Update();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    scanf("%d", &a[i]), ha = (ha * (m + 1) + a[i]) % MOD,
                        delta = (delta * (m + 1) + 1) % MOD;
  p[0] = 1;
  for (int i = 1; i <= m; ++i)
    scanf("%d", &b[i]), pos[b[i]] = i, p[i] = p[i - 1] * (m + 1) % MOD;
  Build(root, 1, m);
  for (int i = 1; i <= m; ++i) {
    root->Change(pos[i], 1);
    if (i > n) {
      root->Change(pos[i - n], 0);
      ha = (ha + delta) % MOD;
    }
    if (root->hash == ha) ++ans;
  }
  printf("%d\n", ans);
}
