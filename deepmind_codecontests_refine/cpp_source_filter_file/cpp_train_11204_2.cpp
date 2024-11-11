#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int sum[N << 2];
bool vis[N];
void update(int x, int c, int l, int r, int rt) {
  if (l == r) {
    sum[rt] = c;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= x) update(x, c, l, mid, rt << 1);
  if (mid < x) update(x, c, mid + 1, r, rt << 1 | 1);
  sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int main() {
  int n;
  scanf("%d", &n);
  printf("!!%d", 1);
  int bef = n;
  for (int i = 1; i <= n; i++) {
    int now;
    scanf("%d", &now);
    vis[now] = 1;
    if (now == bef) {
      for (int j = now - 1; j >= 1; j--) {
        if (vis[j])
          update(j, 0, 1, n, 1);
        else {
          bef = j;
          break;
        }
      }
    } else {
      update(now, 1, 1, n, 1);
    }
    printf(" %d", sum[1] + 1);
  }
  puts("");
  return 0;
}
