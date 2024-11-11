#include <bits/stdc++.h>
using namespace std;
char s[1010];
int main() {
  int n;
  scanf("%d", &n);
  scanf(" %s", s);
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= n; ++j) {
      bool ok = 1;
      for (int k = 0; k < 5; ++k) {
        int t = i + j * k;
        if (t >= n || s[t] == '.') {
          ok = 0;
          break;
        }
      }
      if (ok) {
        puts("yes");
        return 0;
      }
    }
  }
  puts("no");
  return 0;
}
