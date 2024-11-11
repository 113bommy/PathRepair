#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e18;
const long long maxn = 1e5 + 100;
int main(int argc, char const *argv[]) {
  char s[100];
  while (~scanf("%s", s + 1)) {
    int n;
    scanf("%d", &n);
    char s1[100];
    bool flag = false;
    for (int k = 1; k <= n; k++) {
      scanf("%s", s1 + 1);
      int len = strlen(s1 + 1);
      int i, j;
      for (i = 1, j = 1; j <= len; j++) {
        if ((s[i] - 'a' == s1[j] - 'A') || (s[i] - 'A' == s1[j] - 'a')) {
          i++;
          continue;
        }
        if (s1[j] == s[i]) {
          i++;
          continue;
        } else {
          if ((s[i] == '0' || s[i] == 'o' || s[i] == 'O') &&
              (s1[j] == '0' || s1[j] == 'o' || s1[j] == 'O')) {
            i++;
          } else if ((s[i] == '1' || s[i] == 'i' || s[i] == 'I' ||
                      s[i] == 'L' || s[i] == 'l') &&
                     (s1[j] == '1' || s1[j] == 'i' || s1[j] == 'I' ||
                      s1[j] == 'L' || s1[j] == 'l')) {
            i++;
          } else {
            break;
          }
        }
      }
      if (i - 1 == len) {
        flag = true;
      }
    }
    if (flag) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
  return 0;
}
