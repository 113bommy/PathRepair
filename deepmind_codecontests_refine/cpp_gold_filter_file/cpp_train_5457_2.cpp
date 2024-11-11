#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
char s[N];
int a[N][N];
int dp[N][N];
int b[N];
bool cmp(int x, int y) { return x > y; }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++) a[i][j] = s[j] - '0';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        dp[j][i] += dp[j - 1][i] + 1;
      }
    }
  }
  int Max = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      b[j] = dp[i][j];
    }
    sort(b + 1, b + 1 + n);
    for (int k = n; k >= 1; k--) {
      if (b[k] == 0) break;
      Max = max(Max, b[k] * (n - k + 1));
    }
  }
  cout << Max << endl;
}
