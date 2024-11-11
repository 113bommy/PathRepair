#include <bits/stdc++.h>
using namespace std;
char a[200][200];
int n, m;
bool check(int i) {
  for (int j = 0; j < m; j++) {
    for (int k = j + 1; k < m; k++) {
      if (a[i][j] != a[i][k]) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (!check(i) || (i < n - 1 && a[i][0] == a[i + 1][0])) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
