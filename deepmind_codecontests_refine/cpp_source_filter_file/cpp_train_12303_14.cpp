#include <bits/stdc++.h>
using namespace std;
int n, x;
int a[51][51];
vector<pair<int, int>> v;
int flip = 0;
void dfs(int i, int j, int val, int p) {
  v.push_back({i, j});
  if (p == 4) {
    if ((val ^ a[i][j]) == 0) {
      cout << "? " << v[0].first << " " << v[0].second << " " << i << " " << j
           << endl;
      cin >> x;
      if ((x == 1 && a[i][j] != a[v[0].first][v[0].second]) ||
          (x == 0 && a[i][j] == a[v[0].first][v[0].second]))
        flip = 1;
      if (flip == 1) {
        for (int i = 1; i <= n; i++) {
          int j = 1;
          if (i % 2 != 0) j++;
          for (; j <= n; j += 2) a[i][j] = a[i][j] ^ 1;
        }
      }
      cout << "!" << endl;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
      exit(0);
    }
    v.pop_back();
    return;
  }
  if (i + 1 <= n) {
    dfs(i + 1, j, val ^ a[i][j], p + 1);
  }
  if (j + 1 <= n) {
    dfs(i, j + 1, val ^ a[i][j], p + 1);
  }
  v.pop_back();
}
int main() {
  cin >> n;
  a[1][1] = 1;
  a[1][2] = 1;
  a[2][3] = 0;
  cout << "? 1 1 2 2" << endl;
  cin >> x;
  a[2][2] = x;
  cout << "? 1 2 2 3" << endl;
  cin >> x;
  if (x == 1) a[2][3] = 1;
  cout << "? 2 1 2 3" << endl;
  cin >> x;
  if (x == 1)
    a[2][1] = a[2][3];
  else
    a[2][1] = a[2][3] ^ 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j <= n - 2) {
        cout << "? " << i << " " << j << " " << i << " " << j + 2 << endl;
        cin >> x;
        if (x == 1)
          a[i][j + 2] = a[i][j];
        else
          a[i][j + 2] = (a[i][j] ^ 1);
      }
      if (j <= 2 && i <= n - 2) {
        cout << "? " << i << " " << j << " " << i + 2 << " " << j << endl;
        cin >> x;
        if (x == 1)
          a[i + 2][j] = a[i][j];
        else
          a[i + 2][j] = (a[i][j] ^ 1);
      }
    }
  }
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= n; j += 2) {
      dfs(i, j, 0, 1);
    }
  }
}
