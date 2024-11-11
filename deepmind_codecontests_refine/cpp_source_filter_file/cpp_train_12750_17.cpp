#include <bits/stdc++.h>
using namespace std;
const int N = 200001, M = 350;
mt19937 gen(time(NULL));
template <typename T = int>
inline T read() {
  T val = 0, sign = 1;
  char ch;
  for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') sign = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) val = val * 10 + ch - '0';
  return sign * val;
}
vector<int> m[10];
int d[10];
string dp[106][61][16][16];
bool relax(int i, int j, int k, int q, string val) {
  if (i < 50 && j < 35 && k < 16 && q < 16) {
    if (dp[i][j][k][q].size() < val.size() || dp[i][j][k][q] == "x")
      dp[i][j][k][q] = val;
    else if (val.size() == dp[i][j][k][q].size() && dp[i][j][k][q] < val)
      dp[i][j][k][q] = val;
  }
  return false;
}
void solve() {
  string s;
  int n = read();
  cin >> s;
  vector<int> rs(4);
  for (auto v : s) {
    int j = v - '0';
    if (j > 1)
      for (int i = 0; i < 4; i++) rs[i] += m[j][i];
  }
  for (int i = 0; i < 106; i++)
    for (int j = 0; j < 61; j++)
      for (int k = 0; k < 16; k++)
        for (int q = 0; q < 16; q++) dp[i][j][k][q] = "x";
  dp[0][0][0][0] = "";
  for (int i = 0; i < 106; i++)
    for (int j = 0; j < 61; j++)
      for (int k = 0; k < 16; k++)
        for (int q = 0; q < 16; q++)
          if (dp[i][j][k][q] != "x")
            for (int e = 2; e <= 9; e++)
              if (relax(i + m[e][0], j + m[e][1], k + m[e][2], q + m[e][3],
                        dp[i][j][k][q] + to_string(e)))
                ;
  cout << dp[rs[0]][rs[1]][rs[2]][rs[3]] << '\n';
}
void precalc() {
  d[2] = 0, d[3] = 1, d[5] = 2, d[7] = 3;
  vector<int> ps(4);
  vector<int> dv = {2, 3, 5, 7};
  for (int i = 2; i <= 9; i++) {
    int j = i;
    for (auto v : dv)
      while (j % v == 0) {
        ps[d[v]]++;
        j /= v;
      }
    m[i] = ps;
  }
}
signed main() {
  int t = 1;
  precalc();
  while (t--) {
    clock_t z = clock();
    solve();
    fprintf(stderr, "Total Time: %.3f\n",
            (double)(clock() - z) / CLOCKS_PER_SEC),
        fflush(stderr);
  }
}
