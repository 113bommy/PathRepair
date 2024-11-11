#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, v = 2, arr[100][100] = {0}, i = 0;
  cin >> k;
  while (k > 0) {
    if (k < i) {
      i = 0, v++;
    }
    arr[i][v - 1] = 1;
    arr[v - 1][i] = 1;
    k -= i;
    i++;
    if (i >= (v - 1) && k > 0) {
      i = 0;
      v++;
    }
  }
  cout << v << endl;
  for (int j = 0; j < v; j++) {
    for (int m = 0; m < v; m++) {
      cout << arr[j][m];
    }
    cout << endl;
  }
}
