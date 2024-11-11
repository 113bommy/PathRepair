#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, s[1002];
  scanf("%d %d", &n, &d);
  for (int i = 0; i < n; i++) scanf("%d", s + i);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i] - s[j] <= d && s[j] - s[i] <= d) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
