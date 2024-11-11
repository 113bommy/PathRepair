#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int G[12][12];
int S[12][12];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int r, c, n, k;
  cin >> r >> c >> n >> k;
  memset((G), (0), sizeof(G));
  memset((S), (0), sizeof(S));
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x][y] = 1;
  }
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      S[i][j] = G[i][j];
      if (i) S[i][j] += S[i - 1][j];
      if (j) S[i][j] += S[i][j - 1];
      if (i && j) S[i][j] -= S[i - 1][j - 1];
    }
  }
  int cnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int i2 = i; i2 < r; ++i2) {
        for (int j2 = j; j2 < c; ++j2) {
          int tmp = S[i2][j2];
          if (i) tmp -= S[i - 1][j2];
          if (j) tmp -= S[i2][j - 1];
          if (i && j) tmp += S[i - 1][j - 1];
          if (tmp >= k) cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
