#include <bits/stdc++.h>
using namespace std;
int k[3], t[3];
long long t1[4][102400];
long long spare[102400];
int main() {
  for (int i = 0; i < (3); i++) cin >> k[i];
  for (int i = 0; i < (3); i++) cin >> t[i];
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> t1[0][i];
  for (int p = 0; p < (3); p++) {
    if (k[p] >= n) {
      for (int i = 0; i < (n); i++) t1[p + 1][i] = t1[p][i] + t[p];
    } else {
      int pnt = 0;
      memset(spare, 0, sizeof spare);
      for (int i = 0; i < (n); i++) {
        if (pnt == k[p]) pnt = 0;
        if (spare[pnt] <= t1[p][i])
          spare[pnt] = t1[p + 1][i] = t1[p][i] + t[p];
        else {
          t1[p + 1][i] = spare[pnt] + t[p];
          spare[pnt] += t[p];
        }
        pnt++;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < (n); i++) res = max(res, t1[3][i] - t1[0][i]);
  cout << res << endl;
  return 0;
}
