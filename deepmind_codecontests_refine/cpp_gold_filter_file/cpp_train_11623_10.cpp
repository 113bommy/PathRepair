#include <bits/stdc++.h>
using namespace std;
int dad, mum, son, masha;
bool ccheck(int tx, int ty, int tz) {
  if (dad > tx) return 0;
  if (2 * dad < tx) return 0;
  if (mum > ty) return 0;
  if (2 * mum < ty) return 0;
  if (son > tz) return 0;
  if (2 * son < tz) return 0;
  if (masha > tz) return 0;
  if (masha * 2 < tz) return 0;
  if (masha * 2 >= ty) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> dad >> mum >> son >> masha;
  for (int i = 1; i <= 250; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 1; k < j; k++) {
        if (ccheck(i, j, k)) {
          cout << i << endl << j << endl << k << endl;
          exit(0);
        }
      }
    }
  }
  cout << -1;
  return 0;
}
