#include <bits/stdc++.h>
using namespace std;
const int N = 2009;
struct node {
  char w[505];
} p[N];
long long dis[N][N];
int bit(int n) {
  int cnt = 0;
  while (n) {
    if (n & 1) cnt++;
    n >>= 1;
  }
  return cnt;
}
int cal(const node &a, const node &b) {
  int i, cnt = 0;
  for (i = 0; a.w[i] && b.w[i]; i++) {
    if (a.w[i] != b.w[i]) break;
    cnt++;
  }
  return cnt;
}
int main() {
  int i, j, k, n, s, m;
  int stack[24], size;
  while (~scanf("%d%d", &n, &k)) {
    memset(dis, 0, sizeof(dis));
    for (i = 0; i < n; i++) {
      scanf("%s", p[i].w);
    }
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        dis[i][j] = dis[j][i] = cal(p[i], p[j]);
      }
    }
    s = (1 << n);
    long long ans = 0;
    long long tmp = 0;
    for (i = 0; i < s; i++) {
      if (bit(i) == k) {
        size = 0;
        for (j = 0; j < n; j++) {
          if ((1 << j) & (i)) {
            stack[size++] = j;
          }
        }
        tmp = 0;
        for (j = 0; j < size; j++) {
          for (m = j + 1; m < size; m++) {
            tmp += dis[stack[j]][stack[m]];
          }
        }
        ans = max(ans, tmp);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
