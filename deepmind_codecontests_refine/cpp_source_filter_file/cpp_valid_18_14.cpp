#include <bits/stdc++.h>
using namespace std;
int is_intersect(int x1, int x2, int y1, int y2) {
  if (x2 < y1) {
    return 0;
  }
  if (y2 < x1) {
    return 0;
  }
  if (x1 < y1 && y2 < x2) {
    return 0;
  }
  if (y1 < x1 && x2 < y2) {
    return 0;
  }
  return 1;
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  int lnk[2560] = {0};
  int empty_index[2560];
  int empty_cnt = 0;
  int chord_x[1280];
  int chord_y[1280];
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
      swap(x, y);
    }
    lnk[x] = y;
    lnk[y] = x;
    chord_x[i] = x;
    chord_y[i] = y;
    for (int j = 0; j < i; j++) {
      if (is_intersect(chord_x[j], chord_y[j], x, y)) {
        ans++;
      }
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (lnk[i] == 0) {
      empty_index[empty_cnt++] = i;
    }
  }
  for (int i = 0; i < empty_cnt; i++) {
    int x = empty_index[i];
    int y = empty_index[i + (n - k)];
    for (int e = x + 1; e < y; e++) {
      if (lnk[e] && (lnk[e] < x || lnk[e] > y)) {
        ans++;
      }
    }
  }
  switch (n - k) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      ans++;
      break;
    default:
      ans += (n - k) * (n - k - 1) / 2;
      break;
  }
  printf("%d\n", ans);
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    solve();
  }
  return 0;
}
