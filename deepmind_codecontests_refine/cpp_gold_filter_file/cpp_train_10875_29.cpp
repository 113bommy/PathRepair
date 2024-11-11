#include <bits/stdc++.h>
int mas[51][51];
using namespace std;
int chet(int I, int J, int A, int B) {
  int sum = 0;
  for (int i = I; i < I + A; i++)
    for (int j = J; j < J + B; j++) sum += mas[i][j];
  return sum;
}
int main() {
  int n, m, a, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> mas[i][j];
  cin >> a >> b;
  int min;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i + a > n || j + b > m) continue;
      if (chet(i, j, a, b) < min) min = chet(i, j, a, b);
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (i + b > n || j + a > m) continue;
      if (chet(i, j, b, a) < min) min = chet(i, j, b, a);
    }
  cout << min;
  return 0;
}
