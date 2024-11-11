#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double EPS = 1e-10;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int cnt[510][510];
int sum[510][510];
char field[510][510];
int main() {
  fill(&field[0][0], &field[0][0] + 510 * 510, '0');
  int n, m, K;
  long long res = 0;
  cin >> n >> m >> K;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> field[i + 1][j + 1];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cnt[i][j] = 1;
      if (field[i + 1][j + 1] == '0') cnt[i][j] = 0;
      for (int k = 0; k < 4; k++) {
        int i2 = i + 1 + dy[k];
        int j2 = j + 1 + dx[k];
        if (field[i2][j2] == '0') cnt[i][j] = 0;
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i > 1 && j > 1) {
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] +
                    cnt[i - 1][j - 1];
      }
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (sum[i][j] < K) continue;
      for (int k = 0; k < i - 1; k++) {
        int ub = j;
        int lb = 0;
        while (ub - lb > 1) {
          int mb = (ub + lb) / 2;
          long long s =
              sum[i][j] - sum[k + 1][j] - sum[i][mb + 1] + sum[k + 1][mb + 1];
          if (s >= K) {
            lb = mb;
          } else
            ub = mb;
        }
        if (sum[i][j] - sum[k + 1][j] - sum[i][lb + 1] + sum[k + 1][lb + 1] >=
            K) {
          res += lb + 1;
        }
      }
    }
  cout << res << endl;
  return 0;
}
