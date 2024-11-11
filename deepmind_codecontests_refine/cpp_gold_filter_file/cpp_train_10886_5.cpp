#include <bits/stdc++.h>
using namespace std;
char s[200005];
int main() {
  int n, i;
  while (scanf("%d", &n) != EOF) {
    int cnt = 0;
    int r = 0, l = 0, u = 0, d = 0;
    scanf("%s", s);
    for (i = 0; i < n; i++) {
      if (s[i] == 'R') {
        if (l > 0) {
          cnt++;
          u = l = r = d = 0;
        }
        r++;
      }
      if (s[i] == 'L') {
        if (r > 0) {
          cnt++;
          u = l = r = d = 0;
        }
        l++;
      }
      if (s[i] == 'U') {
        if (d > 0) {
          cnt++;
          u = l = r = d = 0;
        }
        u++;
      }
      if (s[i] == 'D') {
        if (u > 0) {
          cnt++;
          u = l = r = d = 0;
        }
        d++;
      }
    }
    printf("%d\n", ++cnt);
  }
  return 0;
}
