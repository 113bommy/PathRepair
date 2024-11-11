#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, x = 0;
  cin >> n >> h;
  int arr[n];
  for (size_t i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (size_t i = 0; i < n; i++) {
    if (arr[i] >= h) {
      x++;
    }
    x++;
  }
  cout << x;
  return 0;
}
