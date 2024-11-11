#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
const long long MOD = 1000000007;
const int INF = 1000000000;
const int MAXN = 200005;
const double EPS = 1e-10;
const int HASH_POW = 7;
const double PI = acos(-1.0);
using namespace std;
void my_return(int code) { exit(code); }
int n, T;
int w[110][1010], cnt[110];
int dp[110][1010];
int main() {
  mt19937 mt_rand(time(NULL));
  scanf("%d %d", &n, &T);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    w[T - x][cnt[T - x]++] = y;
  }
  for (int i = T - 1; i >= 0; --i) {
    for (int j = 1; j <= (n + 1) / 2; ++j)
      dp[i][j] = max(dp[i + 1][2 * j], dp[i + 1][2 * j - 1]);
    for (int k = 0; k < cnt[i]; ++k) {
      for (int j = n - 1; j >= 0; --j)
        dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + w[i][k]);
    }
  }
  printf("%d\n", dp[0][1]);
  my_return(0);
}
