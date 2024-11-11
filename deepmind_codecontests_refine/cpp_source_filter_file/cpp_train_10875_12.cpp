#include <bits/stdc++.h>
using namespace std;
int ms[51][51];
int sum(int i, int j, int a, int b) {
  int sm = 0;
  int k = j;
  for (i; i < b; i++) {
    for (k = j; k < a; k++) sm += ms[i][k];
  }
  return sm;
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> ms[i][j];
  cin >> a >> b;
  int min = 9999999;
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a + j <= m && b + i <= n) temp = sum(i, j, a + j, b + i);
      if (temp < min) min = temp;
      if (j - a >= 0 && i - b >= 0) temp = sum(i - b, j - a, i, j);
      if (temp < min) min = temp;
      if (b + j <= m && a + i <= n) temp = sum(i, j, b + j, a + i);
      if (temp < min) min = temp;
      if (j - b >= 0 && i - a >= 0) temp = sum(i - a, j - b, i, j);
      if (temp < min) min = temp;
    }
  }
  cout << min;
  return 0;
}
