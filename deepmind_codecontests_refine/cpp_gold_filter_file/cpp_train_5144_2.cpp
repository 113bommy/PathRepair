#include <bits/stdc++.h>
using namespace std;
int main() {
  int length, m;
  cin >> length >> m;
  int arr[length], res = 0;
  for (int i = 0; i < length; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + length);
  for (int i = 0; i < m && i < length; i++) {
    if (arr[i] < 0) {
      res += abs(arr[i]);
    }
  }
  cout << res << endl;
  return 0;
}
