#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  cout << abs(arr[0] - arr[1]) << " " << abs(arr[0] - arr[n - 1]) << "\n";
  for (int i = 1; i < n; i++) {
    if (abs(arr[i] - arr[i - 1]) <= abs(arr[i] - arr[i + 1]))
      cout << abs(arr[i] - arr[i - 1]) << " ";
    else
      cout << abs(arr[i] - arr[i + 1]) << " ";
    if (abs(arr[i] - arr[n - 1]) >= abs(arr[i] - arr[0]))
      cout << abs(arr[i] - arr[n - 1]) << "\n";
    else
      cout << abs(arr[i] - arr[0]) << "\n";
  }
}
