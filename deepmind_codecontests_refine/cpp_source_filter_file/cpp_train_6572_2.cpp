#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
char a[maxn][maxn];
int n, x;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i][j] == 'X' && a[i][j] == a[i - 1][j - 1] &&
          a[i][j] == a[i - 1][j + 1] && a[i][j] == a[i + 1][j - 1] &&
          a[i][j] == a[i + 1][j + 1]) {
        x++;
      }
    }
  }
  cout << x;
}
