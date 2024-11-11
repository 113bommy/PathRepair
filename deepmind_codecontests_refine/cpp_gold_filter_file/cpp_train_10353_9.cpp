#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v, i, j;
  cin >> n >> v;
  int ni, sij, res[n], resi = 0, flag;
  for (i = 0; i < n; i++) {
    flag = 0;
    cin >> ni;
    for (j = 0; j < ni; j++) {
      cin >> sij;
      if (flag == 0 && sij < v) {
        flag = 1;
        res[resi++] = (i + 1);
      }
    }
  }
  cout << resi << endl;
  for (i = 0; i < resi; i++) {
    cout << res[i];
    if (i != (resi - 1)) {
      cout << " ";
    }
  }
  return 0;
}
