#include <bits/stdc++.h>
using namespace std;
long long comb[1001][1001];
int main() {
  for (int i = 0; i <= 1000; i++) {
    comb[i][i] = comb[i][0] = 1LL;
    for (int j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
      if (comb[i][j] >= 1000000007) comb[i][j] -= 1000000007;
    }
  }
  int cnt = 0;
  long long ans = 1LL;
  int x, k;
  cin >> k;
  while (k--) {
    cin >> x;
    ans *= comb[cnt + x - 1][cnt];
    ans %= 1000000007;
    cnt += x;
  }
  cout << ans;
  return 0;
}
