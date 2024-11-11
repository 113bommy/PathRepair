#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2010;
int n, m, K, Q;
int num[MAX_N], cur[MAX_N], state[MAX_N];
long long C[MAX_N][MAX_N];
struct Garland {
  int x, y, w;
} garland[MAX_N][MAX_N];
inline int lowbit(int x) { return x & (-x); }
void update(int x, int y, int w) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += (lowbit(j))) {
      C[i][j] += w;
    }
  }
}
long long sum(int x, int y) {
  long long res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j -= lowbit(j)) {
      res += C[i][j];
    }
  }
  return res;
}
int main() {
  while (~scanf("%d%d%d", &n, &m, &K)) {
    memset(state, 0, sizeof(state));
    memset(cur, 0, sizeof(cur));
    memset(C, 0, sizeof(C));
    for (int i = 0; i < K; ++i) {
      scanf("%d", &num[i]);
      for (int j = 0; j < num[i]; ++j) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        garland[i][j].x = x, garland[i][j].y = y, garland[i][j].w = w;
        update(x, y, w);
      }
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
      char s[10];
      scanf("%s", s);
      if (s[0] == 'S') {
        int id;
        scanf("%d", &id);
        id--;
        state[id] = 1;
        cur[id] ^= 1;
      } else {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        for (int i = 0; i < K; ++i) {
          if (state[i] == 0) continue;
          int flag = 1;
          if (cur[i] == 1) flag = -1;
          state[i] = 0;
          for (int j = 0; j < num[i]; ++j) {
            int x = garland[i][j].x, y = garland[i][j].y, w = garland[i][j].w;
            update(x, y, flag * w);
          }
        }
        long long ans =
            sum(c, d) + sum(a - 1, b - 1) - sum(c, b - 1) - sum(a - 1, d);
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
