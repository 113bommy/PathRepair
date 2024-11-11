#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30001;
const int SQ = 300;
const int M2 = SQ * 2 + 2;
int f[MAXN][M2];
int a[MAXN];
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < MAXN; i++) {
    a[i] = 0;
    for (int j = 0; j < M2; j++) f[i][j] = -MAXN;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  int lg;
  if (d < SQ)
    lg = 0;
  else
    lg = d - SQ;
  f[d][d - lg] = 0;
  for (int i = d; i < MAXN; i++) {
    for (int j = 0; j < M2; j++) {
      f[i][j] += a[i];
      ans = max(ans, f[i][j]);
      for (int cj = j + lg - 1; cj <= j + lg + 1; cj++) {
        if ((cj != 0) && (i + cj < MAXN))
          f[i + cj][cj - lg] = max(f[i + cj][cj - lg], f[i][j]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
