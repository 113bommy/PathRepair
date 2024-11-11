#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  for (int a = 0; a < n; a++) {
    cin >> arr[a];
  }
  long long max = arr[n - 1];
  arr[n - 1] = 0;
  for (int a = n - 2; a >= 0; a--) {
    if (max < arr[a]) {
      max = arr[a];
      arr[a] = 0;
    } else {
      arr[a] = max + 1 - arr[a];
    }
  }
  for (int a = 0; a < n; a++) {
    cout << arr[a] << " ";
  }
}
