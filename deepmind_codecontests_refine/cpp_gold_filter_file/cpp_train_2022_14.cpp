#include <bits/stdc++.h>
using namespace std;
int bit[24 + 1], cnt[1 << 24];
int main() {
  int n, i, j, x, rlt;
  char s[5];
  bit[0] = 1;
  for (i = 1; i <= 24; i++) bit[i] = bit[i - 1] * 2;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s);
    for (x = j = 0; s[j]; j++) x |= bit[s[j] - 'a'];
    cnt[x]++;
  }
  rlt = 0;
  for (j = 0; j < 24; j++)
    for (i = 0; i < bit[24]; i++)
      if (i & bit[j]) cnt[i] += cnt[i - bit[j]];
  for (i = 0; i < bit[24]; i++) rlt ^= (n - cnt[i]) * (n - cnt[i]);
  printf("%d\n", rlt);
}
