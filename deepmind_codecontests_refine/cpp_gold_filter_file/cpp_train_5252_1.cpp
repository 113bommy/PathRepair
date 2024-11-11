#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, num, ans;
  scanf("%d", &n);
  char in[n + 1][10];
  for (i = 1; i <= n; i++) {
    scanf("%s", in[i]);
  }
  int cnt[3];
  for (i = 0; i <= 2; i++) cnt[i] = 0;
  for (i = 1; i <= n; i++) {
    num = 0;
    j = 0;
    while (in[i][j] != '\0') {
      num += (in[i][j] - 48);
      j++;
    }
    cnt[num % 3]++;
  }
  if (cnt[1] > cnt[2])
    ans = cnt[2];
  else
    ans = cnt[1];
  ans += cnt[0] / 2;
  printf("%d", ans);
}
