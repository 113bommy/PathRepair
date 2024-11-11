#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j;
  cin >> n;
  int arr, row[n], column[n];
  for (i = 0; i < n; i++) {
    row[i] = 0;
    column[i] = 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> arr;
      row[i] += arr;
      column[j] += arr;
    }
  }
  int cnt = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (row[i] < column[j]) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
