#include <bits/stdc++.h>
using namespace std;
void PLAY() {
  cout << fixed << setprecision(10);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
long long fx4[] = {-1, 1, 0, 0};
long long fy4[] = {0, 0, -1, 1};
long long fx8[] = {-1, -1, -1, 0, 1, 1, 1, 0};
long long fy8[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const double PI = 3.141592653589793;
const long long N = 2e2 + 5;
const long long mod = 1000000007;
long long n, m, k, x, y;
long long arr[N][N];
void work() {
  if (n == 1) {
    long long tot = k / m, rem = k % m;
    for (long long j = 1; j <= m; j++) arr[1][j] += tot;
    for (long long j = 1; j <= rem; j++) arr[1][j]++;
  } else {
    long long period = n * m + (n - 2) * m;
    long long tot = k / period;
    k = k % period;
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (i == 1 || i == n)
          arr[i][j] += tot;
        else
          arr[i][j] += 2 * tot;
      }
    }
    for (long long i = 1; i <= n && k > 0; i++) {
      for (long long j = 1; j <= m && k > 0; j++) {
        arr[i][j]++;
        k--;
      }
    }
    for (long long i = n - 1; i >= 1 && k > 0; i--) {
      for (long long j = 1; j <= m && k > 0; j++) {
        arr[i][j]++;
        k--;
      }
    }
  }
}
int32_t main() {
  PLAY();
  cin >> n >> m >> k >> x >> y;
  work();
  long long mini = 1e18;
  long long maxi = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      maxi = max(maxi, arr[i][j]);
      mini = min(mini, arr[i][j]);
    }
  }
  cout << maxi << " " << mini << " " << arr[x][y];
}
