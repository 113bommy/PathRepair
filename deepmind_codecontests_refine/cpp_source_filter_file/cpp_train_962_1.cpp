#include <bits/stdc++.h>
using namespace std;
void IO() {}
int ar[200005];
int m, n, k, ii;
void solve() {
  int cnt[32] = {0};
  scanf("%d", &n);
  int bit = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
    bit ^= ar[i];
    for (int j = 0; j < 30; j++) {
      if ((ar[i] & (1 << j)) == (1 << j)) {
        cnt[j]++;
      }
    }
  }
  if (bit == 0) {
    printf("DRAW\n");
    return;
  }
  for (int i = 29; i >= 0; i--) {
    if (cnt[i] % 2 == 1) {
      int one = cnt[i];
      int zero = n - one;
      if (one % 4 == 3 && zero % 2 == 0)
        printf("LOSS\n");
      else
        printf("WIN\n");
      return;
    }
  }
}
int main() {
  IO();
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
