#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n[t];
  int a[400][100];
  for (int i = 0; i < t; i++) {
    cin >> n[i];
    n[i] = n[i] * 2;
    for (int j = 0; j < n[i]; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < t; i++) {
    int num = a[i][0];
    for (int j = 0; j < n[i]; j++) {
      int flag;
      if (j == 0) {
        cout << a[i][j];
      } else {
        flag = 1;
        for (int g = 0; g < j; g++) {
          if (a[i][g] == a[i][j]) {
            flag = 0;
          }
        }
        if (flag == 1) {
          cout << " " << a[i][j];
        }
      }
    }
    cout << endl;
  }
}
