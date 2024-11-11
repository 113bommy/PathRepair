#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long arr[3];
    for (long long i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + 3);
    if (arr[1] == arr[2]) {
      cout << "YES" << endl;
      cout << arr[1] << " " << arr[0] << " 1" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
