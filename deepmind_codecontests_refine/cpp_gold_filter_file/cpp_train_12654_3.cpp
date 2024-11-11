#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<long long> > a(n, vector<long long>(n));
  long long sumx = 0, sumy = 0;
  int X, Y;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        X = i;
        Y = j;
      }
      sum += a[i][j];
    }
    if (find(a[i].begin(), a[i].end(), 0) != a[i].end())
      sumx = sum;
    else if (sumy == 0)
      sumy = sum;
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (sumy <= sumx) {
    cout << -1;
    return 0;
  }
  a[X][Y] = sumy - sumx;
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) sum += a[i][j];
    if (sum != sumy) {
      cout << -1;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    long long sum = 0;
    for (int j = 0; j < n; j++) sum += a[j][i];
    if (sum != sumy) {
      cout << -1;
      return 0;
    }
  }
  {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i][i];
    }
    if (sum != sumy) {
      cout << -1;
      return 0;
    }
  }
  {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i][n - 1 - i];
    }
    if (sum != sumy) {
      cout << -1;
      return 0;
    }
  }
  cout << a[X][Y];
  return 0;
}
