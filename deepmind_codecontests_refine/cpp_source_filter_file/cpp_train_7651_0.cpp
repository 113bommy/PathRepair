#include <bits/stdc++.h>
using namespace std;
long long int i, j, ft;
long long int a[32][32][32];
long long int solve(long long int x, long long int y, long long int k) {
  if (k == 0) return 0;
  if (x * y == k) return 0;
  if (a[x][y][k]) return a[x][y][k];
  long long int i = 0;
  long long int sum = 1e9;
  for (i = 0; i < (x - 1); i++) {
    long long int j = 0;
    for (j = 0; j < (k + 1); j++) {
      if (((i + 1) * y >= j) && ((x - i - 1) * y >= (k - j)))
        sum = min(sum, solve(i + 1, y, j) + solve(x - i - 1, y, k - j) + y * y);
    }
  }
  for (i = 0; i < (y - 1); i++) {
    long long int j = 0;
    for (j = 0; j < (k + 1); j++)
      if (((i + 1) * x >= j) && ((y - i - 1) * x >= (k - j)))
        sum = min(sum, solve(x, i + 1, j) + solve(x, y - i - 1, k - j) + x * x);
  }
  a[x][y][k] = sum;
  return sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  for (ft = 0; ft < (t); ft++) {
    long long int n, m, k;
    cin >> n >> m >> k;
    cout << solve(n, m, k) << "\n";
  }
  return 0;
}
