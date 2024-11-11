#include <bits/stdc++.h>
using namespace std;
string s[1005];
int main() {
  int i, j, k;
  int n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) cin >> s[i];
  int ans = n;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      int temp = 0;
      for (k = 0; k < 6; k++) {
        if (s[i][k] != s[j][k]) temp++;
      }
      ans = min(ans, (temp - 1) / 2);
    }
  }
  printf("%d\n", ans);
  return 0;
}
