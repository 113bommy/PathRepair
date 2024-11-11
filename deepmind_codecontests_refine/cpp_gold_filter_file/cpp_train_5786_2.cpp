#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int r[N], b[N];
int tp[N];
vector<vector<int> > valid;
int INF = 2e8;
int dp[100010][130];
int main() {
  int n;
  cin >> n;
  int R = 0, B = 0;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    tp[i] = (c == 'B');
    if (tp[i])
      B++;
    else
      R++;
    cin >> r[i] >> b[i];
  }
  int w = 1 << n;
  w--;
  int m = (n + 1) / 2;
  int res = INF;
  int RR = n * (n - 1) / 2;
  for (int mask = 0; mask <= w; mask++) {
    for (int j = 0; j <= RR; j++) {
      dp[mask][j] = -INF;
    }
  }
  for (int mask = 1; mask <= w; mask++) {
    int x = __builtin_popcount(mask);
    if (x == 1) {
      for (int i = 1; i <= n; i++) {
        if (mask & (1 << (i - 1))) {
          int rx = R, bx = B;
          if (tp[i])
            bx--;
          else
            rx--;
          dp[mask][min(rx, r[i])] = min(bx, b[i]);
        }
      }
    }
  }
  for (int mask = 1; mask <= w; mask++) {
    int rr = 0, bb = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      if (mask & (1 << (i - 1))) v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
      if (tp[v[i]])
        bb++;
      else
        rr++;
    }
    rr = R - rr;
    bb = B - bb;
    int x = __builtin_popcount(mask);
    if (x <= 1) continue;
    for (int j = 0; j <= RR; j++) {
      for (int i = 1; i <= n; i++) {
        if (mask & (1 << (i - 1))) {
          int mask1 = mask - (1 << (i - 1));
          int curRed = min(rr, r[i]);
          int curB = min(bb, b[i]);
          if (curRed <= j) {
            if (dp[mask1][j - curRed] >= 0)
              dp[mask][j] = max(dp[mask][j], dp[mask1][j - curRed] + curB);
          }
        }
      }
    }
  }
  res = INF;
  int sur = 0, sub = 0;
  for (int i = 1; i <= n; i++) {
    sur += r[i];
    sub += b[i];
  }
  for (int j = 0; j <= RR; j++) {
    if (dp[w][j] >= 0) res = min(res, max(sur - j, sub - dp[w][j]));
  }
  cout << res + n << endl;
}
