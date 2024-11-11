#include <bits/stdc++.h>
using namespace std;
int n, i, j, k;
int a[1001][1001];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 1) k++;
      } else if (i % 2 == 1) {
        if (j % 2 == 0) k++;
      }
    }
  }
  cout << k << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i % 2 == 0) {
        if (j % 2 == 0)
          cout << "C";
        else
          cout << ".";
      } else if (i % 2 == 1) {
        if (j % 2 == 1)
          cout << "C";
        else
          cout << ".";
      }
    }
    cout << endl;
  }
}
