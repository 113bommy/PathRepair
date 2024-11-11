#include <bits/stdc++.h>
using namespace std;
int cnt[305];
int query(int l, int r) {
  int resp;
  printf("? %d %d\n", l, r);
  fflush(stdout);
  scanf("%d", &resp);
  return resp;
}
int main() {
  int n, last, temp;
  int rec[2];
  scanf("%d", &n);
  scanf("%d", &cnt[n]);
  if (n == 1) {
    printf("! %d\n", cnt[1]);
    fflush(stdout);
    return 0;
  }
  if (n & 1) {
    rec[0] = rec[1] = 0;
    last = cnt[n];
    while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
      temp = query(2, n);
      if ((temp + last) % 2 == 0)
        rec[0]++;
      else
        rec[1]++;
      last = temp;
    }
    cnt[1] = (n - 1 + cnt[n] - last) / 2;
    rec[0] = rec[1] = 0;
    while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
      temp = query(2, n);
      if ((temp + last) % 2 == 0)
        rec[0]++;
      else
        rec[1]++;
      last = temp;
    }
    cnt[1] = cnt[n] - cnt[1];
    for (int i = 2; i < n; i++) {
      rec[0] = rec[1] = 0;
      last = cnt[n];
      while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
        temp = query(i - 1, i);
        if ((temp + last) % 2 == i % 2)
          rec[0]++;
        else
          rec[1]++;
        last = temp;
      }
      cnt[i] = (i + cnt[n] - last) / 2;
      rec[0] = rec[1] = 0;
      while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
        temp = query(i - 1, i);
        if ((temp + last) % 2 == i % 2)
          rec[0]++;
        else
          rec[1]++;
        last = temp;
      }
    }
    cnt[0] = 0;
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d", cnt[i] - cnt[i - 1]);
    printf("\n");
    fflush(stdout);
  } else {
    for (int i = 1; i < n; i++) {
      rec[0] = rec[1] = 0;
      last = cnt[n];
      while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
        temp = query(i, i);
        if ((temp + last) % 2 == i % 2)
          rec[0]++;
        else
          rec[1]++;
        last = temp;
      }
      cnt[i] = (i + cnt[n] - last) / 2;
      rec[0] = rec[1] = 0;
      while (!(rec[0] % 2 == 1 && rec[1] % 2 == 0)) {
        temp = query(i, i);
        if ((temp + last) % 2 == i % 2)
          rec[0]++;
        else
          rec[1]++;
        last = temp;
      }
    }
    cnt[0] = 0;
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d", cnt[i] - cnt[i - 1]);
    printf("\n");
    fflush(stdout);
  }
  return 0;
}
