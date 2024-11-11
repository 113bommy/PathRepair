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
const int MAXN = (1 << 19);
const int MAXLG = 18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
bool dp[MAXN];
long long n;
long long adj[19][3];
int main() {
  char c;
  for (int i = 0; i < 19; i++) {
    cin >> c;
    if (c == 'O') {
      n += (1 << i);
    }
  }
  adj[0][0] = 1;
  adj[0][1] = 4;
  adj[0][2] = 3;
  adj[1][0] = 2;
  adj[1][1] = 5;
  adj[1][2] = 4;
  adj[2][0] = -1;
  adj[2][1] = 6;
  adj[2][2] = 5;
  adj[3][0] = 4;
  adj[3][1] = 8;
  adj[3][2] = 9;
  adj[4][0] = 5;
  adj[4][1] = 9;
  adj[4][2] = 8;
  adj[5][0] = 6;
  adj[5][1] = 10;
  adj[5][2] = 9;
  adj[6][0] = -1;
  adj[6][1] = 11;
  adj[6][2] = 10;
  adj[7][0] = 8;
  adj[7][1] = 12;
  adj[7][2] = -1;
  adj[8][0] = 9;
  adj[8][1] = 13;
  adj[8][2] = 12;
  adj[9][0] = 10;
  adj[9][1] = 14;
  adj[9][2] = 13;
  adj[10][0] = 11;
  adj[10][1] = 15;
  adj[10][2] = 14;
  adj[11][0] = -1;
  adj[11][1] = -1;
  adj[11][2] = 15;
  adj[12][0] = 13;
  adj[12][1] = 16;
  adj[12][2] = -1;
  adj[13][0] = 14;
  adj[13][1] = 17;
  adj[13][2] = 16;
  adj[14][0] = 15;
  adj[14][1] = 18;
  adj[14][2] = 17;
  adj[15][0] = -1;
  adj[15][1] = -1;
  adj[15][2] = 18;
  adj[16][0] = 17;
  adj[16][1] = -1;
  adj[16][2] = -1;
  adj[17][0] = 18;
  adj[17][1] = -1;
  adj[17][2] = -1;
  adj[18][0] = -1;
  adj[18][1] = -1;
  adj[18][2] = -1;
  for (int i = 1; i < MAXN; i++) dp[i] = true;
  dp[0] = false;
  for (int mask = 1; mask < MAXN; mask++) {
    for (int i = 0; i < 19; i++) {
      long long tmp;
      long long ind;
      for (int j = 0; j < 3; j++) {
        ind = i;
        tmp = 0;
        while (ind != -1 and ((1 << ind) & mask)) {
          tmp += (1 << ind);
          dp[mask] &= dp[mask ^ tmp];
          ind = adj[ind][j];
        }
      }
    }
    dp[mask] = !dp[mask];
  }
  dp[n] ? cout << "Karlsson" : cout << "Lillebror";
}
