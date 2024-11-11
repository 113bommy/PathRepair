#include <bits/stdc++.h>
using namespace std;
int arr[50][50];
int n[3];
int main() {
  int x, c;
  cin >> c >> x;
  for (int i = 0; i < c; ++i)
    for (int j = 0; j < x; ++j) cin >> arr[i][j];
  n[0] += arr[0][0];
  n[0] += arr[0][x - 1];
  n[0] += arr[c - 1][0];
  n[0] += arr[c - 1][x - 1];
  for (int j = 1; j < x - 1; ++j) n[1] += arr[0][j] + arr[c - 1][j];
  for (int i = 1; i < c - 1; ++i) n[1] += arr[i][0] + arr[i][x - 1];
  if (n[0])
    cout << "1" << endl;
  else if (n[1])
    cout << "2" << endl;
  else
    cout << "4" << endl;
  return 0;
}
