#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int arr[3];
  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }
  long long int n;
  cin >> n;
  sort(arr, arr + 3);
  long long int d1 = arr[2] - arr[0];
  long long int d2 = arr[2] - arr[1];
  long long int k = n;
  k = k - d1;
  k = k - d2;
  if (k < 0)
    cout << "NO" << endl;
  else {
    if (k % 3 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
