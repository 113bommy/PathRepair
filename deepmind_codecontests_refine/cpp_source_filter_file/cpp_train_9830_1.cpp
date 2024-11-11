#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 1e6 + 2, M = 1e7 + 10, inf = 1e9 + 10;
const long long INF = 1e18 + 10, mod = 1e9 + 7;
char s[N];
struct ans {
  int x, y, z;
  ans() {}
  ans(int xx, int yy, int zz) {
    x = xx;
    y = yy;
    z = zz;
  }
};
struct SGT {
  int LT[N << 2], RT[N << 2], MT[N << 2];
  void pushup(int pos) {
    int k = min(LT[pos << 1], RT[pos << 1 | 1]);
    MT[pos] = MT[pos << 1 | 1] + MT[pos << 1 | 1] + 2 * k;
    LT[pos] = LT[pos << 1] + LT[pos << 1 | 1] - k;
    RT[pos] = RT[pos << 1] + RT[pos << 1 | 1] - k;
  }
  void build(int l, int r, int pos) {
    if (l == r) {
      LT[pos] = 0;
      RT[pos] = 0;
      MT[pos] = 0;
      if (s[l] == '(')
        LT[pos]++;
      else
        RT[pos]++;
      return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
    pushup(pos);
  }
  ans query(int L, int R, int l, int r, int pos) {
    if (L == l && r == R) return ans(LT[pos], MT[pos], RT[pos]);
    int mid = (l + r) >> 1;
    if (R <= mid)
      return query(L, R, l, mid, pos << 1);
    else if (L > mid)
      return query(L, R, mid + 1, r, pos << 1 | 1);
    else {
      ans a = query(L, mid, l, mid, pos << 1);
      ans b = query(mid + 1, R, mid + 1, r, pos << 1 | 1);
      int k = min(a.x, b.z);
      int m = a.y + b.y + 2 * k;
      int l = a.x + b.x - k;
      int r = a.z + b.z - k;
      return ans(l, m, r);
    }
  }
};
SGT tree;
int main() {
  scanf("%s", s + 1);
  int x = strlen(s + 1);
  tree.build(1, x, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", tree.query(l, r, 1, x, 1).y);
  }
  return 0;
}
