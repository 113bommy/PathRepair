#include <bits/stdc++.h>
using namespace std;
const long double inf = 1e99;
int n;
long double C, T;
long double mintime[101][1001];
long double p9pow[101];
bool canfit(long double req, long double excess) {
  long double t = max((long double)0.0, (sqrt(excess * C) - 1.0) / C);
  return req + t + excess / (1.0 + C * t) <= T + 1e-3;
}
void solve() {
  cin >> n;
  cin >> C >> T;
  int ai, pi;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 1001; j++) {
      mintime[i][j] = inf;
    }
  }
  mintime[0][0] = 0.0;
  vector<pair<int, int> > stuff;
  for (int i = 0; i < n; i++) {
    cin >> ai >> pi;
    stuff.push_back(pair<int, int>(ai, pi));
  }
  sort(stuff.begin(), stuff.end());
  reverse(stuff.begin(), stuff.end());
  for (pair<int, int> val : stuff) {
    ai = val.first;
    pi = val.second;
    for (int j = n; j >= 1; j--) {
      for (int k = 1000; k >= 0; k--) {
        int prevpt = k - pi;
        if (prevpt < 0) continue;
        if (mintime[j - 1][prevpt] == inf) continue;
        mintime[j][k] = min(mintime[j][k],
                            mintime[j - 1][prevpt] + 10 + ai * 1.0 / p9pow[j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 1000; j++) {
      long double req = 10 * i;
      long double excess = mintime[i][j] - req;
      if (canfit(req, excess)) {
        ans = max(ans, j);
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  p9pow[0] = 1.0;
  for (int i = 1; i <= 100; i++) {
    p9pow[i] = p9pow[i - 1] * 0.9;
  }
  while (tc--) {
    solve();
  }
  cout.flush();
}
