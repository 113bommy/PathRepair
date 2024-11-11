#include <bits/stdc++.h>
using namespace std;
const int maxn = 406;
int a[maxn];
int b[maxn];
int n, m;
void enter() {
  string A, B;
  cin >> A >> B;
  n = 0;
  m = 0;
  for (auto i : A) a[++n] = i - 'a';
  for (auto i : B) b[++m] = i - 'a';
}
int nex[26][maxn];
const int oo = -1;
void init() {
  memset(nex, 0, sizeof nex);
  for (int i = (1), _b = (n + 1); i < _b; ++i) {
    for (int j = (0), _b = (26); j < _b; ++j) {
      nex[j][i] = nex[j][i - 1];
    }
    nex[a[i]][i] = i;
  }
  for (int i = (0), _b = (26); i < _b; ++i) nex[i][n + 1] = nex[i][n];
}
int f[maxn][maxn];
bool d[maxn][maxn];
int N, M;
int dp(int I, int J) {
  if (I >= N && J >= M) {
    return n + 1;
  } else if (d[I][J])
    return f[I][J];
  else {
    int &res = f[I][J];
    res = oo;
    if (I < N) {
      int pos = dp(I + 1, J);
      if (pos != oo) {
        if (nex[b[I + 1]][pos - 1] != 0) res = max(res, nex[b[I + 1]][pos - 1]);
      }
    }
    if (J < M) {
      int pos = dp(I, J + 1);
      if (pos != oo) {
        if (nex[b[N + J + 1]][pos - 1] != 0)
          res = max(res, nex[b[N + J + 1]][pos - 1]);
      }
    }
    d[I][J] = true;
    return f[I][J];
  }
}
void _reset() {
  for (int i = (0), _b = (N + 1); i < _b; ++i)
    for (int j = (0), _b = (M + 1); j < _b; ++j) d[i][j] = false;
}
void solve() {
  for (int i = (1), _b = (m + 1); i < _b; ++i) {
    N = i;
    M = m - i;
    if (dp(0, 0) != oo) {
      cout << "YES\n";
      _reset();
      return;
    }
    _reset();
  }
  cout << "NO\n";
}
int main() {
  int t;
  cin >> t;
  for (int i = (0), _b = (t); i < _b; ++i) {
    enter();
    init();
    solve();
  }
  return 0;
}
