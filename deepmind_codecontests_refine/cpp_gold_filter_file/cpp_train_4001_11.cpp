#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const long long BIG = 1446803456761533460LL;
const int Big = 336860180;
stringstream sss;
const int maxn = 100010;
const int SQ = 400;
const int maxnsq = maxn / SQ + 10;
int n;
int ai[maxn];
vector<int> Q[maxnsq], Qt[maxnsq];
int MX[maxnsq];
bool add(int idx, int a, int c) {
  int ii = maxnsq - 1;
  while (ii > 0 && MX[ii] < a && Q[ii].size() <= c) {
    c -= Q[ii].size();
    --ii;
  }
  int i = Q[ii].size();
  while (i > 0 && a > ai[Q[ii][i - 1]] && c) --i, --c;
  Q[ii].insert(Q[ii].begin() + i, idx);
  MX[ii] = max(MX[ii], (a));
  return Q[ii].size() >= SQ * 2;
}
void normal(int n) {
  for (int i = (0); i < (maxnsq); ++i) {
    swap(Q[i], Qt[i]);
    Q[i].clear();
  }
  memset(MX, 0, sizeof MX);
  int ii = 0, i = 0;
  int jj = 0;
  for (int t = (0); t < (n); ++t) {
    if (i == Qt[ii].size()) {
      i = 0;
      ++ii;
    }
    if (Q[jj].size() == SQ) {
      ++jj;
    }
    Q[jj].push_back(Qt[ii][i]);
    MX[jj] = max(MX[jj], (ai[Qt[ii][i]]));
    ++i;
  }
}
void MAIN() {
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int c;
    cin >> ai[i] >> c;
    if (add(i, ai[i], c)) {
      normal(i + 1);
    }
  }
  for (int i = (0); i < (maxnsq); ++i) {
    for (int j = (0); j < (Q[i].size()); ++j) {
      cout << Q[i][j] + 1 << ' ';
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sss << R"(
5
2 3
1 4
4 3
3 1
5 2
    )";
  MAIN();
  return 0;
}
