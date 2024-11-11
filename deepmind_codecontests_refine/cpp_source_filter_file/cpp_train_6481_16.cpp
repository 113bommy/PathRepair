#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int count1 = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] == 1) {
        count1++;
      } else {
        break;
      }
    }
    if (count1 % 2 == 0) {
      cout << "FIRST\n";
    } else {
      cout << "SECOND\n";
    }
  }
  return 0;
}
