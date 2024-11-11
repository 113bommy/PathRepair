#include <bits/stdc++.h>
using namespace std;
FILE *in;
FILE *out;
const int MAX = 1048576;
const int TREE = 2097152;
int n;
int a[MAX];
int ind[MAX];
int tree[TREE];
void update(int idx, int val) {
  idx += (TREE >> 1);
  while (idx) {
    tree[idx] += val;
    idx >>= 1;
  }
}
int query(int idx1, int idx2) {
  idx1 += (TREE >> 1);
  idx2 += (TREE >> 1);
  if (idx1 == idx2) return tree[idx1];
  int ret = 0;
  int flag1 = !(idx1 & 1);
  ret += tree[idx1];
  idx1 >>= 1;
  int flag2 = (idx2 & 1);
  ret += tree[idx2];
  idx2 >>= 1;
  while (idx1 != idx2) {
    if (flag1) ret += tree[(idx1 << 1) + 1];
    if (flag2) ret += tree[(idx2 << 1) + 0];
    flag1 = !(idx1 & 1);
    idx1 >>= 1;
    flag2 = (idx2 & 1);
    idx2 >>= 1;
  }
  return ret;
}
void doUpdate(int num, int oIdx, int nIdx) {
  if (oIdx < ind[num + 1] && nIdx >= ind[num + 1]) update(num, +1);
  if (oIdx > ind[num + 1] && nIdx <= ind[num + 1]) update(num, -1);
  if (oIdx < ind[num - 1] && nIdx >= ind[num - 1]) update(num - 1, -1);
  if (oIdx > ind[num - 1] && nIdx <= ind[num - 1]) update(num - 1, +1);
}
int main(void) {
  in = stdin;
  out = stdout;
  fscanf(in, "%d", &n);
  for (int i = 1; i <= n; i++) {
    fscanf(in, "%d", &a[i]);
    ind[a[i]] = i;
  }
  a[0] = 0;
  ind[0] = 0;
  a[n + 1] = n + 1;
  ind[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    if (ind[i + 1] < ind[i]) update(i, +1);
  }
  int numQueries;
  fscanf(in, "%d", &numQueries);
  for (int i = 0; i < numQueries; i++) {
    int t, x, y;
    fscanf(in, "%d %d %d", &t, &x, &y);
    if (t == 1) {
      fprintf(out, "%d\n", query(x, y - 1) + 1);
    } else {
      doUpdate(a[x], x, y);
      doUpdate(a[y], y, x);
      if (abs(a[x] - a[y]) == 1) {
        if (a[x] < a[y])
          update(a[x], -1);
        else
          update(a[y], +1);
      }
      swap(a[x], a[y]);
      swap(ind[a[x]], ind[a[y]]);
    }
  }
  return 0;
}
