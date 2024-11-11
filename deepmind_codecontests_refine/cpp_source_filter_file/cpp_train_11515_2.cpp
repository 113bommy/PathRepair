#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using db = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
const int MOD = 1e9 + 7;
const int MX = 5010;
const ll INF = 1e18;
int N, B;
int C[MX], D[MX];
vi child[MX];
vl DP[MX][2];
vl comb(vl A, vl B) {
  vl res((int)(A).size() + (int)(B).size() - 1, INF);
  for (int i = (0); i < ((int)(A).size()); i++)
    for (int j = (0); j < ((int)(B).size()); j++)
      res[i + j] = min(res[i + j], A[i] + B[j]);
  return res;
}
void solve(int X) {
  DP[X][0] = {0, C[X]};
  DP[X][1] = {INF, C[X] - D[X]};
  for (auto& Y : child[X]) {
    solve(Y);
    DP[X][0] = comb(DP[X][0], DP[Y][0]);
    DP[X][1] = comb(DP[X][1], DP[Y][1]);
  }
  for (int i = (0); i < ((int)(DP[X][1]).size()); i++) {
    DP[X][1][i] = min(DP[X][1][i], DP[X][0][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> B;
  for (int i = (1); i < (N + 1); i++) {
    cin >> C[i] >> D[i];
    if (i > 1) {
      int X;
      cin >> X;
      child[X].push_back(i);
    }
  }
  solve(1);
  for (int i = (N)-1; i >= (0); i--) {
    if (DP[1][1][i] <= B) {
      cout << i;
      break;
    }
  }
}
