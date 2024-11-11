#include <bits/stdc++.h>
using namespace std;
int n;
char promocode[1100][10];
int strdif(char a[], char b[]) {
  int cnt = 0;
  for (int ii = 0; ii < 6; ii++) {
    if (a[ii] != b[ii]) cnt++;
  }
  return cnt;
}
int main() {
  scanf("%d\n", &n);
  for (int ii = 1; ii <= n; ii++) {
    scanf("%s", promocode[ii]);
  }
  int ans = 6;
  for (int ii = 1; ii <= n - 1; ii++) {
    for (int jj = ii + 1; jj <= n; jj++) {
      ans = min(ans, (strdif(promocode[ii], promocode[jj]) - 1) / 2);
    }
  }
  printf("%d\n", ans);
}
