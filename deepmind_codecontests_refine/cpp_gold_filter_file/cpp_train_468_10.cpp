#include <bits/stdc++.h>
char in[500100];
int vl[500100];
int vr[500100];
int main() {
  int n, a, b, T;
  int vrl, vll;
  scanf("%d%d%d%d", &n, &a, &b, &T);
  getchar();
  scanf("%s", in + 1);
  if (in[1] == 'w') T -= b;
  T--;
  if (T < 0) {
    printf("0\n");
    return 0;
  } else {
    vr[0] = 0;
    for (int i = 2; i <= n; i++) {
      int x = (in[i] == 'w') * b;
      x += (a + 1);
      vr[i - 1] = vr[i - 2] + x;
    }
    vl[0] = 0;
    for (int i = n; i > 1; i--) {
      int x = (in[i] == 'w') * b;
      x += (a + 1);
      vl[n - i + 1] = vl[n - i] + x;
    }
    if (vr[n - 1] < T || vl[n - 1] < T) {
      printf("%d\n", n);
      return 0;
    }
    int ans = 1;
    vrl = n, vll = n;
    for (int i = 1; i <= vrl; i++) {
      int tans = i + 1;
      int lt = T - vr[i];
      if (lt < 0) {
        break;
      } else if (lt == 0) {
        ans = ans > tans ? ans : tans;
        break;
      } else {
        ans = ans > tans ? ans : tans;
        lt -= (a * i);
        if (lt <= 0) continue;
        int l = 0, r = vll;
        while (r - l > 1) {
          int mid = (l + r) >> 1;
          if (vl[mid] <= lt) {
            l = mid;
          } else
            r = mid;
        }
        tans += l;
        ans = ans > tans ? ans : tans;
      }
    }
    for (int i = 1; i <= vll; i++) {
      int tans = i + 1;
      int lt = T - vl[i];
      if (lt < 0) {
        break;
      } else if (lt == 0) {
        ans = ans > tans ? ans : tans;
        break;
      } else {
        ans = ans > tans ? ans : tans;
        lt -= (a * i);
        if (lt <= 0) continue;
        int l = 0, r = vrl;
        while (r - l > 1) {
          int mid = (l + r) >> 1;
          if (vr[mid] <= lt) {
            l = mid;
          } else
            r = mid;
        }
        tans += l;
        ans = ans > tans ? ans : tans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
