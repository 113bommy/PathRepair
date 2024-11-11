#include <bits/stdc++.h>
using namespace std;
int n, m, s, f;
int t, l, r;
int tt, now;
void deal() {
  if (f > s) {
    now++;
    printf("R");
  } else {
    now--;
    printf("L");
  }
}
void work() {
  tt = 1;
  now = s;
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &t, &l, &r);
    if (now == f) continue;
    for (int i = tt + 1; i < t; i++) {
      if (now == f) break;
      deal();
    }
    if (now == f) continue;
    if (f > s) {
      if ((now >= l && now <= r) || ((now + 1) >= l && (now + 1) <= r)) {
        printf("X");
      } else {
        deal();
      }
    } else {
      if ((now >= l && now <= r) || ((now - 1) >= l && (now - 1) <= r)) {
        printf("X");
      } else {
        deal();
      }
    }
    tt = t;
  }
  while (now != f) {
    deal();
  }
  printf("\n");
}
int main() {
  while (scanf("%d %d %d %d", &n, &m, &s, &f) != EOF) {
    work();
  }
  return 0;
}
