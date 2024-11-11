#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
int sx, sy;
int n;
int score[4];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int x, y;
  cin >> n >> sx >> sy;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    if (x < sx) {
      score[3]++;
    } else {
      if (x > sx) score[2]++;
    }
    if (y < sy) {
      score[1]++;
    } else {
      if (y > sy) score[0]++;
    }
  }
  if (sx == 1000000000) {
    score[2] = 0;
  }
  if (sx == 0) {
    score[3] = 0;
  }
  if (sy == 1000000000) {
    score[0] = 0;
  }
  if (sy == 0) {
    score[1] = 0;
  }
  int mx = max(score[0], max(score[1], max(score[2], score[3])));
  if (mx == score[0]) {
    cout << score[0] << "\n" << sx << ' ' << sy + 1;
    return 0;
  }
  if (mx == score[1]) {
    cout << score[1] << "\n" << sx << ' ' << sy - 1;
    return 0;
  }
  if (mx == score[2]) {
    cout << score[2] << "\n" << sx + 1 << ' ' << sy;
    return 0;
  }
  if (mx == score[3]) {
    cout << score[3] << "\n" << sx - 1 << ' ' << sy;
    return 0;
  }
}
