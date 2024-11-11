#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, y1, x2, y2;
  cin >> n;
  long long s = 0, a[101][101];
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 101; j++) a[i][j] = 0;
  for (int c = 0; c < n; c++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1; i <= x2; i++)
      for (int j = y1; j <= y2; j++) a[i][j]++;
  }
  for (int i = 0; i < 101; i++)
    for (int j = 0; j < 101; j++) s += a[i][j];
  cout << s << endl;
  return 0;
}
