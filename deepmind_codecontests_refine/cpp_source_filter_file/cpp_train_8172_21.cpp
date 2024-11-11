#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int x, y;
  long long res = 0;
  vector<int> empRow(1000, 0);
  vector<vector<int> > a(1000, empRow);
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    a[x - 1][y - 1] = 1;
  }
  int I = 999;
  int J = 0;
  while (I >= 0 && J < 1000) {
    int i = I;
    int j = J;
    long long count = 0;
    while (i < 1000 && j < 1000) {
      if (a[i][j] == 1) count++;
      i++;
      j++;
    }
    if (I != 0)
      I--;
    else
      J++;
    if (count > 1) res += (count * (count - 1)) / 2;
  }
  I = 0;
  J = 0;
  while (J < 1000 && I < 1000) {
    int i = I;
    int j = J;
    long long count = 0;
    while (i < 1000 && j < 1000) {
      if (a[i][j] == 1) count++;
      i++;
      j--;
    }
    if (J != 999)
      J++;
    else
      I++;
    if (count > 1) res += (count * (count - 1)) / 2;
  }
  cout << res << endl;
  return 0;
}
