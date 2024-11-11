#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<unsigned long long> > arr(n);
  for (int i = 0; i < n; ++i) {
    arr[i] = vector<unsigned long long>(n);
  }
  int zi, zj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 0) {
        zi = i;
        zj = j;
      }
    }
  }
  if (n == 1) {
    cout << 42 << endl;
    return 0;
  }
  int fullI = (zi == 0 ? 1 : 0);
  unsigned long long fullSum = 0;
  for (int j = 0; j < n; ++j) {
    fullSum += arr[fullI][j];
  }
  unsigned long long zeroSum = 0;
  for (int j = 0; j < n; ++j) {
    zeroSum += arr[zi][j];
  }
  if (fullSum <= zeroSum) {
    cout << -1 << endl;
    return 0;
  }
  unsigned long long res = fullSum - zeroSum;
  arr[zi][zj] = res;
  for (int i = 0; i < n; ++i) {
    unsigned long long sh = 0, sv = 0;
    for (int j = 0; j < n; ++j) {
      sh += arr[i][j];
      sv += arr[j][i];
    }
    if (sh != fullSum || sv != fullSum) {
      cout << -1 << endl;
      return 0;
    }
  }
  unsigned long long d1 = 0, d2 = 0;
  for (int i = 0; i < n; ++i) {
    d1 += arr[i][i];
    d2 += arr[n - 1 - i][i];
  }
  if (d1 != fullSum || d2 != fullSum) {
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;
  return 0;
}
