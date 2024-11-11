#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ans = n + (n - 1);
  ans = arr[0];
  for (int i = 0; i < n - 1; i++) {
    ans += abs(arr[i] - arr[i + 1]);
  }
  cout << ans << endl;
}
