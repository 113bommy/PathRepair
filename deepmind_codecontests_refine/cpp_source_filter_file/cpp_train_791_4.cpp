#include <bits/stdc++.h>
using namespace std;
int a[4][7];
map<int, int> mp;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 6; j++) {
      cin >> a[i][j];
      mp[a[i][j]] = 1;
    }
  }
  if (n == 2) {
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        mp[a[1][i] * 10 + a[2][j]] = 1;
        mp[a[2][j] * 10 + a[1][j]] = 1;
      }
    }
  } else if (n == 3) {
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        mp[a[1][i] * 10 + a[2][j]] = 1;
        mp[a[2][j] * 10 + a[1][i]] = 1;
      }
    }
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        mp[a[1][i] * 10 + a[3][j]] = 1;
        mp[a[3][j] * 10 + a[1][i]] = 1;
      }
    }
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        mp[a[3][i] * 10 + a[2][j]] = 1;
        mp[a[2][j] * 10 + a[3][i]] = 1;
      }
    }
    for (int i = 1; i <= 6; i++) {
      for (int j = 1; j <= 6; j++) {
        for (int k = 1; k <= 6; k++) {
          mp[a[1][i] * 100 + a[2][j] * 10 + a[3][k]] = 1;
          mp[a[1][i] * 100 + a[3][k] * 10 + a[2][j]] = 1;
          mp[a[2][j] * 100 + a[1][i] * 10 + a[3][k]] = 1;
          mp[a[2][j] * 100 + a[3][k] * 10 + a[1][i]] = 1;
          mp[a[3][k] * 100 + a[1][i] * 10 + a[2][j]] = 1;
          mp[a[3][k] * 100 + a[2][j] * 10 + a[1][i]] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= 1000; i++) {
    if (!mp[i]) return cout << i - 1, 0;
  }
}
