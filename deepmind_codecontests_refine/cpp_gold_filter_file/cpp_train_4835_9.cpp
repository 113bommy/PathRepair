#include <bits/stdc++.h>
using namespace std;
int n, m, k, key, MK, MKEY;
int MAP[110][110];
int ii, jj;
void dfssolve(int pos, int step) {
  int temp[110];
  int cnt, i, j;
  if (pos > n) {
    key = 1;
    k = k < step ? k : step;
    return;
  }
  cnt = 0;
  for (i = 1; i <= m; ++i) {
    temp[i] = MAP[pos][i];
    if (MAP[pos][i] != MAP[pos - 1][i]) {
      cnt++;
      MAP[pos][i] = MAP[pos - 1][i];
    }
  }
  if (step + cnt <= k) dfssolve(pos + 1, step + cnt);
  cnt = 0;
  for (i = 1; i <= m; ++i) {
    if (temp[i] == MAP[pos - 1][i]) {
      cnt++;
      MAP[pos][i] = MAP[pos - 1][i] & 1;
    }
  }
  if (step + cnt <= k) dfssolve(pos + 1, step + cnt);
  for (i = 1; i <= m; ++i) MAP[pos][i] = temp[i];
}
void dfssolveup(int pos, int step) {
  int cnt, i, j;
  int temp[110];
  if (pos < 1) {
    MKEY = 1;
    MK = step < MK ? step : MK;
    return;
  }
  cnt = 0;
  for (i = 1; i <= m; ++i) {
    temp[i] = MAP[pos][i];
    if (MAP[pos][i] != MAP[pos + 1][i]) {
      cnt++;
      MAP[pos][i] = MAP[pos + 1][i];
    }
  }
  if (step + cnt <= k) dfssolveup(pos - 1, step + cnt);
  cnt = 0;
  for (i = 1; i <= m; ++i) {
    if (temp[i] == MAP[pos + 1][i]) {
      cnt++;
      MAP[pos][i] = MAP[pos + 1][i] & 1;
    }
  }
  if (step + cnt <= k) dfssolveup(pos - 1, step + cnt);
  for (i = 1; i <= m; ++i) MAP[pos][i] = temp[i];
}
void dfs(int pos, int step) {
  if (k < step) return;
  if (pos == m) {
    dfssolve(2, step);
    MAP[1][pos] ^= 1;
    dfssolve(2, step + 1);
    MAP[1][pos] ^= 1;
  } else {
    dfs(pos + 1, step);
    MAP[1][pos] ^= 1;
    dfs(pos + 1, step + 1);
    MAP[1][pos] ^= 1;
  }
}
int main() {
  cin >> n >> m >> k;
  key = 0;
  if (n < m) {
    for (ii = 1; ii <= n; ++ii)
      for (jj = 1; jj <= m; ++jj) cin >> MAP[jj][ii];
    swap(n, m);
  } else {
    for (ii = 1; ii <= n; ++ii)
      for (jj = 1; jj <= m; ++jj) cin >> MAP[ii][jj];
  }
  if (n <= k) {
    dfs(1, 0);
  } else {
    for (ii = 1; ii <= n; ++ii) {
      MK = 10;
      MKEY = 0;
      dfssolveup(ii - 1, 0);
      if (MKEY) {
        dfssolve(ii + 1, MK);
      }
    }
  }
  if (key)
    cout << k << endl;
  else
    cout << -1 << endl;
  return 0;
}
