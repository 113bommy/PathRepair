#include <bits/stdc++.h>
using namespace std;
template <typename T>
void showArray(const T *arr, int sz) {
  for (int i = 0; i < sz; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}
int readInt() {
  int ret = 0, k = 1;
  char c = getchar();
  if (c == '-') {
    k = -1;
  } else {
    ret = c - '0';
  }
  c = getchar();
  while (c != ' ' && c != '\n') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return k * ret;
}
const bool debug = false;
const int MAXN = 205, INF = 1e9;
const long long LLINF = 1e18;
const double pi = acos(-1);
int n, k, x;
long long a[MAXN], dp[MAXN][MAXN], ans = -1;
int main() {
  for (int i = 0; i < MAXN; ++i) fill(dp[i], dp[i] + MAXN, -LLINF);
  scanf("%d %d %d", &n, &k, &x);
  if (x < n / k) {
    printf("-1\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int j = 0; j < k; ++j) {
    dp[1][j] = a[j];
  }
  for (int i = 2; i <= x; ++i) {
    for (int j = i - 1; j < n; ++j) {
      for (int t = max(0, j - k); t < j; ++t) {
        if (dp[i - 1][t] == -LLINF) continue;
        dp[i][j] = max(dp[i][j], dp[i - 1][t] + a[j]);
      }
    }
  }
  for (int j = x - 1; j < n; ++j) {
    ans = max(ans, dp[x][j]);
  }
  cout << ans << endl;
  return 0;
}
