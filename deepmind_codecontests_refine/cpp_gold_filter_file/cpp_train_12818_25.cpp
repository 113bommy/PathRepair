#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, count = 0;
  cin >> n >> x >> y;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] <= x) count++;
  }
  if (x > y) {
    cout << n;
  } else {
    if (count % 2 == 0) {
      cout << count / 2;
    } else
      cout << (count / 2) + 1;
  }
}
