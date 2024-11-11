#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, l, flag = 0;
  cin >> n;
  char a[n + 1][6];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    flag = 0;
    if (a[i][0] == 'O' && a[i][1] == 'O') {
      a[i][0] = '+';
      a[i][1] = '+';
      flag = 1;
      break;
    }
    if (a[i][3] == 'O' && a[i][4] == 'O' && flag == 0) {
      a[i][3] = '+';
      a[i][4] = '+';
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "NO\n";
  } else
    cout << "YES\n";
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}
