#include <bits/stdc++.h>
int main() {
  long long a1, b1, a2, b2;
  scanf("%I64d%I64d", &a1, &b1);
  long long all1 = a1 * b1;
  scanf("%I64d%I64d", &a2, &b2);
  long long all2 = a2 * b2;
  int cnt12 = 0, cnt13 = 0;
  while (all1 % 2 == 0) {
    all1 /= 2;
    cnt12++;
  }
  while (all1 % 3 == 0) {
    all1 /= 3;
    cnt13++;
  }
  int u12 = cnt12, u13 = cnt13;
  int cnt22 = 0, cnt23 = 0;
  while (all2 % 2 == 0) {
    all2 /= 2;
    cnt22++;
  }
  while (all2 % 3 == 0) {
    all2 /= 3;
    cnt23++;
  }
  int u22 = cnt22, u23 = cnt23;
  int ans = -1;
  if (all1 != all2) {
    printf("%d\n", ans);
  } else {
    if (cnt13 > cnt23) {
      ans = cnt13 - cnt23;
      cnt13 = cnt23;
      cnt12 += ans;
      if (cnt12 >= cnt22) {
        ans += cnt12 - cnt22;
        cnt12 = cnt22;
      } else {
        ans += cnt22 - cnt12;
        cnt22 = cnt12;
      }
    } else if (cnt13 == cnt23) {
      if (cnt12 > cnt22) {
        ans = cnt12 - cnt22;
        cnt12 = cnt22;
      } else if (cnt12 < cnt22) {
        ans = cnt22 - cnt12;
        cnt22 = cnt12;
      } else
        ans = 0;
    } else {
      ans = cnt23 - cnt13;
      cnt23 = cnt13;
      cnt22 += ans;
      if (cnt22 >= cnt12) {
        ans += cnt22 - cnt12;
        cnt22 = cnt12;
      } else {
        ans += cnt12 - cnt22;
        cnt12 = cnt22;
      }
    }
    printf("%d\n", ans);
    int tmp, tmp1, tmp2;
    tmp = u13 - cnt13;
    for (int i = 0; i < tmp; i++) {
      if (a1 % 3 == 0) {
        a1 /= 3;
        tmp1++;
      } else {
        b1 /= 3;
        tmp2++;
      }
    }
    if (cnt12 != u12) {
      if (cnt12 < u12) {
        tmp = u12 - cnt12;
        while (tmp) {
          if (a1 % 2 == 0)
            a1 /= 2;
          else
            b1 /= 2;
          tmp--;
        }
      } else {
        tmp = cnt12 - u12;
        for (int i = 0; i < tmp; i++) {
          if (tmp1) {
            a1 *= 2;
            tmp1--;
          } else
            b1 *= 2;
        }
      }
    }
    tmp = u23 - cnt23;
    for (int i = 0; i < tmp; i++) {
      if (a2 % 3 == 0) {
        a2 /= 3;
        tmp1++;
      } else {
        b2 /= 3;
        tmp2++;
      }
    }
    if (cnt22 != u22) {
      if (cnt22 < u22) {
        tmp = u22 - cnt22;
        while (tmp) {
          if (a2 % 2 == 0)
            a2 /= 2;
          else
            b2 /= 2;
          tmp--;
        }
      } else {
        tmp = cnt22 - u22;
        for (int i = 0; i < tmp; i++) {
          if (tmp1) {
            a2 *= 2;
            tmp1--;
          } else
            b2 *= 2;
        }
      }
    }
    printf("%I64d %I64d\n", a1, b1);
    printf("%I64d %I64d\n", a2, b2);
  }
  return 0;
}
