#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    if (arr[0] + arr[1] < arr[n - 1]) {
      cout << "1 2 " << n << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}
