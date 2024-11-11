#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, count = 0;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'W' || a[i][j] == 'B' || a[i][j] == 'G') {
        count++;
      }
    }
  }
  if (count > 0) {
    cout << "#Black&White";
  } else {
    cout << "#Color";
  }
}
