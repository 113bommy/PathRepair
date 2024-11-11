#include <bits/stdc++.h>
using namespace std;
enum { Maxn = 1000007 };
long long cmlf[200005];
long long cmrg[200005];
long long dis[200005];
int d[200005];
int h[200005];
struct Node {
  int lf;
  int rg;
  int topl;
  int topr;
  Node *l;
  Node *r;
};
int N, M;
Node root;
int f(Node *p, int lf, int rg, int &topl, int &topr) {
  int mid = (p->lf + p->rg) / 2;
  if (lf == p->lf && rg == p->rg) {
    topl = p->topl;
    topr = p->topr;
  } else if (rg <= mid) {
    f(p->l, lf, rg, topl, topr);
  } else if (lf > mid)
    f(p->r, lf, rg, topl, topr);
  else {
    int templ, tempr;
    f(p->l, lf, mid, topl, tempr);
    f(p->r, mid + 1, rg, templ, topr);
    if (cmlf[templ] > cmlf[topl]) topl = templ;
    if (cmrg[tempr] > cmrg[topr]) topr = tempr;
  }
  return 0;
}
int build_tree(Node *p, int lf, int rg) {
  int mid = (lf + rg) / 2;
  int topl, topr;
  p->lf = lf;
  p->rg = rg;
  if (lf == rg) {
    p->topl = lf;
    p->topr = rg;
    p->l = NULL;
    p->r = NULL;
  } else {
    p->l = new Node;
    p->r = new Node;
    build_tree(p->l, lf, mid);
    build_tree(p->r, mid + 1, rg);
    int templ, tempr;
    f(p->l, lf, mid, topl, tempr);
    f(p->r, mid + 1, rg, templ, topr);
    if (cmlf[templ] > cmlf[topl]) topl = templ;
    if (cmrg[tempr] > cmrg[topr]) topr = tempr;
    p->topl = topl;
    p->topr = topr;
  }
  return 0;
}
long long mr2(int lf, int rg) { return dis[rg] - dis[lf] + h[lf] + h[rg]; }
long long mr(int lf, int rg) {
  int topl, topr;
  int templ, tempr;
  int temp;
  f(&root, lf, rg, topl, topr);
  if (topl == topr) {
    if (topl == lf) {
      f(&root, topl + 1, rg, temp, tempr);
      return mr2(topl, tempr);
    } else if (topl == rg) {
      f(&root, lf, topl - 1, templ, temp);
      return mr2(templ, topr);
    } else {
      f(&root, lf, topl - 1, templ, temp);
      f(&root, topl + 1, rg, temp, tempr);
      return max(mr2(topl, tempr), mr2(templ, topr));
    }
  }
  return mr2(topl, topr);
}
int main() {
  int n, m;
  int i, j, k;
  long long result;
  int a, b;
  cin >> n >> m;
  for (i = 1; i <= n; ++i) scanf("%d", &d[i]);
  for (i = 1; i <= n; ++i) scanf("%d", &h[i]);
  for (i = 1; i <= n; ++i) {
    h[i] *= 2;
  }
  memcpy(d + n + 1, d + 1, sizeof(int) * n);
  memcpy(h + n + 1, h + 1, sizeof(int) * n);
  dis[1] = 0;
  for (i = 2; i <= 2 * n; ++i) dis[i] = dis[i - 1] + d[i - 1];
  for (i = 1; i <= 2 * n; ++i) {
    cmlf[i] = -dis[i] + h[i];
    cmrg[i] = dis[i] + h[i];
  }
  build_tree(&root, 1, 2 * n);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    if (a > b) {
      result = mr(b + 1, a - 1);
    } else {
      result = mr(b + 1, a - 1 + n);
    }
    printf("%I64d\n", result);
  }
  return 0;
}
