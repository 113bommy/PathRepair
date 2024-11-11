#include <bits/stdc++.h>
using namespace std;
const int mo = 998244353;
const int N = 100005;
const int BLK = 405;
const int K = 255;
int L[K], R[K], tg[K];
int top[K], pos[K];
int id[N], f[N], s[N];
int v[N], V[N], LIM;
int a[N], la[N], pre[N], n;
void pushdown(int k) {
  for (int i = (int)(L[k]); i <= (int)(R[k]); i++) s[i] += tg[k];
  tg[k] = 0;
}
void pushup(int k) {
  top[k] = L[k];
  v[top[k]] = f[id[L[k]]];
  V[top[k]] = s[id[L[k]]];
  for (int i = (int)(L[k] + 1); i <= (int)(R[k]); i++) {
    if (s[id[i]] != s[id[i - 1]]) {
      V[++top[k]] = s[id[i]];
      v[top[k]] = v[top[k] - 1];
    }
    v[top[k]] = (v[top[k]] + f[id[i]]) % mo;
  }
  pos[k] = L[k] - 1;
  for (; pos[k] != top[k]; ++pos[k])
    if (V[pos[k] + 1] > LIM) break;
}
bool cmp(int x, int y) { return s[x] < s[y]; }
void build(int k) {
  for (int i = (int)(L[k]); i <= (int)(R[k]); i++) id[i] = i;
  sort(id + L[k], id + R[k] + 1, cmp);
  pushup(k);
}
int q1[BLK + 5], q2[BLK + 5];
void add(int k, int l, int r, int v) {
  pushdown(k);
  int p1 = 0, p2 = 0, p3 = L[k] - 1;
  for (int i = (int)(L[k]); i <= (int)(R[k]); i++)
    if (l <= id[i] && id[i] <= r)
      q1[++p1] = id[i], s[id[i]] += v;
    else
      q2[++p2] = id[i];
  int pp1 = 1, pp2 = 1;
  for (; pp1 <= p1 || pp2 <= p2;)
    if (pp2 > p2 || (pp1 <= p1 && s[q1[pp1]] < s[q2[pp2]]))
      id[++p3] = q1[pp1++];
    else
      id[++p3] = q2[pp2++];
  pushup(k);
}
void add(int k, int val) {
  tg[k] += val;
  for (; pos[k] != top[k] && V[pos[k] + 1] + tg[k] <= LIM; ++pos[k])
    ;
  for (; pos[k] != L[k] - 1 && V[pos[k]] + tg[k] > LIM; --pos[k])
    ;
}
int query(int k) { return pos[k] == L[k] - 1 ? 0 : v[pos[k]]; }
int ed;
void change(int l, int r, int v) {
  for (; r >= l && r >= ed; r--) s[r] += v;
  if (r < l) return;
  int bl = l / BLK, br = r / BLK;
  if (bl == br)
    add(bl, l, r, v);
  else {
    for (int i = (int)(bl + 1); i <= (int)(br - 1); i++) add(i, v);
    add(bl, l, R[bl], v);
    add(br, L[br], r, v);
  }
}
void update(int x) {
  change(pre[x], x - 1, 1);
  if (pre[x]) change(pre[pre[x]], pre[x] - 1, -1);
}
int main() {
  scanf("%d%d", &n, &LIM);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &a[i]);
  for (int i = (int)(1); i <= (int)(n); i++) la[a[i]] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) pre[i] = la[a[i]], la[a[i]] = i;
  for (int i = (int)(0); i <= (int)(n / BLK); i++)
    L[i] = i * BLK, R[i] = min(i * BLK + BLK - 1, n);
  f[0] = 1;
  for (int i = (int)(1); i <= (int)(n); i++) {
    update(i);
    int be = i / BLK;
    for (int j = (int)(0); j <= (int)(be - 1); j++)
      f[i] = (f[i] + query(j)) % mo;
    for (int j = (int)(be * BLK); j <= (int)(i - 1); j++)
      if (s[j] <= LIM) f[i] = (f[i] + f[j]) % mo;
    if (i % BLK == BLK - 1 || i == n) build(i / BLK), ed = i;
  }
  printf("%d\n", f[n]);
}
