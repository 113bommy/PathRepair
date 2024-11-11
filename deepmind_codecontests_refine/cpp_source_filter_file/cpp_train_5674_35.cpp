#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int i, j, a[m][n], x = 0, z = 1;
  map<int, int> d;
  for (i = 0; i < m; i++) {
    x = 0;
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] > x) {
        x = a[i][j];
        z = j + 1;
      }
    }
    d[z]++;
  }
  x = 0;
  z = 1;
  for (auto i : d) {
    if (i.second > x) {
      x = i.second;
      z = i.first;
    }
  }
  cout << z << endl;
}
