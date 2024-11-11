#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
char c[509][509];
long long int arr[509][509], brr[509], crr[509];
std::vector<long long int> v[509];
long long int a1[] = {1, -1, 0, 0};
long long int b1[] = {0, 0, 1, -1};
long long int solve(long long int i, long long int j, long long int n,
                    long long int m) {
  if (c[i][j] == '0') return 0;
  for (int k = 0; k < 4; k++) {
    long long int x = a1[k] + i;
    long long int y = b1[k] + j;
    if (x >= 0 && x < n && y >= 0 && y < m && c[x][y] == '1') {
    } else
      return 0;
  }
  return 1;
}
int main() {
  int test_case = 1;
  for (int cs = 1; cs <= test_case; cs++) {
    long long int n, m, kk;
    scanf("%lld %lld %lld", &n, &m, &kk);
    for (int i = 0; i < n; i++) {
      scanf("%s", &c[i]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        arr[i + 1][j + 1] = arr[i + 1][j] + solve(i, j, n, m);
      }
    }
    long long int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = i + 2; j < m; j++) {
        for (int k = 0; k <= n; k++) crr[k] = 0;
        long long int lst = 0;
        long long int lstdn = 0;
        for (int k = 0; k < n; k++) {
          lst += arr[k][j] - arr[k][i + 1];
          crr[k + 1] = lst;
          while (lstdn + 3 < k && (lst - crr[lstdn + 3]) >= kk) lstdn++;
          if (lst >= kk) {
            ans += lstdn + 1;
          }
        }
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
