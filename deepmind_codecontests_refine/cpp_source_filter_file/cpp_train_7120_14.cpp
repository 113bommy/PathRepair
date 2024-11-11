#include <bits/stdc++.h>
using namespace std;
int a[100][100];
int main() {
  string x;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < n; j++) {
      if (x[j] == 'E') a[i][j] = 1;
    }
  }
  int k = 0;
  int s;
  for (int i = 0; i < n; i++) {
    s = 1;
    for (int j = 0; j < n; j++) s *= a[i][j];
    k += (1 - s);
  }
  if (k == n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] == 0) {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
    return 0;
  }
  k = 0;
  for (int i = 0; i < n; i++) {
    s = 1;
    for (int j = 0; j < n; j++) s *= a[j][i];
    k += (1 - s);
  }
  if (k == n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[j][i] == 0) {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
    return 0;
  }
  cout << -1;
  return 0;
}
