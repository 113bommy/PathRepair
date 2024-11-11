#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[100005], n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cout << min(arr[n - 1] - arr[0], arr[n - 2] - arr[1]) << endl;
  return 0;
}
