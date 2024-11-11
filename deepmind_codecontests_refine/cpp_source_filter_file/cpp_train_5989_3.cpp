#include <bits/stdc++.h>
using namespace std;
const int maxn = 150;
char a[maxn][maxn];
int main() {
  ios::sync_with_stdio(false);
  int n;
  int cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      a[i][j] = c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int m = 1; m < n; m++) {
        if (a[i][j] == 'C' && a[i][j] == a[i][j + m]) {
          cnt++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int m = 1; m < n; m++) {
        if (a[i][j] == 'C' && a[i][j] == a[i + m][j]) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
