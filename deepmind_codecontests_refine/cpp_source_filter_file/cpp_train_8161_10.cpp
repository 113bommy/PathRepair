#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100][100];
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    a[i][i] = k;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
