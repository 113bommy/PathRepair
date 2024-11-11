#include <bits/stdc++.h>
using namespace std;
const int MX = 2e6 + 10;
const int mod = 1e9 + 7;
const long long int inf = 1LL << 62;
int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int main() {
  long long int arr[110][110];
  long long int n, m, k, q, t, cnt = 0, sum = 0, ans = 0, mx = -inf, mn = inf,
                               a, b, c, d, e, f, g, h, i, j, x, y, z, temp,
                               temp1;
  string s, s1, s2, s3;
  cin >> n;
  for (int i = 0; i < 105; i++) {
    for (int j = 0; j < 105; j++) {
      arr[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    for (x = a; x <= c; x++) {
      for (y = b; y <= d; y++) {
        arr[x][y]++;
      }
    }
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j < 100; j++) {
      sum += arr[i][j];
    }
  }
  cout << sum << endl;
  return 0;
}
