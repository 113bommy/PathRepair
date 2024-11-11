#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], i, min = 10000, index;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] < min) {
      index = i + 1;
      min = arr[i];
    }
  }
  if (n == 1 || (n == 2 && arr[0] == arr[1]))
    cout << "-1";
  else
    cout << "1" << endl << index;
  return 0;
}
