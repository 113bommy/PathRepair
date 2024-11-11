#include <bits/stdc++.h>
using namespace std;
char map_[110][110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", map_[i]);
  }
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++) {
    int flag1 = 0, flag2 = 0;
    for (int j = 0; j < n; j++) {
      if (map_[i][j] != 'E') {
        flag1 = 1;
      }
      if (map_[j][i] != 'E') {
        flag2 = 1;
      }
    }
    if (flag1 == 0) {
      cnt1 = 1;
      ;
    }
    if (flag2 == 0) {
      cnt2 = 1;
    }
  }
  if (cnt2 == 1 && cnt1 == 1) {
    printf("-1\n");
  } else if (cnt2 == 1 && cnt1 == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map_[i][j] != 'E') {
          printf("%d %d\n", i + 1, j + 1);
          break;
        }
      }
    }
  } else if (cnt1 == 1 && cnt2 == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map_[j][i] != 'E') {
          printf("%d %d\n", j + 1, i + 1);
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (map_[j][i] != 'E') {
          printf("%d %d\n", j + 1, i + 1);
          break;
        }
      }
    }
  }
}
