#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int prefix[N][N];
bool white[N][N];
bool star[N][N];
int nstars(int r1, int r2, int c1, int c2) {
  r2--, c2--;
  r1++, c1++;
  return prefix[r2][c2] - prefix[r1 - 1][c2] - prefix[r2][c1 - 1] +
         prefix[r1 - 1][c1 - 1];
}
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      white[i][j] = c == '1';
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (white[i][j] and white[i][j - 1] and white[i - 1][j] and
          white[i + 1][j] and white[i][j + 1])
        star[i][j] = true;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] -
                     prefix[i - 1][j - 1] + star[i][j];
    }
  }
  long long ans = 0;
  for (int r1 = 0; r1 < n; r1++) {
    for (int r2 = r1; r2 < n; r2++) {
      int l = 0, r = 0;
      for (l = 0; l < m; l++) {
        while (r < m and nstars(r1, r2, l, r) < k) {
          r++;
        }
        ans += m - r;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
