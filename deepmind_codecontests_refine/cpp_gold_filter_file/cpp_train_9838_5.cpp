#include <bits/stdc++.h>
using namespace std;
long long getlen(long long x, int l, int r) {
  if (x >= l && x <= r)
    return 0;
  else if (x < l)
    return (long long)l - x;
  else
    return (long long)x - r;
}
const int N = 5000;
int n, x;
int k;
vector<long long> pts;
vector<pair<int, int> > segs;
long long dp[2][N * 2 + 1 + 7];
long long back[N * 2 + 1 + 7], front[N * 2 + 1 + 7];
int wherex;
int main() {
  scanf("%d%d", &n, &x);
  pts.push_back(x);
  for (int i = 0; i < (int)(n); ++i) {
    pair<int, int> q;
    scanf("%d%d", &q.first, &q.second);
    segs.push_back(q);
    pts.push_back((long long)q.first), pts.push_back((long long)q.second);
  }
  sort(pts.begin(), pts.end());
  k = pts.size();
  int r = 0;
  for (int i = 0; i < (int)(k); ++i) {
    dp[r][i] = getlen(pts[i], segs[n - 1].first, segs[n - 1].second);
    if (pts[i] == x) wherex = i;
  }
  for (int i = n - 2; i >= 0; --i) {
    int nr = r;
    r = 1 - r;
    for (int j = 0; j < (int)(k); ++j)
      dp[r][j] = dp[nr][j] + getlen(pts[j], segs[i].first, segs[i].second);
    back[0] = dp[r][0];
    for (int j = 1; j < k; ++j)
      back[j] = min(dp[r][j], back[j - 1] + pts[j] - pts[j - 1]);
    front[k - 1] = dp[r][k - 1];
    for (int j = k - 2; j >= 0; --j)
      front[j] = min(dp[r][j], front[j + 1] + pts[j + 1] - pts[j]);
    for (int j = 0; j < (int)(k); ++j) dp[r][j] = min(back[j], front[j]);
  }
  printf("%I64d\n", dp[r][wherex]);
  return 0;
}
