#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int f;
  vector<vector<int>> mas(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < m; k++) {
      cin >> f;
      if (f == 1) {
        mas[i][k] = f;
        mas[i][m]++;
        mas[n][k]++;
      }
    }
  }
  int n1 = 0, n2 = 0, n3 = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    n1 = n2 = n3 = 0;
    for (int k = 0; k < m; k++) {
      if (mas[i][k] == 1) {
        n1 = k;
        break;
      }
    }
    for (int k = m - 1; k >= 0; k--) {
      if (mas[i][k] == 1) {
        n2 = m - k - 1;
        break;
      }
    }
    sum += n1;
    sum += n2;
    if (mas[i][m] > 1) n3 = m - mas[i][m] - n1 - n2;
    sum += n3 * 2;
  }
  for (int k = 0; k < m; k++) {
    n1 = n2 = n3 = 0;
    for (int i = 0; i < n; i++) {
      if (mas[i][k] == 1) {
        n1 = i;
        break;
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (mas[i][k] == 1) {
        n2 = n - i - 1;
        break;
      }
    }
    sum += n1;
    sum += n2;
    if (mas[n][k] > 1) n3 = n - mas[n][k] - n1 - n2;
    sum += n3 * 2;
  }
  cout << sum;
  return 0;
}
