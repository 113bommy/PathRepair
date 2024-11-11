#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300001;
const int LOGN = 19;
int N, M;
bool has[MAXN];
int cnt[2 * MAXN][LOGN];
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0, x; i < N; i++) {
    scanf("%d", &x);
    has[x] = true;
  }
  for (int i = 0; i < MAXN; i++)
    if (has[i])
      for (int j = 0; j < LOGN; j++) cnt[i >> j][j]++;
  int cur = 0;
  for (int i = 0, x; i < M; i++) {
    scanf("%d", &x);
    cur ^= x;
    int ans = 0, need = cur, y = LOGN;
    for (int j = 0; j < y; j++)
      if (cnt[need >> j][j] < (1 << j)) {
        if (j > 0) {
          ans |= (1 << (j - 1));
          need ^= (1 << (j - 1));
        }
        y = j;
        j = -1;
      }
    printf("%d\n", ans);
  }
  return 0;
}
