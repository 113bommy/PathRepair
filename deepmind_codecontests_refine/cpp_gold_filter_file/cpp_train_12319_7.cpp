#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 24) + 5, magic = 24;
int freq[N], dp[N], a[N];
string f(int x) {
  string ret = "";
  for (int j = 0; j <= magic; j++) {
    ret += x % 2 + '0';
    x /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = i;
  }
  for (int i = 1; i <= (1 << magic); i++) {
    if (dp[i]) continue;
    for (int j = 0; j <= magic; j++) {
      if (((i >> j) & 1) == 0) continue;
      int mask = i ^ (1 << j);
      if (dp[mask]) {
        dp[i] = dp[mask];
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int mask = ((1 << magic) - 1) ^ a[i];
    int ans = dp[mask];
    if (ans == 0) {
      printf("-1 ");
    } else {
      printf("%d ", a[ans]);
    }
  }
  return 0;
}
