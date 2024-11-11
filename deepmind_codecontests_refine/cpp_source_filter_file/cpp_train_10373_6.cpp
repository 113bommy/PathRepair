#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
template <class T, class U>
inline void Max(T &a, U b) {
  if (a < b) a = b;
}
template <class T, class U>
inline void Min(T &a, U b) {
  if (a > b) a = b;
}
inline void add(int &a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
}
int pow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * (long long)a % 1000000007;
    a = (long long)a * a % 1000000007;
    b >>= 1;
  }
  return ans;
}
int f[1005], dp[1005][1005];
long long v[1005];
char s[1005];
int main() {
  int j, i, k, T, ca = 0, K = 0, m = 0, n;
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int k = 0; k < m; k++)
      if (s[k] == '1') {
        v[k] |= 1 << i;
      }
  }
  sort(v, v + m);
  dp[0][0] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < i + 1; j++) {
      add(dp[i + 1][j], 1LL * dp[i][j] * j % 1000000007);
      add(dp[i + 1][j + 1], dp[i][j]);
    }
  }
  for (int i = 1; i < m + 1; i++)
    for (int j = 1; j < i + 1; j++) add(f[i], dp[i][j]);
  int ans = 1;
  for (int i = 0; i < m; i++) {
    j = i;
    while (j < m && v[j] == v[i]) j++;
    ans = 1LL * ans * f[j - i] % 1000000007;
    i = j - 1;
  }
  printf("%d\n", ans);
  return 0;
}
