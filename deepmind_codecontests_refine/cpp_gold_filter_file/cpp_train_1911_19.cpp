#include <bits/stdc++.h>
using namespace std;
int pos[500005][25], arr[500005], fa[500005][25], bit[500005];
inline int calc(int x, int y) {
  if (arr[x] <= arr[y]) return x;
  return y;
}
inline int query(int l, int r) {
  int len = bit[r - l + 1];
  return calc(pos[l][len], pos[r - (1 << len) + 1][len]);
}
int main() {
  for (int i = 2; i < 500005; i++) bit[i] = bit[i >> 1] + 1;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
    arr[i + n] = arr[i];
  }
  for (int i = 0; i < n << 1; i++) {
    arr[i] = i - arr[i];
    pos[i][0] = i;
  }
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j + (1 << i) <= n + n; j++)
      pos[j][i] = calc(pos[j][i - 1], pos[j + (1 << i - 1)][i - 1]);
  }
  for (int i = 0; i < n << 1; i++) fa[i][0] = query(arr[i], i);
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j < n << 1; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  }
  long long ans = 0;
  for (int i = n; i < n << 1; i++) {
    int x = i;
    ans += (arr[i] > i - n + 1) + 1;
    for (int j = 19; j >= 0; j--) {
      if (arr[fa[x][j]] > i - n + 1) {
        x = fa[x][j];
        ans += 1 << j;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
