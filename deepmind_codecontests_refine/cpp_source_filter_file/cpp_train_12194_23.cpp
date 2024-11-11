#include <bits/stdc++.h>
using namespace std;
const int N = 7005;
int n, q;
int main() {
  scanf("%d%d", &n, &q);
  vector<bitset<N>> to(N);
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < i + 1; j++) {
      if (i % j == 0) {
        to[i][j] = 1;
      }
    }
  }
  vector<bitset<N>> dp(N);
  for (int i = N - 1; i > 0; i--) {
    dp[i][i] = 1;
    for (int j = 2 * i; j < N; j += i) dp[i] ^= dp[j];
  }
  vector<bitset<N>> a(n);
  string ans;
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      x--;
      a[x] = to[v];
    }
    if (type == 2) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      x--;
      y--;
      z--;
      a[x] = a[y] ^ a[z];
    }
    if (type == 3) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      x--;
      y--;
      z--;
      a[x] = a[y] & a[z];
    }
    if (type == 4) {
      int x, v;
      scanf("%d%d", &x, &v);
      x--;
      int res = (a[x] & dp[v]).count();
      ans += '0' + res;
    }
  }
  cout << ans;
  return 0;
}
