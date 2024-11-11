#include <bits/stdc++.h>
using namespace std;
int a[105];
bool t[205];
int main() {
  int z, n, k, d, mmin, tmp;
  cin >> z;
  for (int i = 0; i < z; i++) {
    cin >> n >> k >> d;
    mmin = 10000;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    for (int l = 0; l < n; l++) {
      if (l + d == n + 1) break;
      memset(t, 0, sizeof(t));
      tmp = 0;
      for (int kk = l; kk < l + d; kk++) {
        if (!t[a[kk]]) tmp++;
        t[a[kk]] = 1;
      }
      mmin = min(mmin, tmp);
    }
    cout << mmin << endl;
  }
}
