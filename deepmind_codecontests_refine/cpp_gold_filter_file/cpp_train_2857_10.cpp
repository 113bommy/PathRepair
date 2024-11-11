#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long ans1[N * 2], ans2[N * 2];
struct node {
  int id, v, typ;
  node(int id = 0, int v = 0, int typ = 0) : id(id), v(v), typ(typ) {}
} v1[N * 2];
inline int cmp1(const node &a, const node &b) {
  if (a.v == b.v) return a.typ < b.typ;
  return a.v < b.v;
}
struct item {
  int id, va, vb;
  item(int id = 0, int va = 0, int vb = 0) : id(id), va(va), vb(vb) {}
} v2[N];
inline int cmp2(const item &a, const item &b) {
  return a.va + a.vb < b.va + b.vb;
}
int c1, c2, mxb[N], mna[N], way[N];
int main() {
  int n, m, i;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    int va, vb;
    scanf("%d%d", &va, &vb);
    if (vb >= va * 2) {
      v1[++c1] = node(i, va, 1);
      v1[++c1] = node(i, vb - va, 2);
    } else
      v2[++c2] = item(i, va, vb - va);
  }
  sort(v1 + 1, v1 + c1 + 1, cmp1);
  sort(v2 + 1, v2 + c2 + 1, cmp2);
  for (i = 1; i <= c1; i++) ans1[i] = ans1[i - 1] + v1[i].v;
  mna[c2] = v2[c2].va;
  for (i = c2 - 1; i >= 1; i--) mna[i] = min(mna[i + 1], v2[i].va);
  mxb[0] = -2e9;
  long long sum = 0;
  for (i = 1; i <= c2; i++) {
    mxb[i] = max(mxb[i - 1], v2[i].vb);
    ans2[i * 2 - 1] = min(sum + mna[i], sum - mxb[i - 1] + v2[i].va + v2[i].vb);
    sum += v2[i].va + v2[i].vb;
    ans2[i * 2] = sum;
  }
  int p1 = 0, p2 = 0;
  long long fn = 1e18;
  for (i = max(m - c1, 0); i <= min(m, c2 * 2); i++) {
    long long tans = ans2[i] + ans1[m - i];
    if (fn > tans) p1 = m - i, p2 = i, fn = tans;
  }
  for (i = 1; i <= p1; i++) way[v1[i].id] = v1[i].typ;
  for (i = 1; i <= p2 / 2; i++) way[v2[i].id] = 2;
  if (p2 & 1) {
    int ad1 = (p2 + 1) / 2, ad2 = p2 / 2;
    if (mna[ad1] <= v2[ad1].va + v2[ad1].vb - mxb[ad2]) {
      for (i = c2; i >= ad1; i--) {
        if (v2[i].va == mna[ad1]) {
          way[v2[i].id] = 1;
          break;
        }
      }
    } else {
      way[v2[ad1].id] = 2;
      for (i = 1; i <= ad2; i++) {
        if (v2[i].vb == mxb[ad2]) {
          way[v2[i].id] = 1;
          break;
        }
      }
    }
  }
  printf("%lld\n", fn);
  for (i = 1; i <= n; i++) printf("%d", way[i]);
  return 0;
}
