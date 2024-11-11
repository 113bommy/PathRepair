#include <bits/stdc++.h>
using namespace std;
int main() {
  int p;
  int q;
  int l;
  int r;
  cin >> p >> q >> l >> r;
  int X[p][2];
  int Z[q][2];
  for (int i = 0; i < p; i++) cin >> X[i][0] >> X[i][1];
  for (int i = 0; i < q; i++) cin >> Z[i][0] >> Z[i][1];
  long int t[10000];
  for (int i = 0; i < 1000; i++) t[i] = r + 1;
  int ct = 0;
  int temp = 0;
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      temp = X[i][0] - Z[j][1];
      if (temp > l & temp < r) {
        t[ct] = temp;
        ct++;
      }
      temp++;
      for (int k = temp; k <= (X[i][1] - Z[j][0]); k++) {
        if (k >= l & k <= r) {
          t[ct] = k;
          ct++;
        }
      }
    }
  }
  sort(t, t + ct);
  int realc = 0;
  for (int m = 0; m < ct - 1; m++) {
    if (t[m + 1] != t[m]) realc++;
  }
  if (ct != 0)
    cout << realc + 1;
  else
    cout << 0;
}
