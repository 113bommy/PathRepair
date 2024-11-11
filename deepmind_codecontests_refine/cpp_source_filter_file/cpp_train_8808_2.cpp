#include <bits/stdc++.h>
using namespace std;
const long long seed = 2333;
long long hash_(int a, int b, int c, int d) {
  return a * seed * seed * seed + b * seed * seed + c * seed + d;
}
long long c[2510][2510];
int n, m, q;
void update(int x, int y, long long z) {
  for (int i = x; i <= n; i += i & -i) {
    for (int j = y; j <= n; j += j & -j) c[i][j] += z;
  }
}
long long sum(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) {
    for (int j = y; j > 0; j -= j & -j) ans += c[i][j];
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < q; ++i) {
    int t, r1, c1, r2, c2;
    scanf("%d%d%d%d%d", &t, &r1, &c1, &r2, &c2);
    long long v = hash_(r1, c1, r2, c2);
    if (t == 1) {
      update(r1, c1, v);
      update(r2 + 1, c1, -v);
      update(r1, c2 + 1, -v);
      update(r2 + 1, c2 + 1, v);
    } else if (t == 2) {
      update(r1, c1, -v);
      update(r2 + 1, c1, +v);
      update(r1, c2 + 1, +v);
      update(r2 + 1, c2 + 1, -v);
    } else if (t == 3) {
      if (sum(r1, c1) == sum(r2, c2)) {
        printf("Yes\n");
      } else
        printf("No\n");
    }
  }
  return 0;
}
