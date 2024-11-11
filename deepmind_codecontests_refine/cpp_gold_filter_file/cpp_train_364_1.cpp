#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int cycinp1(int n, int i, int j) {
  cin >> a[i][j];
  return (j == n - 1) ? 0 : cycinp1(n, i, j + 1);
}
int cycinp2(int n, int i, int j) {
  cycinp1(n, i, 0);
  return (i == n - 1) ? 0 : cycinp2(n, i + 1, 0);
}
int cycf1(int n, int i, int j, int k) {
  a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
  return (k == n - 1) ? 0 : cycf1(n, i, j, k + 1);
}
int cycf2(int n, int i, int j, int k) {
  cycf1(n, i, j, 0);
  return (j == n - 1) ? 0 : cycf2(n, i, j + 1, 0);
}
int cycf3(int n, int i, int j, int k) {
  cycf2(n, i, 0, 0);
  return (i == n - 1) ? 0 : cycf3(n, i + 1, j, k);
}
int res = -1;
int cycm1(int n, int i, int j) {
  res = max(res, a[i][j]);
  return (j == n - 1) ? 0 : cycm1(n, i, j + 1);
}
int cycm2(int n, int i, int j) {
  cycm1(n, i, 0);
  return (i == n - 1) ? 0 : cycm2(n, i + 1, j);
}
int main() {
  int n;
  cin >> n;
  cycinp2(n, 0, 0);
  cycf3(n, 0, 0, 0);
  cycm2(n, 0, 0);
  cout << res;
  return 0;
}
