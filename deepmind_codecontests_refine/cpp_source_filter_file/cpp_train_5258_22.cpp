#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, cnt, cnt1, cnt2, t1, t2;
  scanf("%d", &n);
  scanf("%d", &t);
  char a[n], b[n], res[n + 1];
  scanf("%s", a);
  scanf("%s", b);
  for (long long int i = 0; i < n; ++i) {
    res[i] = '.';
  }
  res[n] = '\0';
  cnt = n - t;
  for (long long int i = 0; i < n; ++i) {
    if (cnt == 0) {
      break;
    }
    if (a[i] == b[i]) {
      res[i] = a[i];
      cnt--;
    }
  }
  t1 = 0;
  t2 = 0;
  if (cnt > 0) {
    cnt1 = cnt2 = cnt;
    for (long long int i = 0; i < n; ++i) {
      if (res[i] == '.') {
        if (cnt1 > cnt2) {
          res[i] = a[i];
          cnt1--;
          t2++;
        } else {
          res[i] = b[i];
          cnt2--;
          t1++;
        }
      }
      if (cnt1 == 0 && cnt2 == 0) {
        break;
      }
    }
  }
  for (long long int i = 0; i < n; ++i) {
    if (res[i] == '.') {
      for (char c = 'a'; c <= 'z'; c++) {
        if (c != a[i] && c != b[i]) {
          res[i] = c;
          t1++;
          t2++;
          break;
        }
      }
    }
  }
  if (t1 != t || t2 != t) {
    printf("%s", "-1\n");
    return 0;
  }
  printf("%s", res);
  printf("\n");
  return 0;
}
