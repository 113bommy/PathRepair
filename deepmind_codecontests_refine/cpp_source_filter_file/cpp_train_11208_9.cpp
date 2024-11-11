#include <bits/stdc++.h>
using namespace std;
int n;
char s[109];
int cnt;
int ans;
int main() {
  scanf("%d\n", &n);
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x')
      cnt++;
    else {
      if (cnt >= 3) ans += cnt - 2;
      cnt = 0;
    }
  }
  if (cnt > 3) ans += cnt - 2;
  printf("%d", ans);
  return 0;
}
