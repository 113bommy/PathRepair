#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long x, y, d, e, t;
long long er[505][505], tr[505][505][2], dp[505][505];
vector<pair<long long, long long> > qr[502][502][2];
void qq();
int main() {
  scanf("%lld %lld %lld", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%lld %lld %lld %lld %lld", &x, &y, &d, &t, &e);
    qq();
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int k = 0; k < 2; k++) sort(qr[i][j][k].begin(), qr[i][j][k].end());
  long long ptr = 0, min_ = 0, tot = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      ptr = 0, min_ = 1e18, tot = 0;
      if (i == n - 1 && j == m - 1) min_ = 0;
      dp[i][j] = er[i][j];
      for (int k = i + 1; k < n; k++) {
        if (qr[i][j][1].size() > ptr && qr[i][j][1][ptr].first == k) {
          tr[k][j][1] += qr[i][j][1][ptr].second;
          ptr++;
        }
        min_ = min(min_, tot + dp[k][j] - tr[k][j][1]);
        tot += er[k][j] - tr[k][j][1];
      }
      ptr = 0, tot = 0;
      for (int k = j + 1; k < m; k++) {
        while (qr[i][j][0].size() > ptr && qr[i][j][0][ptr].first == k) {
          tr[i][k][0] += qr[i][j][0][ptr].second;
          ptr++;
        }
        min_ = min(min_, tot + dp[i][k] - tr[i][k][0]);
        tot += er[i][k] - tr[i][k][0];
      }
      dp[i][j] += min_;
    }
  }
  cout << dp[0][0];
}
void qq() {
  if ((x + y) >= t && (x + y) % 4 == (t + 0) % 4) {
    er[x][y] += e;
    if (d % 4 == 3) {
      qr[x][y][1].push_back(make_pair(x + d, e));
    }
    if (d % 4 == 2) {
      qr[x][y][0].push_back(make_pair(y + d, e));
    }
  }
  if (x + d + y - d >= t + 1 && (x + y) % 4 == (t + 1) % 4) {
    er[x + d][y - d] += e;
    if (d % 4 == 1) {
      qr[x + d][y - d][0].push_back(make_pair(y, e));
    }
  }
  if (x + d + y >= t + 2 && (x + d + y) % 4 == (t + 2) % 4) {
    er[x + d][y] += e;
  }
  if (x + y + d >= t + 3 && (x + y + d) % 4 == (t + 3) % 4) {
    er[x][y + d] += e;
  }
}
