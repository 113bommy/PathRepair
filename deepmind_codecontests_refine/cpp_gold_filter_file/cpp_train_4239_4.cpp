#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int memo[2002][10][10][10][10];
int n;
int in[2002], out[2002];
int calc(int i, int b1, int b2, int b3, int b4, int floor) {
  if (i == n && (b1 + b2 + b3 + b4) == 0) return 0;
  int a[4], load = 0;
  memset(a, 0, sizeof a);
  if (b1 != 0) a[load++] = b1;
  if (b2 != 0) a[load++] = b2;
  if (b3 != 0) a[load++] = b3;
  if (b4 != 0) a[load++] = b4;
  sort(a, a + 4);
  int mn = INF;
  if (load == 4) {
    mn = min(mn, calc(i, 0, a[0], a[1], a[2], a[3]) + abs(floor - a[3]) + 1);
    mn = min(mn, calc(i, 0, a[1], a[2], a[3], a[0]) + abs(floor - a[0]) + 1);
    mn = min(mn, calc(i, 0, a[0], a[2], a[3], a[1]) + abs(floor - a[1]) + 1);
    mn = min(mn, calc(i, 0, a[0], a[1], a[3], a[2]) + abs(floor - a[2]) + 1);
    return mn;
  }
  if (memo[i][a[1]][a[2]][a[3]][floor] != -1)
    return memo[i][a[1]][a[2]][a[3]][floor];
  mn = INF;
  if (a[3] > 0)
    mn = min(mn, calc(i, 0, 0, a[1], a[2], a[3]) + abs(floor - a[3]) + 1);
  if (a[2] > 0)
    mn = min(mn, calc(i, 0, 0, a[1], a[3], a[2]) + abs(floor - a[2]) + 1);
  if (a[1] > 0)
    mn = min(mn, calc(i, 0, 0, a[2], a[3], a[1]) + abs(floor - a[1]) + 1);
  if (i < n)
    mn = min(mn, calc(i + 1, out[i], a[1], a[2], a[3], in[i]) +
                     abs(floor - in[i]) + 1);
  return memo[i][a[1]][a[2]][a[3]][floor] = mn;
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(memo, -1, sizeof memo);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in[i] >> out[i];
  cout << calc(0, 0, 0, 0, 0, 1) << '\n';
  return 0;
}
