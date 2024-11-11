#include <bits/stdc++.h>
using namespace std;
int i, j, m, n, inf, maxlog, nowmax, temp;
int stlmax[100005][21], stlmin[100005][21], strmax[100005][21],
    strmin[100005][21];
int x[100005], getlog[100005];
int bis2(int l, int r, int xx, int ans) {
  if (l == r) return l;
  int mid = ((l + r) >> 1) + 1;
  int temp2 = getlog[mid - l + 1];
  if ((strmax[xx][temp2] <= ans + x[xx]) &&
      (stlmax[mid][temp2] <= ans + x[xx]) &&
      (strmin[xx][temp2] >= x[xx] - ans) && (stlmin[mid][temp2] >= x[xx] - ans))
    return (bis2(mid, r, xx, ans));
  else
    return (bis2(l, mid - 1, xx, ans));
}
bool check(int ans) {
  if (abs(x[1] - x[2]) > ans) return false;
  nowmax = 1;
  for (i = 1; i <= n; i++) {
    if ((nowmax >= i) && (abs(x[i] - x[i + 1]) <= ans)) {
      int temp2 = getlog[n - i + 1];
      if ((strmax[i][temp2] <= ans + x[i]) &&
          (stlmax[n][temp2] <= ans + x[i]) &&
          (strmin[i][temp2] >= x[i] - ans) && (stlmin[n][temp2] >= x[i] - ans))
        return true;
      temp = bis2(i, n, i, ans);
      nowmax = max(nowmax, temp);
    }
  }
  return false;
}
int bis(int l, int r) {
  if (l == r) return l;
  int mid = ((l + r) >> 1);
  if (check(mid))
    return (bis(l, mid));
  else
    return (bis(mid + 1, r));
}
int main() {
  inf = (int)(1e9 + 7);
  scanf("%d%d%d", &n, &x[1], &x[2]);
  for (i = 3; i <= n + 2; i++) {
    scanf("%d", &x[i]);
  }
  n += 2;
  maxlog = 21;
  for (i = 1; i <= n; i++) {
    stlmax[i][0] = stlmin[i][0] = strmax[i][0] = strmin[i][0] = x[i];
  }
  for (i = 1; i <= maxlog; i++) {
    for (j = 1 << i; j <= n; j++) {
      stlmax[j][i] = max(stlmax[j][i - 1], stlmax[j - (1 << (i - 1))][i - 1]);
      stlmin[j][i] = min(stlmin[j][i - 1], stlmin[j - (1 << (i - 1))][i - 1]);
    }
    for (j = 1; j <= n - (1 << i) + 1; j++) {
      strmax[j][i] = max(strmax[j][i - 1], strmax[j + (1 << (i - 1))][i - 1]);
      strmin[j][i] = min(strmin[j][i - 1], strmin[j + (1 << (i - 1))][i - 1]);
    }
  }
  getlog[1] = 0;
  getlog[2] = 1;
  for (i = 3; i <= n; i++) {
    getlog[i] = getlog[i / 2] + 1;
  }
  printf("%d\n", bis(1, inf));
  return 0;
}
