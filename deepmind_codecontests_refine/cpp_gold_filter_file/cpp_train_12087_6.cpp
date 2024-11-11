#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n, cnt = 0, cntt = 0;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] == 1) {
      cnt = 1;
    } else if (arr[i] == 0) {
      cntt = 0;
    }
  }
  if (cnt == 1)
    cout << "HARD" << endl;
  else if (cntt == 0)
    cout << "EASY" << endl;
  return 0;
}
