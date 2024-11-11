#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[205];
  int a[129], n;
  memset(a, 0, sizeof(a));
  scanf("%d%s", &n, s);
  int ans = 0;
  int mx = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      int j;
      for (j = i + 1; j < strlen(s); j++) {
        if (s[j] >= 'a' && s[j] <= 'z') {
          if (a[s[j]] == 0) ans++;
          a[s[j]] = 1;
        } else
          break;
      }
      if (ans > mx) mx = ans;
      ans = 0;
      i = j;
      memset(a, 0, sizeof(a));
    }
  }
  printf("%d\n", mx);
}
