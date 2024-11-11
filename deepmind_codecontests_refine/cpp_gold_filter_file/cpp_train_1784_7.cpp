#include <bits/stdc++.h>
using namespace std;
template <class T>
void minn(T &a, T b) {
  a = min(a, b);
}
template <class T>
void maxx(T &a, T b) {
  a = max(a, b);
}
void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
const long long PRIME = 105943LL;
const long long INF = 1e18;
const int SZ = 300000;
const int AC = 0, CA = 1, AG = 2, GA = 3, AT = 4, TA = 5, CG = 6, GC = 7,
          CT = 8, TC = 9, GT = 10, TG = 11;
int opt[2][2][6] = {{{AC, AG, AT, CG, CT, GT}, {CA, GA, TA, GC, TC, TG}},
                    {{GT, CT, CG, AT, AG, AC}, {TG, TC, GC, TA, GA, CA}}};
string pat[12] = {"AC", "CA", "AG", "GA", "AT", "TA",
                  "CG", "GC", "CT", "TC", "GT", "TG"};
string getString(int C, string str) {
  string ret;
  ret.resize(C);
  for (int i = 0; i < (int)(C); i++) ret[i] = str[i % 2];
  return ret;
}
int numDif(array<string, SZ> &mat, int curR, int C, int op) {
  string manu = getString(C, pat[op]);
  int ret = 0;
  for (int c = 0; c < (int)(C); c++)
    if (manu[c] != mat[curR][c]) ret++;
  return ret;
}
int getBest(array<string, SZ> &mat, int R, int C, array<string, SZ> &ans) {
  pair<pair<int, int>, vector<int>> bestSetting = {{INT_MAX, -1},
                                                   vector<int>(1, -1)};
  for (int s = 0; s < (int)(6); s++) {
    int totDif = 0;
    vector<int> rowOp;
    for (int r = 0; r < (int)(R); r++) {
      pair<int, int> best = {INT_MAX, -1};
      minn(best, {numDif(mat, r, C, opt[r % 2][0][s]), 0});
      minn(best, {numDif(mat, r, C, opt[r % 2][1][s]), 1});
      rowOp.push_back(best.second);
      totDif += best.first;
    }
    minn(bestSetting, {{totDif, s}, rowOp});
  }
  for (int r = 0; r < (int)(R); r++)
    ans[r] = getString(
        C, pat[opt[r % 2][bestSetting.second[r]][bestSetting.first.second]]);
  return bestSetting.first.first;
}
int N, M;
array<string, SZ> hor;
array<string, SZ> ver;
array<string, SZ> bestH;
array<string, SZ> bestV;
int main() {
  io();
  cin >> N >> M;
  for (int i = 0; i < (int)(N); i++) cin >> hor[i];
  for (int i = 0; i < (int)(M); i++) ver[i].resize(N);
  for (int i = 0; i < (int)(N); i++)
    for (int j = 0; j < (int)(M); j++) ver[j][i] = hor[i][j];
  int hv = getBest(hor, N, M, bestH);
  int vv = getBest(ver, M, N, bestV);
  if (hv < vv)
    for (int i = 0; i < (int)(N); i++) {
      for (int j = 0; j < (int)(M); j++) cout << bestH[i][j];
      cout << "\n";
    }
  else
    for (int i = 0; i < (int)(N); i++) {
      for (int j = 0; j < (int)(M); j++) cout << bestV[j][i];
      cout << "\n";
    }
  return 0;
}
