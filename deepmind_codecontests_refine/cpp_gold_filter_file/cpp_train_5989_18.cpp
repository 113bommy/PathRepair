#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char a[n][n];
  int tot = 0;
  for (int i = 0; i < n; i++) {
    int ct = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'C') ct++;
    }
    tot += ((ct * (ct - 1)) / 2);
  }
  for (int i = 0; i < n; i++) {
    int ct = 0;
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 'C') ct++;
    }
    tot += ((ct * (ct - 1)) / 2);
  }
  cout << tot << endl;
}
