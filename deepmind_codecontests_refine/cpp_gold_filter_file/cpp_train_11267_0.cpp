#include <bits/stdc++.h>
long long R = 7 + 1e9, NUMTESTCASE;
const int NN = 10 + 1e5, MM = (1 << 8);
const double pi = acos(-1.0);
int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1},
    DI[8] = {1, 1, 0, -1, -1, -1, 0, 1}, DJ[8] = {0, 1, 1, 1, 0, -1, -1, -1};
using namespace std;
long long n, p, x, k, Arr[NN][10], Memo[NN][MM], Sort[NN];
set<pair<long long, long long>, greater<pair<long long, long long>>> Draft;
long long Dp(int Ind, int Flag, int Taken) {
  if (Ind == n + 1)
    if (Taken == p)
      return 0;
    else
      return -INT_MAX;
  if (Memo[Ind][Flag] != -1) return Memo[Ind][Flag];
  long long Res = Dp(Ind + 1, Flag, Taken);
  if (Ind - 1 - Taken < k) Res += Arr[Ind][0];
  for (int Pos = 1; Pos <= p; Pos++)
    if ((Flag & (1 << Pos)) == 0)
      Res = max(Res, Arr[Ind][Pos] + Dp(Ind + 1, Flag | (1 << Pos), Taken + 1));
  return Memo[Ind][Flag] = Res;
}
int main() {
  memset(Memo, -1, sizeof(Memo));
  cin >> n >> p >> k;
  for (int i = (1); i <= (n); ++i) {
    scanf("%I64d", &x);
    Draft.insert({x, i});
  }
  int Flag = 1;
  for (auto IT : Draft) {
    Sort[IT.second] = Flag;
    Arr[Flag][0] = IT.first;
    Flag++;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (p); ++j) scanf("%I64d", &Arr[Sort[i]][j]);
  Flag = 0;
  for (int i = (1); i <= (p); ++i) Flag += (1 << i);
  cout << Dp(1, 0, 0);
  return 0;
}
