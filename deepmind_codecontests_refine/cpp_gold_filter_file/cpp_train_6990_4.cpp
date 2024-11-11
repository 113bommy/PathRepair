#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int main() {
  int n, i, m, j;
  int x = 0;
  vector<int> v;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> a[i][j];
      if (j == 0) x = (x ^ a[i][j]);
    }
    v.push_back(0);
  }
  int flag = x;
  if (x == 0) {
    for (i = 0; i < n && flag == 0; i++) {
      for (j = 1; j < m; j++) {
        if (a[i][0] != a[i][j]) {
          v[i] = j;
          flag = 1;
          break;
        }
      }
    }
  }
  if (flag == 0) {
    cout << "NIE";
  } else {
    cout << "TAK\n";
    for (int i = 0; i < n; i++) {
      cout << v[i] + 1 << " ";
    }
  }
}
