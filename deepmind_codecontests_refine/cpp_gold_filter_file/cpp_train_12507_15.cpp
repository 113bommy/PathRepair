#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0;
  cin >> n;
  int arr[2 * n];
  for (int i = 0; i < 2 * n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  for (int i = 1; i < 2 * n; i++) {
    if (i % 2 != 0) {
      if (k <= arr[i]) {
        r += 1;
      }
    } else {
      continue;
    }
  }
  cout << r;
  return 0;
}
