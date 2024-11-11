#include <bits/stdc++.h>
using namespace std;
char str[300];
int main() {
  int n;
  scanf("%s", str);
  scanf("%d", &n);
  int len = strlen(str);
  if (len <= n) {
    printf("%d\n", (len + n) / 2 * 2);
  } else {
    int ans = 2 * n;
    for (int least = n / 2; least <= len / 2; ++least) {
      for (int i = 0; i + least * 2 <= len; ++i) {
        bool flag = true;
        for (int j = i; j < i + least; ++j) {
          if (str[j] != str[j + least]) {
            flag = false;
            break;
          }
        }
        if (flag) {
          if (ans < 2 * least) ans = 2 * least;
        }
      }
    }
    int len1, len2;
    for (len1 = 1; len1 <= (len - n) / 2; ++len1) {
      for (len2 = ans / 2 - len1 + 1; len2 <= n; ++len2) {
        int id_start = len - (2 * len1 + len2);
        int i;
        for (i = 0; i < len1; ++i) {
          if (str[id_start + i] == str[id_start + i + len1 + len2])
            continue;
          else
            break;
        }
        if (i >= len1) {
          ans = 2 * (len1 + len2);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
