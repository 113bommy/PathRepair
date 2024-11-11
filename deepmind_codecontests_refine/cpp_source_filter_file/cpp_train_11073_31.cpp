#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  reverse(arr, arr + n);
  if (n == 1)
    cout << -1 << "\n";
  else {
    for (auto u : arr) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
