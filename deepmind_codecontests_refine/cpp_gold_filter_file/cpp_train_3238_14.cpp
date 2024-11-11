#include <bits/stdc++.h>
using namespace std;
int n, v, k;
int a[200005];
int s0[200005];
int s1[200005];
int s2[200005];
int s3[200005];
int main() {
  scanf("%d", &n);
  int s = 0, id = -1, pre = -1e9 - 10;
  int cnt = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      s0[++cnt] = i;
    }
    if (a[i] < 0) {
      if (a[i] > pre) {
        pre = a[i];
        id = i;
      }
      s++;
    }
    if (a[i] != 0) s1[++cnt1] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (i != id) {
      s2[++cnt2] = i;
      if (a[i] != 0) s3[++cnt3] = i;
    }
  }
  if (s > 0 && s % 2 == 1) {
    if (cnt > 0) {
      for (int i = 1; i < cnt; i++) {
        printf("1 %d %d\n", s0[i], s0[i + 1]);
      }
      printf("1 %d %d\n", s0[cnt], id);
      if (cnt3 > 0) {
        printf("2 %d\n", id);
        for (int i = 1; i < cnt3; i++) {
          printf("1 %d %d\n", s3[i], s3[i + 1]);
        }
      }
    } else {
      printf("2 %d\n", id);
      for (int i = 1; i < cnt2; i++) {
        printf("1 %d %d\n", s2[i], s2[i + 1]);
      }
    }
    return 0;
  }
  for (int i = 1; i < cnt; i++) {
    printf("1 %d %d\n", s0[i], s0[i + 1]);
  }
  if (cnt == n) return 0;
  if (cnt > 0) printf("2 %d\n", s0[cnt]);
  for (int i = 1; i < cnt1; i++) {
    printf("1 %d %d\n", s1[i], s1[i + 1]);
  }
}
