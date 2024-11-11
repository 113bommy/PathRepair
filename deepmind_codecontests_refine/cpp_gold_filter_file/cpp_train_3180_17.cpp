#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n;
char board[1005][1005];
int pre[8][1005][1005], pre2[8][1005][1005], pre3[8][1005][1005];
int direction[8][2] = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                       {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
bool bigger(int cnt21, int cnt31, int cnt22, int cnt32) {
  double d1 = cnt21 + cnt31 * log2(3), d2 = cnt22 + cnt32 * log2(3);
  return d1 > d2;
}
bool inRange(int x) { return x >= 0 && x < n; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  memset(board, 0, sizeof(board));
  memset(pre, 0, sizeof(pre));
  memset(pre2, 0, sizeof(pre2));
  memset(pre3, 0, sizeof(pre3));
  cin >> n;
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)n; j++) cin >> board[i][j];
  bool oneExist = 0;
  int maxCnt2 = 0, maxCnt3 = 0;
  for (int k = 0; k < (int)8; k++) {
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)n; j++) {
        int x0 = i - direction[k][0], y0 = j - direction[k][1];
        if (!inRange(x0) || !inRange(y0)) {
          int cnt = 0, k0 = 0, k2 = 0, k3 = 0;
          bool next = 1;
          while (next) {
            cnt++;
            int x = x0 + direction[k][0] * cnt, y = y0 + direction[k][1] * cnt;
            if (!inRange(x) || !inRange(y)) {
              next = 0;
              break;
            }
            if (board[x][y] == '0') {
              k0 = k2 = k3 = 0;
            } else {
              if (board[x][y] == '2') k2++;
              if (board[x][y] == '3') k3++;
              k0++;
              pre[k][x][y] = k0;
              pre2[k][x][y] = k2;
              pre3[k][x][y] = k3;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < (int)n; i++) {
    for (int j = 0; j < (int)n; j++) {
      if (board[i][j] == '0') continue;
      for (int l = 0; l < (int)2; l++) {
        int t = l * 4;
        oneExist = 1;
        int cnt2 = 0, cnt3 = 0, cnt = 10000;
        if (board[i][j] == '2') cnt2++;
        if (board[i][j] == '3') cnt3++;
        for (int k = t; k < (int)t + 4; k++) cnt = min(cnt, pre[k][i][j] - 1);
        if (cnt) {
          for (int k = t; k < (int)t + 4; k++) {
            int x = i + direction[k][0] * cnt, y = j + direction[k][1] * cnt;
            cnt2 += abs(pre2[k][i][j] - pre2[k][x][y]);
            cnt3 += abs(pre3[k][i][j] - pre3[k][x][y]);
          }
        }
        if (bigger(cnt2, cnt3, maxCnt2, maxCnt3)) {
          maxCnt2 = cnt2;
          maxCnt3 = cnt3;
        }
      }
    }
  }
  if (!oneExist)
    cout << 0 << "\n";
  else {
    long long ans = 1;
    for (int i = 0; i < (int)maxCnt2; i++) {
      ans *= 2;
      ans %= mod;
    }
    for (int i = 0; i < (int)maxCnt3; i++) {
      ans *= 3;
      ans %= mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
