#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[2002];
  int brr[2002];
  memset(arr, -1, sizeof arr);
  memset(brr, 0, sizeof brr);
  int a = 1, b = 1, n;
  brr[1] = 1, brr[2] = 1, brr[3] = 2;
  arr[1] = arr[2] = 0;
  n = 2;
  int n1 = 4;
  int f = 0;
  while (brr[n1] <= 1000) {
    brr[n1] = brr[n1 - 1] + brr[n1 - 2];
    arr[brr[n1]] = 0;
    if (brr[n1] > 1000) break;
    ++n1;
  }
  for (int i = 1; i <= t; i++) {
    if (arr[i] == 0)
      cout << "O";
    else
      cout << "o";
  }
}
