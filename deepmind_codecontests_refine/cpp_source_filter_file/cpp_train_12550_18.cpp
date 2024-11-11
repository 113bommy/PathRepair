#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, i, j = 1;
  cin >> n;
  cin >> c;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (arr[i + 1] - arr[i] <= c)
      j = j + 1;
    else if (arr[i + 1] - arr[i] != c && i != n - 2)
      j = 1;
    else
      j = 0;
  }
  cout << j;
  return 0;
}
