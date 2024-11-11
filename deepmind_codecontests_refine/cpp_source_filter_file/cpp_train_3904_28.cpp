#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int check(int nn, int mm) {
  int dn = min(nn - 1, n - nn);
  int dm = min(mm - 1, m - mm);
  int dx = min(dn, dm);
  return dx < 9;
}
int main(void) {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int nn, mm;
    cin >> nn >> mm;
    if (check(nn, mm)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
