#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (arr[n - 1] >= arr[0] + arr[1]) {
      cout << "1 2 " << n << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}
