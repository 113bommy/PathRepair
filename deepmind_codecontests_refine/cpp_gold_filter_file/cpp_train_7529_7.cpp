#include <bits/stdc++.h>
using namespace std;
int marr[200][200];
int main() {
  int n;
  memset(marr, 0, sizeof(marr));
  ;
  int ret = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> marr[i][j];
  if (n == 1) {
    cout << marr[0][0] << endl;
    return 0;
  }
  int mid = n / 2;
  for (int i = 0; i < n; i++) {
    ret += marr[i][i];
    ret += marr[n - i - 1][i];
    ret += marr[mid][i];
    ret += marr[i][mid];
  }
  ret -= 3 * marr[mid][mid];
  cout << ret << endl;
  return 0;
}
