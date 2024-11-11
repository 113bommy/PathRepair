#include <bits/stdc++.h>
using namespace std;
int main() {
  int p, q, n;
  cin >> n;
  int arr[n];
  for (p = 0; p < n; p++) {
    cin >> arr[p];
  }
  for (p = 0; p < n; p++) {
    if (arr[p] == 2) {
      q == 2;
    } else if ((arr[p] % 2) == 0) {
      q = 0;
    } else if ((arr[p] % 2) != 0) {
      q = 1;
    }
    cout << q << "\n";
  }
  return 0;
}
