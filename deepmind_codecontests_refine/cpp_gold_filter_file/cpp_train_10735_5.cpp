#include <bits/stdc++.h>
using namespace std;
const int maxt = 1 << 21, maxm = 1000005, tn = 1 << 20;
long long mx[maxt], tag[maxt], bit[maxm];
int argt[maxm], argd[maxm], Q;
char opt[5];
void add(int x, int w) {
  for (; x < maxm; x += x & -x) bit[x] += w;
}
long long sum(int x) {
  long long res = 0;
  for (; x; x -= x & -x) res += bit[x];
  return res;
}
void build(int l = 0, int r = tn, int k = 0) {
  mx[k] = r - 1;
  if (l + 1 == r) return;
  int mid = (l + r) >> 1;
  build(l, mid, k * 2 + 1), build(mid, r, k * 2 + 2);
}
void pushdown(int k) {
  if (!tag[k]) return;
  int ls = k * 2 + 1, rs = k * 2 + 2;
  mx[ls] += tag[k], tag[ls] += tag[k];
  mx[rs] += tag[k], tag[rs] += tag[k];
  tag[k] = 0;
}
void update(int a, int b, int x, int l = 0, int r = tn, int k = 0) {
  if (a >= r || b <= l) return;
  if (a <= l && b >= r) {
    tag[k] += x;
    mx[k] += x;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(k);
  update(a, b, x, l, mid, k * 2 + 1);
  update(a, b, x, mid, r, k * 2 + 2);
  mx[k] = max(mx[k * 2 + 1], mx[k * 2 + 2]);
}
long long query(int a, int b, int l = 0, int r = tn, int k = 0) {
  if (a >= r || b <= l) return LLONG_MIN;
  if (a <= l && b >= r) return mx[k];
  int mid = (l + r) >> 1;
  pushdown(k);
  return max(query(a, b, l, mid, k * 2 + 1), query(a, b, mid, r, k * 2 + 2));
}
int main() {
  build();
  scanf("%d", &Q);
  for (int i = 1; i <= Q; i++) {
    scanf("%s", opt);
    if (opt[0] == '+') {
      int t, d;
      scanf("%d%d", &t, &d);
      argt[i] = t, argd[i] = d;
      update(t + 1, tn, -d);
      add(t, d);
    } else if (opt[0] == '-') {
      int t;
      scanf("%d", &t);
      update(argt[t] + 1, tn, argd[t]);
      add(argt[t], -argd[t]);
    } else {
      int t;
      scanf("%d", &t);
      long long res = max((long long)t, query(0, t + 1) + sum(t));
      printf("%lld\n", res - t);
    }
  }
  return 0;
}
