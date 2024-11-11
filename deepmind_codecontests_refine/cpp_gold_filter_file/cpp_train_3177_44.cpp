#include <bits/stdc++.h>
using namespace std;
int main() {
  bool ok[10];
  int cnt = 0, help;
  memset(ok, true, sizeof ok);
  int x[10], a[10];
  for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 3; i++) scanf("%d", &x[i]);
  for (int i = 0; i < 3; i++) {
    if (x[i] > a[i]) {
      ok[i] = false;
      cnt++;
    }
  }
  if (cnt == 3) {
    printf("NO\n");
    return 0;
  }
  if (cnt == 0) {
    printf("YES\n");
    return 0;
  }
  if (cnt == 2) {
    for (int i = 0; i < 3; i++)
      if (ok[i]) {
        help = i;
        break;
      }
    int need = 0;
    for (int i = 0; i < 3; i++) {
      if (!ok[i]) {
        need += a[i] - x[i];
      }
    }
    need *= -2;
    if (a[help] - need >= x[help]) {
      printf("YES\n");
      return 0;
    } else {
      printf("NO\n");
      return 0;
    }
  }
  if (cnt == 1) {
    int p = 0, q = 0;
    for (int i = 0; i < 3; i++) {
      if (!ok[i]) {
        p = -(a[i] - x[i]);
        break;
      }
    }
    for (int i = 0; i < 3; i++) {
      if (ok[i]) {
        q += (a[i] - x[i]) / 2;
      }
    }
    if (p <= q) {
      printf("YES\n");
      return 0;
    } else {
      printf("NO\n");
      return 0;
    }
  }
}
