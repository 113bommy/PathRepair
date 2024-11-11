#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long d1[] = {0, 1, 1, 1, 0, -1, -1, -1};
long long d2[] = {1, 1, 0, -1, -1, -1, 0, 1};
char c[101][101];
bool isvalid(long long i, long long j) {
  if (i >= 1 && i <= n && j >= 1 && j <= m) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) cin >> c[i][j];
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (c[i][j] == '.') {
        for (long long k = 0; k < 8; k++) {
          long long x1 = i + d1[k];
          long long y1 = j + d2[k];
          if (isvalid(x1, y1) && c[x1][y1] == '*') {
            cout << "NO";
            return 0;
          }
        }
      } else if (c[i][j] != '*') {
        long long s = c[i][j] - '0';
        long long c1 = 0;
        for (long long k = 0; k < 8; k++) {
          long long x1 = i + d1[k];
          long long y1 = j + d2[k];
          if (c[x1][y1] == '*' && isvalid(x1, y1)) {
            c1++;
          }
        }
        if (c1 != s) {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
  return 0;
}
