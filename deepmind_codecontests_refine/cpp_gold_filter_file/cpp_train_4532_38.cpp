#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long double EPS = 1e-9;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 3;
const int base = 1000 * 1000 * 1000;
int arr[15][15];
int func(int a, int b, int c, int d) {
  int cnt = 0;
  for (int m = a; m <= c; m++)
    for (int n = b; n <= d; n++)
      if (arr[m][n] == 1) cnt++;
  return cnt;
}
int main() {
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  for (int i = 1; i <= n; i++) {
    int first, second;
    cin >> first >> second;
    arr[first][second] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      for (int m = i; m <= r; m++) {
        for (int l = j; l <= c; l++) {
          if (func(i, j, m, l) >= k) ans++;
        }
      }
    }
  }
  cout << ans;
}
