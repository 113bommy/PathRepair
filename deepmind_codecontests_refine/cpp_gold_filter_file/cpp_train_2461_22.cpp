#include <bits/stdc++.h>
using namespace std;
int n;
char d[706];
int f[2][706][2], A[706];
int main() {
  scanf("%s", d + 1);
  n = strlen(d + 1);
  for (int i = 1; i <= n; ++i) A[i] = d[i] - '0';
  int res = 0;
  for (int k = 1; k < 10; ++k) {
    memset(f[0], 0, sizeof f[0]);
    for (int i = 0; i < 10; ++i) f[0][i][0] = 1;
    int cur = 1, nxt = 0;
    for (int i = 0; i < n; ++i) {
      cur ^= 1, nxt ^= 1;
      memset(f[nxt], 0, sizeof f[nxt]);
      for (int j = 0; j <= i; ++j)
        for (int l = 0; l <= 1; ++l)
          for (int p = 0; p <= (l ? 9 : A[i + 1]); ++p)
            (f[nxt][j + (p >= k)][l | (p < A[i + 1])] += f[cur][j][l]) %=
                1000000007;
    }
    int c = 1;
    for (int i = 1; i <= n; ++i)
      (res += 1ll * (f[nxt][i][0] + f[nxt][i][1]) * c % 1000000007) %=
          1000000007,
          c = (10ll * c + 1) % 1000000007;
  }
  cout << res << endl;
}
