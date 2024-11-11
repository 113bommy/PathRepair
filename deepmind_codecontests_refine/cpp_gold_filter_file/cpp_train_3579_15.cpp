#include <bits/stdc++.h>
using namespace std;
int n, l, m, sol;
int a[10];
bool r[333][333];
bool ok;
int main() {
  cin >> n;
  for (int(i) = (0); (i) < (n); ++(i)) cin >> a[i];
  if (n == 1) {
    if (a[0] == 0)
      cout << "BitAryo" << endl;
    else
      cout << "BitLGM" << endl;
    return 0;
  }
  if (n == 2) {
    r[0][0] = false;
    for (int(i) = (0); (i) < (a[0] + 1); ++(i))
      for (int(j) = (0); (j) < (a[1] + 1); ++(j)) {
        if (i + j == 0) continue;
        ok = false;
        m = min(i, j);
        while (m > 0) {
          ok |= (r[i - m][j - m] == 0);
          m--;
        }
        m = i;
        while (m > 0) {
          ok |= (r[i - m][j] == 0);
          m--;
        }
        m = j;
        while (m > 0) {
          ok |= (r[i][j - m] == 0);
          m--;
        }
        r[i][j] = ok;
      }
    if (r[a[0]][a[1]])
      cout << "BitLGM" << endl;
    else
      cout << "BitAryo" << endl;
    return 0;
  }
  if (a[0] ^ a[1] ^ a[2])
    cout << "BitLGM" << endl;
  else
    cout << "BitAryo" << endl;
  return 0;
}
