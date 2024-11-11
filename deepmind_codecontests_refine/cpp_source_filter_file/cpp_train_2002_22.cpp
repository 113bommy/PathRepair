#include <bits/stdc++.h>
using namespace std;
long long N, M, K;
int mat[505][505];
int acm[505][505];
int f(int a, int b, int x, int y) {
  if (x - a < 2 or y - b < 2) return 0;
  if (a == 0 and b == 0) return acm[x][y];
  if (a == 0) return acm[x][y] - acm[x][b + 1];
  if (b == 0) return acm[x][y] - acm[a + 1][y];
  return acm[x][y] - acm[x][b + 1] - acm[a + 1][y] + acm[a + 1][b + 1];
}
int main() {
  cin >> N >> M >> K;
  vector<string> s(N);
  for (long long i = (0); i < (N); i++) cin >> s[i];
  memset(mat, 0, sizeof(mat));
  memset(acm, 0, sizeof(acm));
  for (long long i = (2); i < (N); i++)
    for (long long j = (2); j < (M); j++) {
      mat[i][j] =
          (s[i - 2][j - 1] == '1' and s[i - 1][j - 2] == '1' and
           s[i - 1][j - 1] == '1' and s[i - 1][j] == '1' and s[i][j - 1] == '1')
              ? 1
              : 0;
      acm[i][j] = acm[i - 1][j] + acm[i][j - 1] - acm[i - 1][j - 1] + mat[i][j];
    }
  long long ans = 0;
  for (long long i = (0); i < (N); i++)
    for (long long j = (i + 1); j < (N); j++) {
      int l = 0, r = 1;
      while (l < N) {
        while (r < M and f(i, l, j, r) < K) r++;
        if (r == M) break;
        ans += (M - r);
        l++;
      }
    }
  cout << ans << endl;
}
