#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long mod = 258280327;
int sum[N << 2], a[N << 2];
char s[N];
void pushup(int rt) { sum[rt] = min(sum[rt << 1], sum[rt << 1 | 1]); }
void build(int l, int r, int rt) {
  if (l == r) {
    sum[rt] = a[l];
    return;
  }
  int m = (l + r) >> 1;
  build(l, m, rt << 1);
  build(m + 1, r, rt << 1 | 1);
  pushup(rt);
}
int query(int L, int R, int l, int r, int rt) {
  if (L > r || R < l) return 0x3f3f3f3f;
  if (L <= l && R >= r) return sum[rt];
  int m = (l + r) >> 1;
  return min(query(L, R, l, m, rt << 1), query(L, R, m + 1, r, rt << 1 | 1));
}
int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  for (int i = 0; i < n; i++) a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
  build(0, n, 1);
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    int d = query(l, r, 0, n, 1);
    printf("%d\n",
           r - l - (query(l, l, 0, n, 1) - d) - (query(r, r, 0, n, 1) - d));
  }
  return 0;
}
