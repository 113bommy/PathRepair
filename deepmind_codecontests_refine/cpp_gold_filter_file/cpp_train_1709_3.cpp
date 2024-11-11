#include <bits/stdc++.h>
using namespace std;
long long f[2222][2222], sum[2222];
char s[2222];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  f[0][0] = 1;
  sum[0] = 1;
  for (int i = 1, _b = n; i <= _b; i++)
    for (int j = 0, _b = k; j <= _b; j++) {
      f[i][j] = (f[i][j] + 1LL * sum[j] * (s[i - 1] - 'a')) % 1000000007LL;
      for (int pref = 0, _b = i - 1; pref <= _b; pref++) {
        if (j - (1 + pref) * (n - i + 1) < 0) break;
        f[i][j] =
            (f[i][j] + 1LL * f[i - pref - 1][j - (1 + pref) * (n - i + 1)] *
                           ('z' - s[i - 1])) %
            1000000007LL;
      }
      sum[j] = (sum[j] + f[i][j]) % 1000000007LL;
    }
  long long res = 0;
  for (int i = 0, _b = n; i <= _b; i++) res = (res + f[i][k]) % 1000000007LL;
  cout << res << endl;
  return 0;
}
