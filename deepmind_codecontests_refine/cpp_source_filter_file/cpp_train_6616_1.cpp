#include <bits/stdc++.h>
using namespace std;
const int maxn = 3020;
long long a[maxn], b[maxn];
long long dp1[maxn][maxn];
int n;
bool cmp(int x, int y) { return x > y; }
int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      a[i] -= i;
      b[i] = a[i];
    }
    sort(b, b + n);
    memset(dp1, 0, sizeof(dp1));
    for (int i = 0; i < n; i++) {
      long long minx = dp1[i][0];
      for (int j = 0; j < n; j++) {
        minx = min(minx, dp1[i][j]);
        dp1[i + 1][j] = minx + abs(a[i] - b[j]);
      }
    }
    long long min_up = 100000000;
    for (int i = 0; i < n; i++) {
      min_up = min(min_up, dp1[n][i]);
    }
    cout << min_up << endl;
  }
  return 0;
}
