#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
int a[MX];
int n;
bool possible(int j, int i, int s1, int s2, int cnt) {
  if (s1 == 1) {
    if (j + 1 > n || a[j + 1] != 0) return false;
    s1++;
    j++;
  }
  if (i - s2 + 1 <= j) return false;
  int mn = (max(0, (i - s2) - j - (5 - s1)) + 4) / 5;
  int mx = ((i - s2) - j) / 2;
  return mn <= cnt && cnt <= mx;
}
bool can[MX][6];
int main() {
  ignore = scanf("%d", &n);
  for (int i = 1; i <= n; i++) ignore = scanf("%d", a + i);
  {
    int pr = 0;
    for (int i = 1; i <= n; i++) {
      if (!a[i]) continue;
      if (a[i] == a[pr]) {
        while (pr < i) {
          a[pr] = a[i];
          pr++;
        }
      }
      pr = i;
    }
    pr = 0;
    for (int i = 1; i <= n; i++) {
      if (!a[i]) continue;
      if (a[i] < pr) {
        printf("-1\n");
        return 0;
      }
      pr = a[i];
    }
  }
  int pr = 0;
  can[0][5] = true;
  for (int i = 1; i <= n; i++) {
    if (!a[i]) continue;
    int cnt = 1;
    while (i + 1 <= n && a[i + 1] == a[i]) {
      i++;
      cnt++;
    }
    while (cnt <= 5) {
      for (int c = 1; c <= 5; c++) {
        if (!can[pr][c]) continue;
        can[i][cnt] = possible(pr, i, c, cnt, a[i] - a[pr] - 1);
      }
      cnt++;
    }
    pr = i;
  }
  can[n][1] = false;
  can[n - 1][5] = false;
  int x = 2;
  while (x <= 5 && !can[pr][x]) x++;
  if (x > 5) {
    if (can[pr][1]) x = 1;
  }
  if (x > 5) {
    printf("-1\n");
    return 0;
  }
  if (x == 1) {
    x = 2;
    pr++;
    a[pr] = a[pr - 1];
  }
  for (int i = pr + 1; i <= n; i += 2) {
    if (i + 1 <= n) {
      a[i] = a[i - 1] + 1;
      a[i + 1] = a[i];
    } else {
      a[i] = a[i - 1];
    }
  }
  while (true) {
    int j = pr - 1;
    int t;
    while (j >= 0) {
      bool ok = false;
      for (t = 1; t <= 5; t++) {
        if (can[j][t] && possible(j, pr, t, x, a[pr] - a[j] - 1)) {
          ok = true;
          break;
        }
      }
      if (ok) break;
      j--;
    }
    if (j < 0) break;
    if (t == 1) {
      t = 2;
      j++;
      a[j] = a[j - 1];
    }
    while (--pr > j) {
      int cc = 0;
      for (int i = pr; a[i + 1] == a[pr + 1]; i++) cc++;
      bool ok = false;
      for (int v = 1; v + cc <= 5; v++) {
        if (a[pr + 1] == a[j] ||
            (v + cc <= 5 &&
             possible(j, pr + cc, t, cc + v, a[pr + 1] - a[j] - 1))) {
          a[pr] = a[pr + 1];
          ok = true;
          break;
        }
      }
      if (!ok) {
        a[pr] = a[pr + 1] - 1;
      }
    }
    pr = j;
    x = t;
  }
  for (int i = 1, cc = 0; i <= n; i++) {
    if (a[i] < a[i - 1]) {
      printf("-1\n");
      return 0;
    }
    if (a[i] == a[i - 1]) {
      cc++;
    } else {
      cc = 0;
    }
    if (cc == 5) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n", a[n]);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
}
