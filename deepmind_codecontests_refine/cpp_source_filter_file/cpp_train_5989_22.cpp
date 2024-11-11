#include <bits/stdc++.h>
using namespace std;
const int N = 100;
char s[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt1 = 0, cnt2 = 0;
    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'C') cnt1++;
      if (s[j][i] == 'C') cnt2++;
    }
    ans += (cnt1 - 1) * cnt2 / 2;
    ans += (cnt2 - 1) * cnt2 / 2;
  }
  printf("%d\n", ans);
  return 0;
}
