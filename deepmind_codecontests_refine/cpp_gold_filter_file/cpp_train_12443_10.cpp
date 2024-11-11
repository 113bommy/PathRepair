#include <bits/stdc++.h>
using namespace std;
const int N = 60;
int a[N], b[N];
long long dp[N][2];
long long f(int p, int c) {
  if (p == N) return c == 0;
  long long &ret = dp[p][c];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 0; i < 2; ++i)
    for (int j = 0; j < 2; ++j)
      if ((i ^ j ^ c) == a[p] && (i ^ j) == b[p])
        ret += f(p + 1, i + j + c > 1);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  long long s, x;
  cin >> s >> x;
  for (int i = 0; i < N; ++i) {
    a[i] = (s >> i & 1);
    b[i] = (x >> i & 1);
  }
  memset(dp, -1, sizeof dp);
  cout << f(0, 0) - (s == x) * 2 << "\n";
  return 0;
}
