#include <bits/stdc++.h>
using namespace std;
int n;
char s[109];
int cnt[109];
int ans;
int main() {
  scanf("%d\n", &n);
  scanf("%s", s);
  int len = strlen(s);
  if (s[0] = 'x') cnt[0] = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == 'x') cnt[i] = cnt[i - 1] + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (cnt[i] >= 3) {
      ans += cnt[i] - 2;
      i -= cnt[i];
    }
  }
  printf("%d", ans);
  return 0;
}
