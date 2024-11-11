#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int r[10100], tem[10100], ans[10100];
int b[10100], p[10100], oth;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("? %d %d\n", i, 0);
    fflush(stdout);
    scanf("%d", &r[i]);
  }
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (!r[i]) x = i;
  }
  tem[0] = r[0];
  if (tem[0] == x) q.push(0);
  for (int i = 1; i < n; i++) {
    printf("? %d %d\n", i, i);
    fflush(stdout);
    scanf("%d", &tem[i]);
    if (tem[i] == x) q.push(i);
  }
  printf("? %d %d\n", 0, n - 1);
  fflush(stdout);
  scanf("%d", &oth);
  int cnt = 0;
  for (int y = 0; y < n; y++) {
    int ff = 1;
    b[0] = y;
    for (int i = 0; i < n; i++) {
      p[i] = r[i] ^ y;
    }
    for (int i = 0; i < n; i++) {
      b[p[i]] = i;
    }
    if (y != b[0]) ff = 0;
    for (int i = 0; i < n; i++) {
      if ((b[i] ^ p[i]) != tem[i]) ff = 0;
    }
    if ((b[n - 1] ^ p[0]) != oth) ff = 0;
    if (ff) {
      cnt++;
    }
    if (ff && cnt == 1)
      for (int i = 0; i < n; i++) {
        ans[i] = p[i];
      }
  }
  printf("!\n%d\n", cnt);
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
