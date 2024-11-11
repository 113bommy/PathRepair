#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (auto& elem : arr) {
    cin >> elem;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (arr[j] == i) {
        cout << j + 1 << " ";
      }
    }
  }
  return 0;
}
