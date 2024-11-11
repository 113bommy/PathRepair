#include <bits/stdc++.h>
using namespace std;
int n, r[20], b[20];
char ch[20];
long long dp[(1 << 16)][260];
long long dfs(int bit, int discount) {
  long long& ret = dp[bit][discount];
  if (ret != -1) return ret;
  if (bit == (1 << n) - 1) {
    return ret = 0;
  }
  ret = 0xffffffffffffff;
  int Rcard = 0, Bcard = 0, cnt = 0;
  ;
  long long Rused = 0, Bused = 0;
  for (int i = 0; i < n; i++) {
    if (bit & (1 << i)) {
      ++cnt;
      Rused += r[i];
      Bused += b[i];
      if (ch[i] == 'R')
        ++Rcard;
      else
        Bcard++;
    }
  }
  int gap = discount - 120;
  long long remainR = 0, remainB = 0;
  if (gap > 0)
    Rused -= gap;
  else
    Bused -= gap;
  if (Rused > Bused) {
    remainB = Rused - Bused;
  } else {
    remainR = Bused - Rused;
  }
  for (int i = 0; i < n; i++) {
    if (!(bit & (1 << i))) {
      long long maxi = max((long long)(r[i] - Rcard - remainR),
                           (long long)(b[i] - Bcard - remainB));
      maxi = max(maxi, (long long)0);
      long long discountR = min(r[i], Rcard);
      long long discountB = min(b[i], Bcard);
      long long go = dfs(bit | (1 << i), discount + discountR - discountB);
      ret = min(ret, go + maxi);
    }
  }
  return ret;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> ch[i];
    scanf("%d %d", &r[i], &b[i]);
  }
  long long ans = dfs(0, 120);
  ans += n;
  cout << ans;
}
