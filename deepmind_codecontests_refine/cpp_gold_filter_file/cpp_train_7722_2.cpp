#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2019;
char init[MAX_N][MAX_N];
char target[MAX_N][MAX_N];
int mat[MAX_N][MAX_N];
char rod[MAX_N];
int lin[MAX_N], col[MAX_N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> init[i];
  for (int i = 0; i < n; i++) cin >> target[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) mat[i][j] = (init[i][j] != target[i][j]);
  int ix = -1;
  cin >> rod;
  for (int i = 0; i < n; i++) {
    rod[i] -= '0';
    if (rod[i]) ix = i;
  }
  if (ix == -1) {
    bool all_zero = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) all_zero &= !mat[i][j];
    if (all_zero)
      cout << 0;
    else
      cout << -1;
    return 0;
  }
  for (int v = 0; v < 2; v++) {
    for (int i = 0; i < n; i++) lin[i] = col[i] = 0;
    lin[ix] = v;
    for (int i = 0; i < n; i++) {
      col[i] = (mat[ix][i] ^ (v * rod[i]));
    }
    bool works = 1;
    for (int i = 0; i < n; i++) {
      if (i == ix) continue;
      int f[2] = {0, 0};
      for (int j = 0; j < n; j++) {
        int t = (mat[i][j] ^ (col[j] * rod[i]));
        if (rod[j])
          f[t]++;
        else if (t)
          works = 0;
      }
      if (f[0] && f[1])
        works = 0;
      else if (f[1])
        lin[i] = 1;
    }
    if (works) {
      int cnt = 0;
      for (int i = 0; i < n; i++) cnt += lin[i] + col[i];
      cout << cnt << "\n";
      for (int i = 0; i < n; i++) {
        if (lin[i]) cout << "row " << i << "\n";
        if (col[i]) cout << "col " << i << "\n";
      }
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
