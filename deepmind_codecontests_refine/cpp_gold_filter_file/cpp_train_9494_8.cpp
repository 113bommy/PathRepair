#include <bits/stdc++.h>
using namespace std;
int book[3];
char s[105], rs[105];
int main() {
  int t, ans, n;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    ans = 0;
    memset(rs, '\0', sizeof(rs));
    for (int i = 0; i < 3; i++) {
      scanf("%d", &book[i]);
    }
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R') {
        if (book[1] > 0) {
          ans++;
          book[1]--;
          rs[i] = 'P';
        }
      } else if (s[i] == 'P') {
        if (book[2] > 0) {
          ans++;
          book[2]--;
          rs[i] = 'S';
        }
      } else {
        if (book[0] > 0) {
          ans++;
          book[0]--;
          rs[i] = 'R';
        }
      }
    }
    if (ans >= (n + 1) / 2) {
      int k = 0;
      for (int i = 0; i < n; i++) {
        if (rs[i] == '\0') {
          while (book[k] == 0) k++;
          if (k == 0)
            rs[i] = 'R';
          else if (k == 1)
            rs[i] = 'P';
          else
            rs[i] = 'S';
          book[k]--;
        }
      }
      printf("YES\n%s\n", rs);
    } else
      printf("NO\n");
  }
  return 0;
}
