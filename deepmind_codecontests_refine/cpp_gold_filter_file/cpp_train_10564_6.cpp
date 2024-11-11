#include <bits/stdc++.h>
using namespace std;
int a[100003], t[100003], r[100003], num[100003], b[100003];
int main() {
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int m, k;
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    int st = 0;
    for (int i = 1; i < m; i++) scanf("%d%d", &t[i], &r[i]);
    for (int i = 1; i < m; i++)
      if (r[i] == 1) {
        st = i;
        break;
      }
    if (st == 0) {
      for (int i = 1; i <= k; i++) num[i] = 0;
      int zero = 0;
      for (int i = 1; i < m; i++)
        if (t[i] == 0)
          zero++;
        else
          a[t[i]]--;
      for (int i = 1; i <= k; i++)
        if (zero >= a[i]) num[i] = 1;
      for (int i = 1; i <= k; i++)
        if (num[i])
          putchar('Y');
        else
          putchar('N');
    } else {
      for (int i = 1; i <= k; i++) num[i] = 0;
      int check = 0;
      int zero = 0;
      for (int i = 1; i < st; i++)
        if (t[i] == 0)
          zero++;
        else {
          a[t[i]]--;
          if (a[t[i]] == 0) check = 1;
        }
      if (check) {
        for (int i = st; i < m; i++)
          if (t[i] == 0)
            zero++;
          else
            a[t[i]]--;
        for (int i = 1; i <= k; i++)
          if (zero >= a[i]) num[i] = 1;
        for (int i = 1; i <= k; i++)
          if (num[i])
            putchar('Y');
          else
            putchar('N');
      } else {
        int zerof = zero;
        for (int i = 1; i <= k; i++) b[i] = 0;
        for (int i = st; i < m; i++)
          if (t[i] == 0)
            zero++;
          else
            b[t[i]]--;
        int min_value = 1000000;
        for (int i = 1; i <= k; i++)
          if (a[i] <= zerof && b[i] == 0) {
            num[i] = 1;
            if (a[i] < min_value) min_value = a[i];
          }
        for (int i = 1; i <= k; i++)
          if (a[i] + b[i] <= zero - min_value) num[i] = 1;
        for (int i = 1; i <= k; i++)
          if (num[i])
            putchar('Y');
          else
            putchar('N');
      }
    }
    puts("");
  }
  return 0;
}
