#include <bits/stdc++.h>
using namespace std;
long long w, sum[1010][2][1010][2];
int op, tx1, tx2, ty1, ty2, n, t;
int lowbit(int x) { return x & -x; }
void update(int x, int y, long long val) {
  int p1 = ((x + 1) >> 1), op1 = x % 2, p2 = ((y + 1) >> 1), op2 = y % 2;
  for (int i = p1; i <= n; i += lowbit(i))
    for (int j = p2; j <= n; j += lowbit(j)) sum[i][op1][j][op2] ^= val;
}
long long query(int x, int y) {
  int p1 = ((x + 1) >> 1), op1 = x % 2, p2 = ((y + 1) >> 1), op2 = y % 2;
  long long ans = 0;
  for (int i = p1; i >= 1; i -= lowbit(i))
    for (int j = p2; j >= 1; j -= lowbit(j)) ans ^= sum[p1][op1][p2][op2];
  return ans;
}
int main() {
  scanf("%d%d", &n, &t);
  while (t--) {
    scanf("%d", &op);
    if (op == 2) {
      scanf("%d%d%d%d%I64d", &tx1, &ty1, &tx2, &ty2, &w);
      update(tx1, ty1, w);
      update(tx1, ty2 + 1, w);
      update(tx2 + 1, ty1, w);
      update(tx2 + 1, ty2 + 1, w);
    } else {
      scanf("%d%d%d%d", &tx2, &ty2, &tx1, &ty1);
      printf("%I64d\n", query(tx1, ty1) ^ query(tx1, ty2 - 1) ^
                            query(tx2 - 1, ty1) ^ query(tx2 - 1, ty2 - 1));
    }
  }
  return 0;
}
