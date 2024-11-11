#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[101][101];
  char c;
  int n;
  cin >> n;
  int con = 0, big_con = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c;
      if (c == 'o') {
        arr[i][j] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int t = arr[i][j + 1] + arr[i][j - 1] + arr[i + 1][j] + arr[i - 1][j];
      if (t % 2 != 0) big_con++;
    }
  }
  if (big_con == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
