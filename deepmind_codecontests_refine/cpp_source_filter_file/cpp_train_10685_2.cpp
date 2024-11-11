#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int a[5005];
bool dp[5005][5005], prv[5005][5005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k, v;
  cin >> n >> k >> v;
  int s = 0;
  for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
  if (s < v) {
    cout << "NO\n";
    return 0;
  }
  int cur = 0, use = 0, pv = v % k;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int c = a[i] % k;
    for (int j = 0; j < k; ++j) {
      if (!dp[i - 1][j]) continue;
      dp[i][j] = true;
      dp[i][(j + c) % k] = true;
      prv[i][(j + c) % k] = true;
    }
  }
  if (!dp[n][pv]) {
    cout << "NO\n";
    return 0;
  }
  vector<int> mv[2];
  for (int i = n; i; --i) {
    int c = a[i] % k;
    if (prv[i][pv]) {
      mv[0].push_back(i);
      pv = (pv - c + k) % k;
    } else {
      mv[1].push_back(i);
    }
  }
  cout << "YES\n";
  if (!mv[0].empty()) {
    for (int i = 1; i < mv[0].size(); ++i)
      cout << 1000000 << " " << mv[0][i] << " " << mv[0][0] << "\n";
  }
  if (!mv[1].empty()) {
    for (int i = 1; i < mv[1].size(); ++i)
      cout << 1000000 << " " << mv[1][i] << " " << mv[1][0] << "\n";
  }
  s = 0;
  for (int i = 0; i < mv[0].size(); ++i) s += a[mv[0][i]];
  int in, out;
  if (mv[1].empty())
    in = mv[0][0], out = mv[0][1];
  else if (mv[0].empty())
    in = mv[1][0], out = mv[1][1];
  else
    in = mv[0][0], out = mv[1][0];
  if (s > v) {
    cout << (s - v) / k << " " << in << " " << out;
  } else if (s < v) {
    cout << (v - s) / k << " " << out << " " << in;
  }
  return 0;
}
