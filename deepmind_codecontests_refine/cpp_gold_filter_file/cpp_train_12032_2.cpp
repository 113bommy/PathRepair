#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  char c;
  bool fu = 0;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x *= -1;
}
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x, y);
  read(z);
}
const int N = 22;
long long jc[N], dp[N][N];
int a[N], k;
long long C(int n, int m) { return jc[n] / jc[m] / jc[n - m]; }
long long get(int L) {
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int _tmp = 15, i = 0; i <= _tmp; ++i)
    for (int _tmp = a[i], j = 0; j <= _tmp; ++j)
      for (int _tmp = L - j, k = 0; k <= _tmp; ++k)
        dp[i + 1][k + j] += dp[i][k] * C(L - k, j);
  return dp[16][L];
}
long long n;
int wei, ans[N];
int main() {
  read(n);
  read(k);
  n--;
  jc[0] = 1;
  for (int _tmp = 20, i = 1; i <= _tmp; ++i) jc[i] = jc[i - 1] * i;
  for (int _tmp = 15, i = 0; i <= _tmp; ++i) a[i] = k;
  wei = 1;
  a[0]--;
  while (1) {
    long long tmp = get(wei - 1) * 15;
    if (n >= tmp)
      n -= tmp;
    else
      break;
    ++wei;
  }
  a[0]++;
  for (int _tmp = 1, i = wei; i >= _tmp; --i) {
    for (int _tmp = 15, j = i == wei; j <= _tmp; ++j)
      if (a[j]) {
        a[j]--;
        long long tmp = get(i - 1);
        if (n >= tmp)
          n -= tmp;
        else {
          ans[wei - i + 1] = j;
          break;
        }
        a[j]++;
      }
  }
  for (int _tmp = wei, i = 1; i <= _tmp; ++i) {
    if (ans[i] < 10)
      printf("%d", ans[i]);
    else
      printf("%c", ans[i] - 10 + 'a');
  }
  return 0;
}
