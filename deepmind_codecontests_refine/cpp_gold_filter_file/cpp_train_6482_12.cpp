#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n + 5];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] == 1) {
        ans = 1 - ans;
      } else {
        break;
      }
    }
    if (ans == 1) {
      cout << "First" << endl;
    } else {
      cout << "Second" << endl;
    }
  }
  return 0;
}
