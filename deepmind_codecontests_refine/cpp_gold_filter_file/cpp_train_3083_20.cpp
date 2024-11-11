#include <bits/stdc++.h>
using namespace std;
int N, M, K, q;
vector<pair<pair<int, int>, int> > p;
bool broken(long long time) {
  long long cnt[N + 1][M + 1];
  for (int i = 0; i <= N; ++i)
    for (int j = 0; j <= M; ++j) cnt[i][j] = 0;
  for (int i = 0; i < (int)p.size(); ++i)
    if (p[i].second <= time) cnt[p[i].first.first][p[i].first.second] = 1;
  for (int i = 1; i <= N; ++i)
    for (int j = 1; j <= M; ++j)
      cnt[i][j] += cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1];
  for (int i = K; i <= N; ++i)
    for (int j = K; j <= M; ++j)
      if (cnt[i][j] - cnt[i - K][j] - cnt[i][j - K] + cnt[i - K][j - K] ==
          K * K)
        return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M >> K >> q;
  p.resize(q);
  for (int i = 0; i < q; ++i) {
    int x, y, time;
    cin >> x >> y >> time;
    p[i] = {{x, y}, time};
  }
  long long i = 0, j = 2e9;
  long long ans = -1;
  while (i <= j) {
    long long mid = j + (i - j) / 2ll;
    if (broken(mid))
      ans = mid, j = mid - 1;
    else
      i = mid + 1;
  }
  cout << ans;
  return 0;
}
