#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[10];
  int i = 0;
  while (n > 0) {
    a[i] = n % 10;
    n = n / 10;
    i++;
  }
  i--;
  int m = i, k;
  for (i = 0; i <= m; i++) {
    if (a[i] != 0) {
      k = i;
      break;
    }
  }
  int flag = 0, j = 0;
  for (i = m; i > (m + k) / 2; i--) {
    if (a[i] != a[k + j]) {
      flag = 1;
      break;
    }
    j++;
  }
  if (flag == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
