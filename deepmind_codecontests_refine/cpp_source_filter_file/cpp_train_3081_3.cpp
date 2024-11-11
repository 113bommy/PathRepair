#include <bits/stdc++.h>
using namespace std;
int main() {
  char chess[10][10];
  for (int i = 0; i < 8; i++) scanf("%s", chess[i]);
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < 8; j++) {
      if (chess[i][j] == 'B') cnt1++;
      if (chess[j][i] == 'B') cnt2++;
    }
    if (cnt1 == 8) ans++;
    if (cnt2 == 8) ans++;
  }
  if (ans > 8) ans = 8;
  printf("%d\n", ans);
}
