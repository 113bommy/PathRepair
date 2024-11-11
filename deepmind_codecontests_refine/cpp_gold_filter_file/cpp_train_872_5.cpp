#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int N, M;
long long tree[4][MAXN][MAXN];
int ju(int x, int y) {
  int tt = 0;
  if (x % 2) tt++;
  if (y % 2) tt += 2;
  return tt;
}
void Update(int x, int y, long long v) {
  int ty = ju(x, y);
  for (int i = x; i <= N; i += i & -i)
    for (int j = y; j <= N; j += j & -j) tree[ty][i][j] ^= v;
}
long long Sum(int x, int y) {
  int ty = ju(x, y);
  long long ans = 0;
  for (int i = x; i > 0; i -= i & -i)
    for (int j = y; j > 0; j -= j & -j) ans ^= tree[ty][i][j];
  return ans;
}
int main() {
  while (~scanf("%d %d", &N, &M)) {
    memset(tree, 0, sizeof(tree));
    for (int i = 1; i <= M; ++i) {
      int a, b, c, d;
      int ty;
      long long v;
      scanf("%d", &ty);
      if (ty == 2) {
        scanf("%d %d %d %d %lld", &a, &b, &c, &d, &v);
        Update(a, b, v);
        Update(c + 1, b, v);
        Update(a, d + 1, v);
        Update(c + 1, d + 1, v);
      } else {
        long long ans = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ans ^= Sum(c, d);
        ans ^= Sum(a - 1, d);
        ans ^= Sum(c, b - 1);
        ans ^= Sum(a - 1, b - 1);
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
