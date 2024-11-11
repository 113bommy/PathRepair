#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 10;
int n, p[maxn], q[maxn], pos[maxn];
int t[maxn], laz[maxn];
void push_down(int rt) {
  if (laz[rt]) {
    laz[rt << 1] += laz[rt];
    laz[rt << 1 | 1] += laz[rt];
    t[rt << 1] += laz[rt];
    t[rt << 1 | 1] += laz[rt];
    laz[rt] = 0;
  }
}
void updata(int rt, int l, int r, int ql, int qr, int val) {
  if (ql <= l && r <= qr) {
    t[rt] += val;
    laz[rt] += val;
    return;
  }
  push_down(rt);
  int mid = (l + r) >> 1;
  if (ql <= mid) updata(rt << 1, l, mid, ql, qr, val);
  if (qr > mid) updata(rt << 1 | 1, mid + 1, r, ql, qr, val);
  t[rt] = min(t[rt << 1], t[rt << 1 | 1]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
  for (int i = 1, j = n; i <= n; i++) {
    while (j >= 1 && t[1] >= 0) updata(1, 1, n, 1, pos[j--], -1);
    printf("%d ", j + 1);
    updata(1, 1, n, 1, q[i], 1);
  }
  return 0;
}
