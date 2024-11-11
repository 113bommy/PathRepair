#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
const long long base = 1e9 + 7;
int n, k;
long long f[N][N], fSum[N][N];
char s[N + 1];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  cin >> s + 1;
  f[0][0] = 1;
  fSum[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k; j++) {
      f[i][j] = (fSum[i - 1][j] * (s[i] - 'a')) % base;
      for (int equa = 1; equa <= i; equa++) {
        if (j - equa * (n - i + 1) < 0) break;
        f[i][j] =
            (f[i][j] + f[i - equa][j - equa * (n - i + 1)] * ('z' - s[i])) %
            base;
      }
      fSum[i][j] = fSum[i - 1][j] + f[i][j];
    }
  long long res = 0;
  for (int i = 1; i <= n; i++) res = (res + f[i][k]) % base;
  cout << res << endl;
  return 0;
}
