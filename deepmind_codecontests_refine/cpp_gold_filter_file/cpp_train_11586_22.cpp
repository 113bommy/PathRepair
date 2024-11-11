#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k, l;
  cin >> n >> m >> k;
  k++;
  int a = 1, b = 0;
  char arr[n][m];
  int ar[33] = {};
  map<char, int> me;
  for (int i = 0; i < n; i++) {
    int x = -1, y = -1, q = 0;
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] != '-' && x != -1) {
        y = j;
      } else if (arr[i][j] != '-') {
        x = j;
      }
    }
    if (y == -1 || arr[i][x] == arr[i][y] || x == -1) q = 1;
    if (q == 0) {
      int v = abs(y - x) - 1, j = 32;
      while (j--) {
        ar[j] += (v % 2);
        v /= 2;
      }
      a = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '-') {
        if (j != 0 && arr[i][j - 1] != '-') me[arr[i][j - 1]]++;
        if (j != m - 1 && arr[i][j + 1] != '-') me[arr[i][j + 1]]++;
      }
    }
  }
  if (!me['G'])
    cout << "Second" << endl;
  else if (!me['R'] && me['G'])
    cout << "First" << endl;
  else {
    if (a == 0) {
      b = 0;
      for (int i = 0; i < 33; i++) {
        b += (ar[i] % (k));
      }
      if (b)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }
  return 0;
}
