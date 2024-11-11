#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n][n];
  int flag = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  int a = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      a += arr[i][j];
    }
    if (a == 0)
      a = 0;
    else
      flag = 0;
  }
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
