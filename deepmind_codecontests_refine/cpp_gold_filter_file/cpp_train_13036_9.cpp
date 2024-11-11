#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int arr[3];
    for (int i = 0; i < 3; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + 3);
    if (arr[2] == 0)
      cout << "0\n";
    else if (arr[0] > 3)
      cout << "7\n";
    else {
      if (arr[0] == 1) {
        if (arr[1] >= 2)
          cout << "4\n";
        else
          cout << "3\n";
      } else if (arr[0] == 2) {
        if (arr[2] > 2)
          cout << "5\n";
        else
          cout << "4\n";
      } else if (arr[0] == 3) {
        cout << "6\n";
      } else {
        if (arr[1] == 0)
          cout << "1\n";
        else if (arr[1] == 1)
          cout << "2\n";
        else
          cout << "3\n";
      }
    }
  }
  return 0;
}
