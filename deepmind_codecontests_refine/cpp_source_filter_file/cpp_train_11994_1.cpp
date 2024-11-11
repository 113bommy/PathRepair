#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
char s[M];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    bool flag = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == s[i + 1] && s[i] != '?') {
        flag = 1;
        break;
      } else {
        if (s[i] == '?') {
          for (int j = 0; j < 3; j++) {
            if ('a' + j != s[i - 1] && 'a' + j != s[i + 1]) {
              s[i] = 'a' + j;
              break;
            }
          }
        }
      }
    }
    if (flag)
      puts("-1");
    else
      printf("%s\n", s + 1);
  }
  return 0;
}
