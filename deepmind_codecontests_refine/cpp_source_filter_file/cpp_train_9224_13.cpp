#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[100][100];
  int n, i, j, flag = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    j = i - 1;
    while (j >= 0) {
      if (strcmp(a[i], a[j]) == 0) {
        flag = 1;
        cout << "YES" << endl;
        break;
      }
      j--;
    }
    if (flag == 1) {
      flag = 0;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
