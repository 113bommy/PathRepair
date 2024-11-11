#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ct = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      int ans = 0;
      for (int k = 0; k < n; k++) {
        cnt += a[i][k];
        ans += a[k][j];
      }
      if (cnt > ans) ct++;
    }
  }
  cout << ct;
  return 0;
}
