#include <bits/stdc++.h>
using namespace std;
int OO = 2e9;
const double eps = 1e-9;
int mx = -2e9, mn = 2e9;
int main() {
  int n, a;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  for (int i = 0; i < n; ++i)
    if (arr[i] < mn) {
      mn = arr[i];
      a = i + 1;
    }
  sort(arr, arr + n);
  if (n == 1)
    cout << "1/n";
  else {
    if (arr[0] == arr[1])
      cout << "Still Rozdil\n";
    else
      cout << a << endl;
  }
  return 0;
}
