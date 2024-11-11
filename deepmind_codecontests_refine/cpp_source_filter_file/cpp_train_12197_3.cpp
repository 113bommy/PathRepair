#include <bits/stdc++.h>
using namespace std;
char ans[1100][1100];
char a[10] = {"aeiou"};
int main() {
  int k;
  int flag = 0;
  cin >> k;
  for (int i = 5; i <= k; i++) {
    if (k % i == 0 && k / i >= 5) {
      flag = i;
      break;
    }
  }
  if (!flag) {
    cout << "-1" << endl;
    return 0;
  }
  int n = flag;
  int m = k / n;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ans[i][j] = a[(i + j) % 5];
    }
  }
  for (int i = 5; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      ans[i][j] = a[j];
    }
    for (int j = 5; j < m; j++) {
      ans[i][j] = 'm';
    }
  }
  for (int i = 5; i < m; i++) {
    for (int j = 0; j < 5; j++) {
      ans[j][i] = a[j];
    }
    for (int j = 5; j < n; j++) {
      ans[j][i] = 'm';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
  }
  return 0;
}
