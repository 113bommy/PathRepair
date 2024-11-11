#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cell;
  cin >> n >> cell;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int x = arr[0] + 1;
  bool possible = 0;
  while (x <= n) {
    if (x == cell) {
      possible = 1;
      cout << "YES";
      break;
    }
    x += arr[x - 1];
  }
  if (possible == 0) {
    cout << "NO";
  }
  return 0;
}
