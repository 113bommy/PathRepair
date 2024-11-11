#include <bits/stdc++.h>
using namespace std;
int n, m;
char arr[105][105];
string s;
void f(int x, int y) {
  int d[105] = {};
  for (int i = 0; i < m; i++) {
    if (i != y) {
      d[arr[x][i] - 'a']++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != x) {
      d[arr[i][y] - 'a']++;
    }
  }
  if (d[arr[x][y] - 'a'] == 0) {
    s += arr[x][y];
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      f(i, j);
    }
  }
  cout << s;
  return 0;
}
