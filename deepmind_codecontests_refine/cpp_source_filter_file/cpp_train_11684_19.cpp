#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int arr[n];
    int one = 0;
    int ind = -1;
    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      if (arr[j] % 2 == 0) {
        one = 1;
        ind = j;
      }
    }
    if (one == 1) {
      cout << 1 << endl;
      cout << ind << endl;
    } else {
      if (n >= 2) {
        cout << 2 << endl;
        cout << 1 << " " << 2 << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
