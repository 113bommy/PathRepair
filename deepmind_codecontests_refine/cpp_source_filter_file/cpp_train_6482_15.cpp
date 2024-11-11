#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    bool has_greater_than_one = false;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      if (arr[i] > 1) {
        has_greater_than_one = true;
      }
    }
    bool first = true;
    for (int i = 0; i < n; i++) {
      if (arr[i] > 1) {
        break;
      }
      first = !first;
    }
    if (!has_greater_than_one) {
      first = !first;
    }
    if (first) {
      cout << "FIRST" << endl;
    } else
      cout << "SECOND" << endl;
  }
  return 0;
}
