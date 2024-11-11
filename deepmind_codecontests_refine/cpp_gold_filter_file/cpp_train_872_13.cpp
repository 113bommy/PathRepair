#include <bits/stdc++.h>
using namespace std;
const int N = 1015;
int n, m;
long long s[2][2][N][N];
void change(int x, int y, long long z) {
  for (int i = x; i <= n + 5; i += (i & -i))
    for (int j = y; j <= n + 5; j += (j & -j)) s[x & 1][y & 1][i][j] ^= z;
}
long long query(int x, int y) {
  long long ans = 0;
  for (int i = x; i; i -= (i & -i))
    for (int j = y; j; j -= (j & -j)) ans ^= s[x & 1][y & 1][i][j];
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, y, xx, yy;
      scanf("%d%d%d%d", &x, &y, &xx, &yy);
      printf("%I64d\n", query(xx, yy) ^ query(x - 1, y - 1) ^ query(xx, y - 1) ^
                            query(x - 1, yy));
    } else {
      int x, y, xx, yy;
      long long z;
      scanf("%d%d%d%d%I64d", &x, &y, &xx, &yy, &z);
      change(x, y, z);
      change(x, yy + 1, z);
      change(xx + 1, y, z);
      change(xx + 1, yy + 1, z);
    }
  }
  return 0;
}
