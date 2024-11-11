#include <bits/stdc++.h>
using namespace std;
long long N, M, B;
pair<long long, pair<long long, int>> friends[110];
long long memo[2][1 << 20];
long long dp(int pos, int msk) { return memo[pos % 2][msk]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> B;
  int mk, sp = 0;
  for (int i = 0; i < N; i++) {
    cin >> friends[i].second.first >> friends[i].first >> mk;
    friends[i].second.second = 0;
    for (int j = 0; j < mk; j++) {
      cin >> sp;
      sp--;
      friends[i].second.second += 1 << sp;
    }
  }
  sort(friends, friends + N);
  for (int i = 0; i < (1 << M); i++) {
    memo[N % 2][i] = 2e18;
  }
  memo[N % 2][(1 << M) - 1] = friends[N - 1].first * B;
  for (int pos = N - 1; pos >= 0; pos--) {
    for (int msk = 0; msk < (1 << M); msk++) {
      if (msk + 1 == (1 << M)) {
        memo[pos % 2][msk] = friends[pos - 1].first * B;
        continue;
      }
      memo[pos % 2][msk] = dp(pos + 1, msk);
      memo[pos % 2][msk] = min(memo[pos % 2][msk],
                               dp(pos + 1, msk | friends[pos].second.second) +
                                   friends[pos].second.first);
    }
  }
  long long rp = dp(0, 0);
  if (rp >= 2e18) {
    cout << -1;
  } else {
    cout << rp;
  }
  return 0;
}
