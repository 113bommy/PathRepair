#include <bits/stdc++.h>
using namespace std;
stack<time_t> time_stack;
void startTimer() { time_stack.push(clock()); }
double stopTimer() {
  double time = clock() - time_stack.top();
  time_stack.pop();
  return time / double(CLOCKS_PER_SEC);
}
double sqr(double x) { return x * x; }
vector<int> p;
vector<int> used;
void cover(int i) {
  for (int j = i; !used[j]; j = p[j]) used[j] = true;
}
int main() {
  startTimer();
  ios::sync_with_stdio(false);
  string TASK = "immediate";
  cout.precision(9);
  cout << fixed;
  double dp[256][2][256], new_dp[256][2][256];
  for (int i = 0; i < 256; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 256; k++) dp[i][j][k] = 0;
  int x, k;
  double p;
  cin >> x >> k >> p;
  p /= 100;
  int tmp = x, cnt1 = 0;
  while (tmp % 2 == 0) {
    cnt1++;
    tmp /= 2;
  }
  int rem = x % 256;
  if (x > 255) {
    tmp = x / 256;
    int bt = tmp % 2, cnt2 = 0;
    while (tmp % 2 == bt) {
      cnt2++;
      tmp /= 2;
    }
    dp[rem][bt][cnt2] = 1;
  } else
    dp[rem][0][1] = 1;
  for (int step = 0; step < k; step++) {
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 256; k++) new_dp[i][j][k] = 0;
    for (int bm = 0; bm < 256; bm++)
      for (int last = 0; last < 2; last++)
        for (int cnt = 0; cnt < 256; cnt++) {
          int new_bm = bm + 1;
          double v = dp[bm][last][cnt] * (1 - p);
          if (v == 0) continue;
          if (new_bm == 256)
            if (last == 0)
              new_dp[0][1][1] += v;
            else
              new_dp[0][0][cnt] += v;
          else
            new_dp[new_bm][last][cnt] += v;
        }
    for (int bm = 0; bm < 256; bm++)
      for (int last = 0; last < 2; last++)
        for (int cnt = 0; cnt < 256; cnt++) {
          int new_bm = bm * 2;
          double v = dp[bm][last][cnt] * p;
          if (v == 0) continue;
          if (bm & (1 << 7))
            if (last == 0)
              new_dp[new_bm % 256][1][1] += v;
            else
              new_dp[new_bm % 256][1][cnt + 1] += v;
          else if (last == 0)
            new_dp[new_bm % 256][0][cnt + 1] += v;
          else
            new_dp[new_bm % 256][0][1] += v;
        }
    for (int i = 0; i < 256; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k < 256; k++) dp[i][j][k] = new_dp[i][j][k];
  }
  double ans = 0;
  for (int bm = 0; bm < 256; bm++) {
    int end = 0, tmp = bm;
    for (int i = 0; i < 8 && tmp % 2 == 0; i++) {
      end++;
      tmp /= 2;
    }
    for (int last = 0; last < 2; last++)
      for (int cnt = 0; cnt < 256; cnt++) {
        if (dp[bm][last][cnt] == 0) continue;
        if (end == 8 && last == 0)
          ans += dp[bm][last][cnt] * (8 + cnt);
        else
          ans += dp[bm][last][cnt] * end;
      }
  }
  cout << ans;
  cout << endl;
  return 0;
}
