#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 0, m = 0, d[101] = {0};
  string s, a[101];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    a[i] = s;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (a[i][j] == 'C') {
        m++;
        d[j]++;
      }
    if (m > 1) l = l + (m * (m - 1) / 2);
    m = 0;
  }
  for (int i = 0; i < n; i++)
    if (d[i] > 1) l = l + (d[i] * (d[i] - 1) / 2);
  cout << l << endl;
  return 0;
}
