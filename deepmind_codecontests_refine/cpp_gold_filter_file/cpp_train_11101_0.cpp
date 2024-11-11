#include <bits/stdc++.h>
using namespace std;
long long al[200][200] = {};
long long ar[200][200] = {};
int main() {
  al[1][0] = 0;
  al[1][1] = 1;
  ar[1][0] = 1;
  al[2][0] = -1;
  al[2][1] = 0;
  al[2][2] = 1;
  ar[2][0] = 0;
  ar[2][1] = 1;
  int n;
  cin >> n;
  for (int i = 3; i < 160; ++i) {
    for (int j = 0; j < 160; ++j) {
      ar[i][j] = al[i - 1][j];
    }
    for (int j = 0; j < 160; ++j) {
      al[i][j + 1] = al[i - 1][j];
    }
    for (int j = 0; j < 160; ++j) {
      al[i][j] += ar[i - 1][j];
    }
    bool hasTwo = false;
    for (int j = 0; j < 160; ++j) {
      if (al[i][j] != 0 && al[i][j] != 1 && al[i][j] != -1) {
        hasTwo = true;
      }
    }
    if (!hasTwo) {
      continue;
    }
    for (int j = 0; j < 160; ++j) {
      al[i][j] -= 2 * ar[i - 1][j];
    }
  }
  cout << n << endl;
  cout << al[n][0];
  for (int i = 1; i <= n; ++i) {
    cout << " " << al[n][i];
  }
  cout << endl;
  cout << n - 1 << endl;
  cout << ar[n][0];
  for (int i = 1; i <= n - 1; ++i) {
    cout << " " << ar[n][i];
  }
  cout << endl;
}
