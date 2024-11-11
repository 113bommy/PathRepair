#include <bits/stdc++.h>
using namespace std;
int a[5010], b[5010];
char s[5010][10];
int main() {
  int n, i, ans = 0, j;
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%s%d%d", s[i], &a[i], &b[i]);
  for (i = 1; i <= 356; i++) {
    int male = 0, female = 0;
    for (j = 1; j <= n; j++)
      if (i >= a[j] && i <= b[j]) {
        if (s[j][0] == 'M')
          ++male;
        else
          ++female;
      }
    ans = max(ans, min(male, female) * 2);
  }
  cout << ans << endl;
  return 0;
}
